/*
 * MIT License
 * 
 * Copyright (c) 2020 Size Zheng

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef BOOST_IR_H
#define BOOST_IR_H

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include "type.h"
#include "arith.h"
#include "debug.h"

namespace Boost {

namespace Internal {

/**
 * This class is inspired by Halide IntrusivePtr
 * The difference is that we use std::shared_ptr
 */
template <typename T>
class Ref {

 protected:
    std::shared_ptr<T> ptr = nullptr;

 public:
    Ref() {}

    Ref(Ref<T> &other) : ptr(other.ptr) {}

    Ref(Ref<T> &&other) : ptr(std::move(other.ptr)) {}

    /**
     * allow constructing from sub-class
     */ 
    template<typename U, typename std::enable_if<std::is_base_of<T, U>::value>::type* = nullptr>
    Ref(Ref<U> &other) : ptr(other.real_ptr()) {}

    template<typename U, typename std::enable_if<std::is_base_of<T, U>::value>::type* = nullptr>
    Ref(Ref<U> &&other) : ptr(std::move(other.real_ptr())) {}

    /**
     * allow constructing from shared_ptr of sub-class
     */ 
    template<typename U, typename std::enable_if<std::is_base_of<T, U>::value>::type* = nullptr>
    Ref(std::shared_ptr<U> _ptr) : ptr(_ptr) {}

    bool defined() { return ptr != nullptr; }

    T *get() const { return ptr.get(); }

    /**
     * have to expose inner shared_ptr, required by constructor
     */ 
    void set_ptr(std::shared_ptr<T> other) {
        this->ptr = other;
    }

    std::shared_ptr<T> real_ptr() const {
        return this->ptr;
    }

    T &operator*() const { return *ptr; }

    T *operator->() const { return ptr.operator->(); }

    Ref<T> &operator=(Ref<T> &b) {
        this->ptr = b.ptr;
        return *this;
    }

    Ref<T> &operator=(Ref<T> &&b) {
        swap(this->ptr, b.ptr);
        return *this;
    }

    bool operator<(Ref<T> &b) const {
        /* Don't directly compare shared_ptr, for C++20 removes operator< */
        return this->get() < b.get();
    }
};

/**
 * different type of IRNodes
 */ 
enum class IRNodeType : short {
    // Groups
    Kernel,
    // Stmts
    LoopNest,
    IfThenElse,
    If,
    Move,
    // Exprs
    Unary,
    Binary,
    Select,
    Compare,
    Call,
    Var,
    Cast,
    Ramp,
    Index,
    IntImm,
    UIntImm,
    FloatImm,
    StringImm,
    Dom
};


/**
 * forward declaration
 */
class IRVisitor;
class IRMutator;
class Expr;
class Stmt;
class Group;


/**
 * this is the base class of all IR nodes
 */ 
class IRNode {
 public:
    IRNode(const IRNodeType _type) : _node_type(_type) {}

    IRNodeType node_type() const {
        return this->_node_type;
    }

    /**
     * for IRVisitor
     */ 
    virtual void visit_node(IRVisitor *visitor) const = 0;

 private:
    /**
     * indicate the concrete type of this IR node
     */ 
    IRNodeType _node_type;
};


/**
 * base node of expression
 */ 
class ExprNode : public IRNode {
 private:
    Type type_;
 public:
    ExprNode(Type _type, const IRNodeType node_type) : IRNode(node_type), type_(_type) {} 

    virtual ~ExprNode() = default;

    virtual Expr mutate_expr(IRMutator *mutator) const = 0;

    Type type() const {
        return type_;
    }
};


/**
 * base node of statement
 */ 
class StmtNode : public IRNode {
 private:

 public:
    StmtNode(IRNodeType _type) : IRNode(_type) {}

    virtual ~StmtNode() = default;

    virtual Stmt mutate_stmt(IRMutator *mutator) const = 0;
};


/**
 * base node of group
 */ 
class GroupNode : public IRNode {
 private:

 public:
    GroupNode(IRNodeType _type) : IRNode(_type) {}

    virtual ~GroupNode() = default;

    virtual Group mutate_group(IRMutator *mutator) const = 0;
};


/**
 * inherited from Halide
 */ 
class IntImm : public ExprNode, public std::enable_shared_from_this<IntImm> {
 private:
    int64_t value_;
 public:
    IntImm(Type _type, const int64_t _value) : ExprNode(_type, IRNodeType::IntImm), value_(_value)  {}

    /**
     * May need consider bits
     */
    int64_t value() const {
        return value_;
    }

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Ref<const IntImm> make(Type t, const int64_t _value) {
        return std::make_shared<const IntImm>(t, _value);
    }

    static const IRNodeType node_type_ = IRNodeType::IntImm;
};


/**
 * inherited from Halide
 */ 
class UIntImm : public ExprNode, public std::enable_shared_from_this<UIntImm> {
 private:
    uint64_t value_;
 public:
    UIntImm(Type _type, const uint64_t _value) : ExprNode(_type, IRNodeType::UIntImm), value_(_value) {}

    /**
     * May need consider bits
     */ 
    uint64_t value() const {
        return value_;
    }

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Ref<const UIntImm> make(Type t, const uint64_t _value) {
        return std::make_shared<const UIntImm>(t, _value);
    }

    static const IRNodeType node_type_ = IRNodeType::UIntImm;
};


/**
 * inherited from Halide
 */ 
class FloatImm : public ExprNode, public std::enable_shared_from_this<FloatImm> {
 private:
    double value_;
 public:
    FloatImm(Type _type, const double _value) : ExprNode(_type, IRNodeType::FloatImm), value_(_value) {}

    /**
     * May need consider bits
     */ 
    double value() const {
        return value_;
    }

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Ref<const FloatImm> make(Type t, const double _value) {
        return std::make_shared<const FloatImm>(t, _value);
    }

    static const IRNodeType node_type_ = IRNodeType::FloatImm;
};


/**
 * inherited from Halide
 */ 
class StringImm : public ExprNode, public std::enable_shared_from_this<StringImm> {
 private:
    std::string value_;
 public:
    StringImm(Type _type, const std::string _value) :
        ExprNode(_type, IRNodeType::StringImm), value_(_value) {}

    std::string value() const {
        return value_;
    }

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Ref<const StringImm> make(Type t, const std::string _value) {
        return std::make_shared<const StringImm>(t, _value);
    }

    static const IRNodeType node_type_ = IRNodeType::StringImm;
};


/**
 * a reference to expression
 */ 
class Expr : public Ref<const ExprNode> {
 public:
    Expr() : Ref<const ExprNode>() {}
    
    Expr(const Expr &other) : Ref<const ExprNode>(other.real_ptr()) {}

    Expr(const Expr &&other) : Ref<const ExprNode>(other.real_ptr()) {}

    template<typename U,
                typename std::enable_if<std::is_base_of<ExprNode, U>::value>::type* = nullptr>
    Expr(Ref<const U> &other) : Ref<const ExprNode>(other) {}

    template<typename U,
                typename std::enable_if<std::is_base_of<ExprNode, U>::value>::type* = nullptr>
    Expr(Ref<const U> &&other) : Ref<const ExprNode>(std::move(other)) {}

    template<typename U,
                typename std::enable_if<std::is_base_of<ExprNode, U>::value>::type* = nullptr>
    Expr(std::shared_ptr<const U> _ptr) : Ref<const ExprNode>(_ptr) {}

    /**
     * convenient constructors
     */ 
    explicit Expr(bool value) :
        Ref<const ExprNode>(UIntImm::make(Type::uint_scalar(1), static_cast<uint64_t>(value))) {}

    explicit Expr(uint8_t value) :
        Ref<const ExprNode>(UIntImm::make(Type::uint_scalar(8), static_cast<uint64_t>(value))) {}

    explicit Expr(uint16_t value) :
        Ref<const ExprNode>(UIntImm::make(Type::uint_scalar(16), static_cast<uint64_t>(value))) {}

    explicit Expr(uint32_t value) :
        Ref<const ExprNode>(UIntImm::make(Type::uint_scalar(32), static_cast<uint64_t>(value))) {}

    explicit Expr(uint64_t value) :
        Ref<const ExprNode>(UIntImm::make(Type::uint_scalar(64), value)) {}

    explicit Expr(int8_t value) :
        Ref<const ExprNode>(IntImm::make(Type::int_scalar(8), static_cast<int64_t>(value))) {}

    explicit Expr(int16_t value) :
        Ref<const ExprNode>(IntImm::make(Type::int_scalar(16), static_cast<int64_t>(value))) {}

    Expr(int value) :
        Ref<const ExprNode>(IntImm::make(Type::int_scalar(32), static_cast<int64_t>(value))) {}

    explicit Expr(int64_t value) :
        Ref<const ExprNode>(IntImm::make(Type::int_scalar(64), value)) {}

    explicit Expr(float value) :
        Ref<const ExprNode>(FloatImm::make(Type::float_scalar(32), static_cast<double>(value))) {}

    Expr(double value) :
        Ref<const ExprNode>(FloatImm::make(Type::float_scalar(64), value)) {}

    Expr &operator=(const Expr &other) {
        this->set_ptr(other.real_ptr());
        return *this;
    }
    IRNodeType node_type() const {
        return this->get()->node_type();
    }

    Type type() const {
        return this->get()->type();
    }

    void visit_expr(IRVisitor *visitor) const {
        return this->get()->visit_node(visitor);
    }

    Expr mutate_expr(IRMutator *mutator) const {
        return this->get()->mutate_expr(mutator);
    }

    /**
     * cast to other type of reference
     */ 
    template <typename T>
    std::shared_ptr<const T> as() const {
        if (this->node_type() == T::node_type_) {
            return std::static_pointer_cast<const T>(this->real_ptr());
        }
        return nullptr;
    }
};


/**
 * a reference to statement
 */ 
class Stmt : public Ref<const StmtNode> {
 public:
    Stmt() : Ref<const StmtNode>() {}

    Stmt(const Stmt &other) : Ref<const StmtNode>(other.real_ptr()) {}

    Stmt(const Stmt &&other) : Ref<const StmtNode>(other.real_ptr()) {}

    template<typename U, typename std::enable_if<std::is_base_of<StmtNode, U>::value>::type* = nullptr>
    Stmt(Ref<const U> &other) : Ref<const StmtNode>(other) {}

    template<typename U, typename std::enable_if<std::is_base_of<StmtNode, U>::value>::type* = nullptr>
    Stmt(Ref<const U> &&other) : Ref<const StmtNode>(std::move(other)) {}

    template<typename U, typename std::enable_if<std::is_base_of<StmtNode, U>::value>::type* = nullptr>
    Stmt(std::shared_ptr<const U> _ptr) : Ref<const StmtNode>(_ptr) {}

    Stmt(std::shared_ptr<const StmtNode> _ptr) : Ref<const StmtNode>(_ptr) {}

    Stmt &operator=(const Stmt &other) {
        this->set_ptr(other.real_ptr());
        return *this;
    }

    IRNodeType node_type() const {
        return this->get()->node_type();
    }

    void visit_stmt(IRVisitor *visitor) const {
        return this->get()->visit_node(visitor);
    }

    Stmt mutate_stmt(IRMutator *mutator) const {
        return this->get()->mutate_stmt(mutator);
    }

    /**
     * cast to other type of reference
     */ 
    template <typename T>
    std::shared_ptr<const T> as() const {
        if (this->node_type() == T::node_type_) {
            return std::static_pointer_cast<const T>(this->real_ptr());
        }
        return nullptr;
    }
};


/**
 * a reference to group
 */ 
class Group : public Ref<const GroupNode> {
 public:
    Group() : Ref<const GroupNode>() {}

    Group(const Group &other) : Ref<const GroupNode>(other.real_ptr()) {}

    Group(const Group &&other) : Ref<const GroupNode>(other.real_ptr()) {}

    template<typename U, typename std::enable_if<std::is_base_of<GroupNode, U>::value>::type* = nullptr>
    Group(Ref<const U> &other) : Ref<const GroupNode>(other) {}

    template<typename U, typename std::enable_if<std::is_base_of<GroupNode, U>::value>::type* = nullptr>
    Group(Ref<const U> &&other) : Ref<const GroupNode>(std::move(other)) {}

    template<typename U, typename std::enable_if<std::is_base_of<GroupNode, U>::value>::type* = nullptr>
    Group(std::shared_ptr<const U> _ptr) : Ref<const GroupNode>(_ptr) {}

    Group(std::shared_ptr<const GroupNode> _ptr) : Ref<const GroupNode>(_ptr) {}

    Group &operator=(const Group &other) {
        this->set_ptr(other.real_ptr());
        return *this;
    }

    IRNodeType node_type() const {
        return this->get()->node_type();
    }

    void visit_group(IRVisitor *visitor) const {
        return this->get()->visit_node(visitor);
    }

    Group mutate_group(IRMutator *mutator) const {
        return this->get()->mutate_group(mutator);
    }

    /**
     * cast to other type of reference
     */ 
    template <typename T>
    std::shared_ptr<const T> as() const {
        if (this->node_type() == T::node_type_) {
            return std::static_pointer_cast<const T>(this->real_ptr());
        }
        return nullptr;
    }
};


enum class UnaryOpType : uint8_t {
    Neg,    /* negate */
    Not     /* logic not */
};


/**
 * unary operation
 */ 
class Unary : public ExprNode, public std::enable_shared_from_this<Unary> {
 public:
    UnaryOpType op_type;
    Expr a;

    Unary(Type _type, UnaryOpType _op_type, Expr _a) : ExprNode(_type, IRNodeType::Unary),
        op_type(_op_type), a(_a) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, UnaryOpType _op_type, Expr _a) {
        return std::make_shared<const Unary>(t, _op_type, _a);
    }

    static const IRNodeType node_type_ = IRNodeType::Unary;
};


enum class BinaryOpType : uint8_t {
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    And,
    Or,
};


/**
 * binary operation
 */ 
class Binary : public ExprNode, public std::enable_shared_from_this<Binary> {
 public:
    BinaryOpType op_type;
    Expr a, b;
    bool bracket; 

    Binary(Type _type, BinaryOpType _op_type, Expr _a, Expr _b,bool _bracket) : ExprNode(_type, IRNodeType::Binary),
        op_type(_op_type), a(_a), b(_b) ,bracket(_bracket){}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, BinaryOpType _op_type, Expr _a, Expr _b,bool _bracket=false) {
        return std::make_shared<const Binary>(t, _op_type, _a, _b,_bracket);
    }

    static const IRNodeType node_type_ = IRNodeType::Binary;
};


enum class CompareOpType : uint8_t {
    LT,
    LE,
    EQ,
    NE,
    GE,
    GT
};


/**
 * compare op <, <=, =, !=, >=, >
 */ 
class Compare : public ExprNode, public std::enable_shared_from_this<Compare> {
 public:
    CompareOpType op_type;
    Expr a, b;

    Compare(Type _type, CompareOpType _op_type, Expr _a, Expr _b) : ExprNode(_type, IRNodeType::Compare),
        op_type(_op_type), a(_a), b(_b) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, CompareOpType _op_type, Expr _a, Expr _b) {
        return std::make_shared<const Compare>(t, _op_type, _a, _b);
    }

    static const IRNodeType node_type_ = IRNodeType::Compare;
};


/**
 * select op: cond? true_value : false_value
 */ 
class Select : public ExprNode, public std::enable_shared_from_this<Select> {
 public:
    Expr cond;
    Expr true_value, false_value;

    Select(Type _type, Expr _cond, Expr _true_value, Expr _false_value) : ExprNode(_type, IRNodeType::Select),
        cond(_cond), true_value(_true_value), false_value(_false_value) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, Expr _cond, Expr _true_value, Expr _false_value) {
        return std::make_shared<const Select>(t, _cond, _true_value, _false_value);
    }

    static const IRNodeType node_type_ = IRNodeType::Select;
};


enum class CallType : uint8_t {
    Pure,
    SideEffect
};


/**
 * call op, used for function call
 */ 
class Call : public ExprNode, public std::enable_shared_from_this<Call> {
 public:
    std::vector<Expr> args;
    std::string func_name;
    CallType call_type;

    Call(Type _type, const std::vector<Expr> &_args, const std::string &_func_name, CallType _call_type) : ExprNode(_type, IRNodeType::Call),
        args(_args), func_name(_func_name), call_type(_call_type) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Expr make(Type t, const std::vector<Expr> &_args, const std::string &_func_name, CallType _call_type) {
        return std::make_shared<const Call>(t, _args, _func_name, _call_type);
    }

    static const IRNodeType node_type_ = IRNodeType::Call;
};


/**
 * cast op, used for type cast
 */ 
class Cast : public ExprNode, public std::enable_shared_from_this<Cast> {
 public:
    Type new_type;
    Expr val;

    Cast(Type _type, Type _new_type, Expr _val) : ExprNode(_type, IRNodeType::Cast),
        new_type(_new_type), val(_val) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, Type _new_type, Expr _val) {
        return std::make_shared<const Cast>(t, _new_type, _val);
    }

    static const IRNodeType node_type_ = IRNodeType::Cast;
};


/**
 * ramp, used for vectorization
 * - broadcast: when stride is 0
 */ 
class Ramp : public ExprNode, public std::enable_shared_from_this<Ramp> {
 public:
    Expr base;
    uint16_t stride;
    uint16_t lanes;

    Ramp(Type _type, Expr _base, uint16_t _stride, uint16_t _lanes) : ExprNode(_type, IRNodeType::Ramp),
        base(_base), stride(_stride), lanes(_lanes) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, Expr _base, uint16_t _stride, uint16_t _lanes) {
        return std::make_shared<const Ramp>(t, _base, _stride, _lanes);
    }

    static const IRNodeType node_type_ = IRNodeType::Ramp;
};


/**
 * TODO: do we need shuffle?
 */ 


/**
 * variable index expression, such as A[i, j]
 * - scalar: when shape is {1}
 */ 
class Var : public ExprNode, public std::enable_shared_from_this<Var> {
 public:
    std::string name;
    std::vector<Expr> args;
    // TODO: this may need to be removed to other class
    std::vector<size_t> shape;
    Var(Type _type, const std::string &_name, const std::vector<Expr> &_args,
        const std::vector<size_t> &_shape) : ExprNode(_type, IRNodeType::Var),
        name(_name), args(_args), shape(_shape) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, const std::string &_name, const std::vector<Expr> &_args,
        const std::vector<size_t> &_shape) {
        return std::make_shared<const Var>(t, _name, _args, _shape);
    }

    static const IRNodeType node_type_ = IRNodeType::Var;
};


/**
 * iteration domain, for now it's a simple [begin, begin+extent)
 */ 
class Dom : public ExprNode, public std::enable_shared_from_this<Dom> {
 public:
    Expr begin;
    Expr extent;

    Dom(Type _type, Expr _begin, Expr _extent) : ExprNode(_type, IRNodeType::Dom), begin(_begin), extent(_extent) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Expr make(Type t, Expr _begin, Expr _extent) {
        return std::make_shared<const Dom>(t, _begin, _extent);
    }

    static const IRNodeType node_type_ = IRNodeType::Dom;
};


enum class IndexType : uint8_t {
    Spatial,
    Reduce,
    Thread,
    Block,
    Vectorized,
    Unrolled
};


/**
 * iteration index
 */ 
class Index : public ExprNode, public std::enable_shared_from_this<Index> {
 public:
    std::string name;
    Expr dom;
    IndexType index_type;

    Index(Type _type, const std::string &_name, Expr _dom, IndexType _index_type) :
        ExprNode(_type, IRNodeType::Index), name(_name), dom(_dom), index_type(_index_type) {}

    Expr mutate_expr(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Expr make(Type t, const std::string &_name, Expr _dom, IndexType _index_type) {
        return std::make_shared<const Index>(t, _name, _dom, _index_type);
    }

    static const IRNodeType node_type_ = IRNodeType::Index;
};


/**
 * loop nest
 * - block: if index_list is empty, it means a block of statements
 */ 
class LoopNest : public StmtNode, public std::enable_shared_from_this<LoopNest> {
 public:
    std::vector<Expr> index_list;
    std::vector<Stmt> body_list;

    LoopNest(const std::vector<Expr> &_index_list, const std::vector<Stmt> &_body_list) :
        StmtNode(IRNodeType::LoopNest), index_list(_index_list), body_list(_body_list) {}

    Stmt mutate_stmt(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;

    static Stmt make(const std::vector<Expr> &_index_list, const std::vector<Stmt> &_body_list) {
        return std::make_shared<const LoopNest>(_index_list, _body_list);
    }

    static const IRNodeType node_type_ = IRNodeType::LoopNest;
};


/**
 * branch statement
 */ 
class IfThenElse : public StmtNode, public std::enable_shared_from_this<IfThenElse> {
 public:
    Expr cond;
    Stmt true_case;
    Stmt false_case;

    IfThenElse(Expr _cond, Stmt _true_case, Stmt _false_case) :
        StmtNode(IRNodeType::IfThenElse), cond(_cond), true_case(_true_case), false_case(_false_case) {}

    Stmt mutate_stmt(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Stmt make(Expr _cond, Stmt _true_case, Stmt _false_case) {
        return std::make_shared<const IfThenElse>(_cond, _true_case, _false_case);
    }

    static const IRNodeType node_type_ = IRNodeType::IfThenElse;
};

class If : public StmtNode, public std::enable_shared_from_this<If> {
 public:
    Expr cond;
    Stmt true_case;

    If(Expr _cond, Stmt _true_case) :
        StmtNode(IRNodeType::If), cond(_cond), true_case(_true_case) {}

    Stmt mutate_stmt(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Stmt make(Expr _cond, Stmt _true_case) {
        return std::make_shared<const If>(_cond, _true_case);
    }

    static const IRNodeType node_type_ = IRNodeType::If;
};



enum class MoveType : uint8_t {
    DeviceToHost,
    HostToDevice,
    MemToShared,
    SharedToMem,
    MemToLocal,
    LocalToMem,
    SharedToLocal,
    LocalToShared,
    SharedToShared,
    MemToMem,
    LocalToLocal
};


/**
 * assign statement: load and store are put together
 * - evaluate: when dst is nullptr
 */ 
class Move : public StmtNode, public std::enable_shared_from_this<Move> {
 public:
    Expr dst;
    Expr src;
    // TODO: is this necessary?
    MoveType move_type;

    Move(Expr _dst, Expr _src, MoveType _move_type) :
        StmtNode(IRNodeType::Move), dst(_dst), src(_src), move_type(_move_type) {}

    Stmt mutate_stmt(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Stmt make(Expr _dst, Expr _src, MoveType _move_type) {
        return std::make_shared<const Move>(_dst, _src, _move_type);
    }

    static const IRNodeType node_type_ = IRNodeType::Move;
};


enum class KernelType : uint8_t {
    CPU,
    GPU
};


class Kernel : public GroupNode, public std::enable_shared_from_this<Kernel> {
 public:
    std::string name;
    std::vector<Expr> inputs;
    std::vector<Expr> outputs;
    std::vector<Stmt> stmt_list;
    KernelType kernel_type;

    Kernel(const std::string &_name, const std::vector<Expr> &_inputs,
        const std::vector<Expr> &_outputs, const std::vector<Stmt> &_stmt_list, KernelType _kernel_type) :
        GroupNode(IRNodeType::Kernel), name(_name), inputs(_inputs), outputs(_outputs),
        stmt_list(_stmt_list), kernel_type(_kernel_type) {}

    Group mutate_group(IRMutator *mutator) const;
    void visit_node(IRVisitor *visitor) const;
    
    static Group make(const std::string &_name, const std::vector<Expr> &_inputs,
        const std::vector<Expr> &_outputs, const std::vector<Stmt> &_stmt_list, KernelType _kernel_type) {
        return std::make_shared<const Kernel>(_name, _inputs, _outputs, _stmt_list, _kernel_type);
    }

    static const IRNodeType node_type_ = IRNodeType::Kernel;
};

enum TokenType {
    id,
    Int,
    Float,
    symbol
};
class Token{
public:
    std::string symbol;
    TokenType type;
    int ival;
    float fval;
    Token(){}
    Token(std::string s,TokenType t){
        symbol = s;
        type = t;
        ival = -1;
        fval = -1;
        if(t == TokenType::Int || t == TokenType::Float){
            bool isInt=true;
            for(int i = 0; i < s.size();i++)
            if(s[i] == '.'){
                isInt=false;
                break;
            }
            if(isInt) ival = getInt(s);
            else fval = getFloat(s);
        }
    }
    int getInt(std::string s){
    return std::atoi(s.c_str());
    }
    float getFloat(std::string s){
        return std::atof(s.c_str());
    }
};
class Parse{
    public:
        Token curToken; 
        int index = 0; //for input
        int curStmt = 0,curIndex=0,curDom=0; //for index_expr 
        std::string name,type;
        std::vector<Token>input;
        std::vector<std::string>in,out;
        std::vector<Expr>index_expr[10];  //存放每一条语句用到的index变量
        std::vector<Expr> var_alist[10];  //存放每条语句中Var的alist
        std::vector<int> var_clist[10];   //存放每条语句中Var的clist
        std::map<std::string,Expr>inputs,outputs;  //分别存放输入和输出的变量  
        Type index_type,data_type;
        Parse(std::string name1,std::string type1,std::vector<std::string> in1,
        std::vector<std::string> out1,std::vector<Token>x){
            input.assign(x.begin(),x.end());
            in.assign(in1.begin(),in1.end());
            out.assign(out1.begin(),out1.end());
            name = name1;
            type = type1;
            in = in;
            out = out;
            index_type = Type::int_scalar(32);
            if(type=="float")
            data_type = Type::float_scalar(32);
            else if(type=="int")
            data_type = Type::int_scalar(32);
        }
        void insertVarList(Expr expr){
            std::string id = expr.as<Var>()->name;
            for(int i = 0; i < in.size();i++)
            if(id == in[i]){
                if(inputs.count(id)==0)
                inputs[id]=expr;
            }
            for(int i = 0; i < out.size();i++)
            if(id == out[i]){
                if(outputs.count(id)==0)
                outputs[id]=expr;
            }
        }
        void inserIndex(Expr& expr){
            std::string index_name = expr.as<Index>()->name;
            std::string tmp_name;
            for(int i = 0;i < index_expr[curStmt].size();i++){
                tmp_name = index_expr[curStmt][i].as<Index>()->name;
                if(index_name == tmp_name){
                    int64_t e1 = index_expr[curStmt][i].as<Index>()->dom.as<Dom>()->extent.as<IntImm>()->value();
                    int64_t e2 = expr.as<Index>()->dom.as<Dom>()->extent.as<IntImm>()->value();
                    if(e2<e1)
                    index_expr[curStmt][i] = expr;
                    return;
                }
            }
            index_expr[curStmt].push_back(expr);
        }
        void getNextToken(){
            curToken=input[index];
            index++;
        }
        Group P() { // P      ->   S P1
            std::vector<Stmt>stmts;
            std::vector<Expr> Input,Output;
            S(stmts);
            P1(stmts);
            for(int i = 0; i < in.size();i++)
            Input.push_back(inputs[in[i]]);
            for(int i = 0; i < out.size();i++)
            Output.push_back(outputs[out[i]]);
            Group kernel = Kernel::make(name, Input, Output, stmts, KernelType::CPU);
            return kernel;
        }
        Stmt buildIfStmt(Stmt stmt){
            int size = var_alist[curStmt].size();
            if(size == 0)return stmt;
            Expr lastcond = Compare::make(data_type, CompareOpType::LT, var_alist[curStmt][0], var_clist[curStmt][0]);
            for(int i = 1; i < size; i++){
                Expr cond = Compare::make(data_type, CompareOpType::LT, var_alist[curStmt][i], var_clist[curStmt][i]);
                lastcond = Binary::make(data_type, BinaryOpType::And, lastcond, cond);
            }
            Stmt ifStmt = If::make(lastcond,stmt);
            return ifStmt;
        }
        void S(std::vector<Stmt>& stmts) { // S      ->   LHS = RHS ;
            Expr l = LHS();
            getNextToken(); // for =
            Expr r = RHS();
            getNextToken(); // for ;
            Stmt main_stmt = Move::make(l,r,MoveType::MemToMem);
            Stmt ifStmt = buildIfStmt(main_stmt);
            Stmt loop_nest = LoopNest::make(index_expr[curStmt], {ifStmt});
            stmts.push_back(loop_nest);
            curStmt++;
        }
        void P1(std::vector<Stmt>& stmts){ // P1     ->   S P1 | null
            if(index < input.size()){
                S(stmts);
                P1(stmts);
            }
        }
        Expr LHS(){ // LHS    ->   TRef
            return TRef();
        }
        Expr RHS(bool bracket=false){ // RHS    ->   TERM RHS1
            Expr expr_A=TERM(bracket);
            RHS1(expr_A,bracket);
            return expr_A;
        }
        void RHS1(Expr &expr_A,bool bracket=false){ // RHS1   ->   + TERM RHS1 | - TERM RHS1 | null
            if(input[index].symbol=="+"){
                getNextToken();
                Expr expr_B = TERM(bracket);
                expr_A = Binary::make(data_type, BinaryOpType::Add, expr_A, expr_B,bracket);
                RHS1(expr_A,bracket);
            }
            else if(input[index].symbol=="-"){
                 getNextToken();
                Expr expr_B = TERM(bracket);
                expr_A = Binary::make(data_type, BinaryOpType::Sub, expr_A, expr_B,bracket);
                RHS1(expr_A,bracket);
            }            
        }
        Expr TERM(bool bracket=false){ // TERM   ->   FACTOR TERM1
            Expr expr_A = FACTOR();
            TERM1(expr_A,bracket);
            return expr_A;
        }
        void TERM1(Expr &expr_A,bool bracket=false){ //TERM1  ->   * FACTOR TERM1 | / FACTOR TERM1 | % FACTOR TERM1 | // FACTOR TERM1 | null
            
            if(input[index].symbol=="*"){
                getNextToken();
                Expr expr_B = FACTOR();
                expr_A = Binary::make(data_type, BinaryOpType::Mul, expr_A, expr_B,bracket);
                TERM1(expr_A,bracket);
            }
            else if(input[index].symbol=="%"){
                 getNextToken();
                 Expr expr_B = FACTOR();
                 expr_A = Binary::make(data_type, BinaryOpType::Mod, expr_A, expr_B,bracket);
                 TERM1(expr_A,bracket);
            }
            else if(input[index].symbol=="/"){
                 getNextToken();
                 Expr expr_B = FACTOR();
                 expr_A = Binary::make(data_type, BinaryOpType::Div, expr_A, expr_B,bracket);
                 TERM1(expr_A,bracket);
            }    
            else if(input[index].symbol=="//"){
                 getNextToken();
                 Expr expr_B = FACTOR();
                 expr_A = Binary::make(data_type, BinaryOpType::Div, expr_A, expr_B,bracket);
                 TERM1(expr_A,bracket);
            }      
        }
        Expr FACTOR(){ //FACTOR ->   (RHS) | Const | TRef
            if(input[index].symbol == "("){ // for (RHS)
                getNextToken();
                //bracket=true;
                Expr i = RHS(true);
                //bracket=false;
                getNextToken(); // for )
                return i;
            }
            else if(input[index].type == TokenType::Int || input[index].type == TokenType::Float) {//for const
                return Const();
            }
            else{
                return TRef();
            }
        }
        Expr TRef(){ // TRef   ->   Id < CList > SRef
            std::string varName;
            std::vector<Expr>clist,alist;
            std::vector<size_t>shape;
            //处理id
            getNextToken();
            varName = curToken.symbol;
            getNextToken(); // for <
            CList(clist);
            for(int i = 0; i<clist.size();i++)
            shape.push_back(clist[i].as<IntImm>()->value());
            getNextToken(); // for >
            SRef(alist,shape);
            Expr var = Var::make(data_type, varName, alist, shape);
            insertVarList(var);
            for(int i = 0; i < alist.size(); i++)
            if(alist[i].node_type()==IRNodeType::Binary){
            var_alist[curStmt].push_back(alist[i]);
            var_clist[curStmt].push_back(shape[i]);
            }
            // todo
            return var;

        }
        void CList(std::vector<Expr>&clist){ // CList  ->   IntV CList1
            getNextToken();
            Expr num = IntImm::make(index_type,curToken.ival);
            clist.push_back(num);
            CList1(clist);
        }
        void CList1(std::vector<Expr>&clist){ // CList1 ->   ,IntV Clist1 | null
            if(input[index].symbol==","){
                getNextToken(); // for ,
                getNextToken();
                Expr num = IntImm::make(index_type,curToken.ival);
                clist.push_back(num);
                CList1(clist);
            }
        }
        void SRef(std::vector<Expr>&alist,std::vector<size_t>&shape){ // SRef   ->   [ AList ] | null
            if(input[index].symbol=="["){
                getNextToken(); // for [
                AList(alist,shape);
                getNextToken(); // for ]
            }
        }
        void AList(std::vector<Expr>&alist,std::vector<size_t>&shape){ // AList  ->   IdExpr AList1
            curIndex=0;
            curDom = shape[curIndex];
            Expr idExpr = IdExpr();
            alist.push_back(idExpr);
            AList1(alist,shape);
        }
        void AList1(std::vector<Expr>&alist,std::vector<size_t>&shape){ // AList1 ->   ,IdExpr AList1 | null
            if(input[index].symbol==","){
                    getNextToken(); // for ,
                    curIndex++;
                    curDom = shape[curIndex];
                    Expr idExpr = IdExpr();
                    alist.push_back(idExpr);
                    AList1(alist,shape);
                }
        }
        Expr IdExpr(bool bracket=false){ // IdExpr ->   TERM IdExpr1
            Expr expr_A=ITERM(bracket);
            IdExpr1(expr_A,bracket);
            return expr_A;
        }
        void IdExpr1(Expr &expr_A,bool bracket=false){ // IdExpr1->   + TERM IdExpr1 | - TERM IdExpr1 | null
            Expr expr_A1 = Expr(expr_A);
            if(input[index].symbol=="+"){
                getNextToken();
                Expr expr_B = ITERM(bracket);
                expr_A = Binary::make(index_type, BinaryOpType::Add, expr_A1, expr_B,bracket);
                IdExpr1(expr_A,bracket);
            }
            else if(input[index].symbol=="-"){
                getNextToken();
                Expr expr_B = ITERM(bracket);
                expr_A = Binary::make(index_type, BinaryOpType::Sub, expr_A1, expr_B,bracket);
                IdExpr1(expr_A,bracket);
            }
        }
        Expr ITERM(bool bracket=false){ // TERM   ->   FACTOR TERM1
            Expr expr_A = IFACTOR();
            ITERM1(expr_A,bracket);
            return expr_A;
        }
        void ITERM1(Expr &expr_A,bool bracket=false){ // * FACTOR TERM1 | % FACTOR TERM1 | // FACTOR TERM1 | null
            Expr expr_A1 = Expr(expr_A);
            if(input[index].symbol=="*"){
                 getNextToken();
                 Expr expr_B = IFACTOR();
                 expr_A = Binary::make(index_type, BinaryOpType::Mul, expr_A1, expr_B,bracket);
                 ITERM1(expr_A,bracket);
            }
            else if(input[index].symbol=="%"){
                 getNextToken();
                 Expr expr_B = IFACTOR();
                 expr_A = Binary::make(index_type, BinaryOpType::Mod, expr_A1, expr_B,bracket);
                 ITERM1(expr_A,bracket);
            }
            else if(input[index].symbol=="//"){
                 getNextToken();
                 Expr expr_B = IFACTOR();
                 expr_A = Binary::make(index_type, BinaryOpType::Div, expr_A1, expr_B,bracket);
                 ITERM1(expr_A,bracket);
            }
        }
        Expr IFACTOR(){ // FACTOR ->   (IdExpr) | Id | IntV
            if(input[index].symbol=="("){
                getNextToken(); // for (
                Expr i = IdExpr(true);
                getNextToken(); // for )
                return i;
            }
            else if(input[index].type==TokenType::id){
                getNextToken();
                Expr tmp_dom = Dom::make(index_type, 0, curDom);
                Expr i = Index::make(index_type, curToken.symbol, tmp_dom, IndexType::Spatial);
                inserIndex(i);
                return i;
            }
            else if(input[index].type==TokenType::Int){
                getNextToken();
                return IntImm::make(index_type,curToken.ival);
            }
        }
        Expr Const(){ // Const  ->   FloatV | IntV
            getNextToken();
            if(curToken.type == TokenType::Int){
                return IntImm::make(data_type,curToken.ival);
            }
            else if(curToken.type == TokenType::Float){
                return FloatImm::make(data_type,curToken.fval);
            }
        }
};


}  // namespace Internal

}  // namespace Boost


#endif  // BOOST_IR_H