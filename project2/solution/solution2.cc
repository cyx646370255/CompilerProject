//#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

#include "IR.h"
#include "parse.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"

using namespace std;

#define Vector vector
#define String string


namespace Project1 {
	const string inpath = "./cases/", outpath = "./kernels/grad_";
	vector<string> infiles, in, out;
	vector<string> outfiles;
	string name = "", type = "";
	void getFiles() {
		for(int i = 1; i <= 10; i++) {
			char s[99];
			sprintf(s, "case%d.new.json", i);
			infiles.push_back(s);
		}
		infiles.push_back("example.new.json");
		
		for(int i = 1; i <= 10; i++) {
			char s[99];
			sprintf(s, "case%d.cc", i);
			outfiles.push_back(s);
		}
		outfiles.push_back("example.cc");
	}
	
	bool isLetter(char c){
		return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
	}
	bool isNumber(char c){
		return c>='0'&&c<='9';
	}
	void parse(string s,vector<Boost::Internal::Token>&kernel){
		int pos1,pos2;
		string tmp="";
		for(unsigned int i = 0; i < s.size(); i++)
		if(s[i]!=' ') tmp+=s[i];
		if((pos1 = tmp.find("\"name\""))!=-1){
		    pos1 = tmp.find_last_of("\"");
		    pos2 = tmp.find_last_of("\"", pos1 - 1);
		    name = tmp.substr(pos2+1,pos1-pos2-1);
		}
		else if((pos1 = tmp.find("\"ins\""))!=-1){
		    for(unsigned int i = 6; i<tmp.size(); i++){
		        if(tmp[i]=='"'){
		            unsigned int j = i+1;
		            while(tmp[j]!='"')j++;
		            in.push_back(tmp.substr(i+1,j-i-1));
		            i = j;
		        }
		    }
		}
		else if((pos1 = tmp.find("\"outs\""))!=-1){
		    for(unsigned int i = 7; i<tmp.size(); i++){
		        if(tmp[i]=='"'){
		            unsigned int j = i+1;
		            while(tmp[j]!='"')j++;
		            out.push_back(tmp.substr(i+1,j-i-1));
		            i = j;
		        }
		    }
		}
		else if((pos1 = tmp.find("\"data_type\""))!=-1){
		    pos1 = tmp.find_last_of("\"");
		    pos2 = tmp.find_last_of("\"", pos1 - 1);
		    type = tmp.substr(pos2+1,pos1-pos2-1);
		}
		else if((pos1 = tmp.find("\"kernel\""))!=-1){
		    pos1 = tmp.find_last_of("\"");
		    pos2 = tmp.find_last_of("\"", pos1 - 1);
		    tmp = tmp.substr(pos2+1,pos1-pos2-1);
		    for(int i = 0; i < tmp.size();i++){
		        if(isNumber(tmp[i])){
		            string num="";
		            bool isInt = true;
		            Boost::Internal::TokenType type;
		            for(;isNumber(tmp[i])||tmp[i]=='.';i++){
		                if(tmp[i] == '.')isInt=false;
		                num+=tmp[i];
		            }
		            if(isInt)
		            type = Boost::Internal::TokenType::Int;
		            else
		            type = Boost::Internal::TokenType::Float;
		            Boost::Internal::Token t = Boost::Internal::Token(num,type);
		            kernel.push_back(t);
		            i--;
		        }
		        else if(isLetter(tmp[i])){
		            string num="";
		            for(;isLetter(tmp[i]);i++)
		            num+=tmp[i];
		            kernel.push_back(Boost::Internal::Token(num,Boost::Internal::TokenType::id));
		            i--;
		        }
		        else if(tmp[i]=='/'){
		            if(tmp[i+1]=='/')
		            {
		                kernel.push_back(Boost::Internal::Token("//",Boost::Internal::TokenType::symbol));
		                i++;
		            }
		            else kernel.push_back(Boost::Internal::Token("/",Boost::Internal::TokenType::symbol));
		        }
		        else{
		            string s = "";
		            s+=tmp[i];
		            kernel.push_back(Boost::Internal::Token(s,Boost::Internal::TokenType::symbol));
		        }
		    }
		}
	}
}

void solveProject1() {
	using namespace Project1;
	getFiles();
	
    for(int i = 0; i < infiles.size();i++){
    	int cas = i + 1;
    	if(cas == 6 || cas == 8 || cas == 10) continue;
    	cerr << "solving 1." << i+1 << endl;
        vector<Boost::Internal::Token>kernel1;
        string file = inpath+infiles[i];
        ifstream infile(file); 
        if(!infile)continue;
        string line; 
        while(getline(infile,line)){
            parse(line,kernel1);
        } 
        Boost::Internal::Parse p = Boost::Internal::Parse(name,type,in,out,kernel1);
        Boost::Internal::Group kernel = p.P();
        Boost::Internal::IRVisitor visitor;
        kernel.visit_group(&visitor);

        // mutator
        Boost::Internal::IRMutator mutator;
        kernel = mutator.mutate(kernel);

        // printer
        Boost::Internal::IRPrinter printer;
        std::string code = printer.print(kernel);

        infile.close(); 
        //std::cout << code;
        //std::cout << code;
        std::ofstream ofile(outpath+outfiles[i], std::ios::out);
        ofile << code;
        ofile.close();
        name = "",type="";
        in.clear();out.clear();
    }
}

namespace Project2 {
	const String inpath = "./cases/", outpath = "./cases/";
	vector<string> infiles, outfiles;
	void getFiles() {
		for(int i = 1; i <= 10; i++) {
			char s[99];
			sprintf(s, "case%d.json", i);
			infiles.push_back(s);
		}
		infiles.push_back("example.json");
		
		for(int i = 1; i <= 10; i++) {
			char s[99];
			sprintf(s, "case%d.new.json", i);
			outfiles.push_back(s);
		}
		outfiles.push_back("example.new.json");
	}
	
	String trim(String s) {
		while(s.size() && *s.begin() == ' ') s.erase(s.begin());
		while(s.size() && (*--s.end() == ' ' || *--s.end() == ';')) s.erase(--s.end());
		return s;
	}
	
	Vector<String> split(String s, char c) {
		cerr << "\nsplit(" + s + ")" << endl;
		unsigned n;
		Vector<String> res;
		while((n = s.find(c)) < s.size()) {
			res.push_back(trim(s.substr(0, n)));
			cout << n << ": " << trim(s.substr(0, n - 1)) << endl;
			s = s.substr(n + 1, s.size() - (n+1));
		}
		if(trim(s).size()) {
			res.push_back(trim(s));
	//		cout << trim(s) << endl;
		}
		return res;
	}
	
	bool isLetter(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }
	
	String name(String s) {
		unsigned n = s.find('<');
		if(n == String::npos) {
			return s;
		}
		return s.substr(0, n-1);
	}
	
	String rename(String s, String pre) {
		unsigned n = s.find('<');
		if(n == String::npos) {
			return s;
		}
		return pre + s.substr(n, s.size() - n);
	}
	
	enum NodeType{
		e1, e2, e3
	};
	struct Node;
	struct Visitor {
		string virtual visit(Node *n, string argu);
	};
	struct Node {
		NodeType type;
		String str;
	//	String name;
		vector<Node> sons;
		bool d;
		bool isNumber() {
			return str.find('<') == String::npos;
		}
		bool has0() {
			if(type == NodeType::e3) {
				return str == "0";
			} else if(type == NodeType::e2) {
				for(unsigned i = 0; i < sons.size(); i++) {
					if(sons[i].has0()) return 1;
				}
				return 0;
			}
		}
		void collectIns(set<string> &s) {
			if(type == NodeType::e3) {
				if(!isNumber()) s.insert((d ? "d" : "") + name());
			} else if(type == NodeType::e2) {
				for(unsigned i = 0; i < sons.size(); i++) {
					sons[i].collectIns(s);
				}
			} else if(type == NodeType::e1) {
				for(unsigned i = 1; i < sons.size(); i++) {
					if(!sons[i].has0()) sons[i].collectIns(s);
				}
			}
		}
		String name() {
			unsigned n = str.find('<');
			if(n == String::npos) {
				return str;
			}
			return str.substr(0, n);
		}
		void calcStr() {
			//cerr << "arrive calcStr." << endl;
			if(type == NodeType::e3) return;
			str = "";
			if(type == NodeType::e2) {
				for(unsigned i = 0; i < sons.size(); i++) {
					if(i > 0) str += " * ";
					if(sons[i].d && sons[i].str != "0") str += "d";
					str += sons[i].str;
				}
			} else if(type == NodeType::e1) {
	//			str = sons[0].str + " = ";
				int fir = 0;
				for(unsigned i = 0; i < sons.size(); i++) {
					if(sons[i].has0()) continue;
					if(fir++) str += " + ";
					str += sons[i].str;
				}
			}
		}
		Node() {}
		Node(NodeType type) : type(type) {
			d = 0;
		}
		Node(NodeType type, String inputString, int d = 0) : type(type), str(inputString), d(d) {
			if(type == NodeType::e1) {
				Vector<String> sp1 = split(inputString, '=');
				Vector<String> sp2 = split(sp1[1], '+');
				////cerr << sp1[0] << endl << sp1[1] << endl;
				sons.push_back(Node(NodeType::e2, sp1[0]));
				for(unsigned i = 0; i < sp2.size(); i++) {
					sons.push_back(Node(NodeType::e2, sp2[i]));
				}
			} else if(type == NodeType::e2) {
				Vector<String> sp = split(inputString, '*');
				for(unsigned i = 0; i < sp.size(); i++) {
				    ////cerr << sp[i] << endl;
					sons.push_back(Node(NodeType::e3, sp[i]));
				}
			} else if(type == NodeType::e3) {
	//			str = inputString;
			}
		}
		string accept(Visitor *visitor, string argu) {
			return visitor->visit(this, argu);
		}
		
		Node getD(string lhs, string tar) {
			Node res;
			////cerr << "arrive 1." << endl;
			if(type == NodeType::e3) {
				////cerr << "arrive e3." << endl;
				res = *this;
				res.d = 1;
				if(name() == lhs || name() == tar) {
					
				} else {
					res.str = "0";
				}
				//cerr << "arrive e3_end." << endl;
			} else if(type == NodeType::e2) {
				
				//cerr << "arrive e2." << endl;
				res = Node(NodeType::e1);
				for(unsigned i = 0; i < sons.size(); i++) {
					Node node(NodeType::e2);
					for(unsigned j = 0; j < sons.size(); j++) {
						if(i == j) {
							node.sons.push_back(sons[j].getD(lhs, tar));
						} else {
							node.sons.push_back(sons[j]);
						}
					}
					node.calcStr();
					res.sons.push_back(node);
				}
				res.calcStr();
				//cerr << "arrive e2_end." << endl;
			} else if(type == NodeType::e1) {
				//cerr << "arrive e1." << endl;
				res = *this;
				res.sons.clear();
				for(unsigned i = 0; i < sons.size(); i++) {
					Node e = sons[i].getD(lhs, tar);
					res.sons.insert(res.sons.end(), e.sons.begin(), e.sons.end());
				}
				res.calcStr();
			}
			return res;
		}
		
		void get_full(string lhs, string tar, string &lhs_full, string &tar_full) {
			if(type == NodeType::e3) {
				if(name() == lhs) {
					lhs_full = str;
					return;
				} else if(name() == tar) {
					tar_full = str;
				}
			} else {
				for(unsigned i = 0; i < sons.size(); i++) {
					sons[i].get_full(lhs, tar, lhs_full, tar_full);
				}
			}
		}
		
		void swaplt(string lhs, string tar, string lhs_full, string tar_full) {
			if(type == NodeType::e3) {
				if(d) { 
					if(name() == lhs) {
						str = tar_full;
					} else if(name() == tar) {
						str = lhs_full;
					}
				}
			} else {
				for(unsigned i = 0; i < sons.size(); i++) {
					sons[i].swaplt(lhs, tar, lhs_full, tar_full);
				}
				calcStr();
			}
		}
	};
	
	struct Visitor1 : public Visitor {
		string visit(Node *n, string argu) {
			//cerr << n->str << " " << n->sons.size() << endl;
			for(unsigned i = 0; i < n->sons.size(); i++) {
				n->sons[i].accept(this, argu);
			}
			return "";
		}
	};
	
	struct getD_Visitor : public Visitor {
		string lhs, tar;
		getD_Visitor(string lhs, string tar) : lhs(lhs), tar(tar) {
			
		}
		
		string visit(Node *n, string argu) {
			for(unsigned i = 0; i < n->sons.size(); i++) {
				n->sons[i].accept(this, argu);
				
			}
			return "";
		}
	};
	
	string Visitor::visit(Node *n, string argu) {
		//cerr << "???" << endl;
		return n->accept(this, argu);
	}
	
	string package(string s) {
		unsigned n = s.find('+');
		s[n] = '=';
		return s + ";";
	}
	
	string getInside(string s, char lc, char rc) {
		int l = s.find(lc), r = s.find_last_of(rc);
		return s.substr(l + 1, r - l - 1);
	}

}

void solveProject2() {
	using namespace Project2; 
	getFiles();
	
	for (int i = 0; i < infiles.size(); i++) {
	
		int cas = i + 1;
		if(cas == 6 || cas == 8 || cas == 10) continue;
		
        string file = inpath + infiles[i];
        cerr << file << endl;
        ifstream infile(file);
        FILE *fdebug = fopen((file + ".debug").c_str(), "w");
        if (!infile)
            continue;
        string line;
        string lines[10];
        int line_cnt = 0;
        string kernel, lhs;
        vector<string> tars, ins;
        while (getline(infile, line)) {
        	lines[++line_cnt] = line;
        	cerr << line_cnt << ": " << line << endl;
        	if(line_cnt == 1 || line_cnt == 8) continue;
        	
			int pos = line.find(':');
			line = line.substr(pos + 1);
        	if(line_cnt == 3) { // ins
        		fprintf(fdebug, "line3: %s\n", line.c_str());
        		string is = getInside(line, '[', ']');
        		cerr << is << endl;
        		vector<string> iss = split(is, ',');
        		cerr << "!!!" << endl;
        		fprintf(fdebug, "ins: ");
        		for(unsigned i = 0; i < iss.size(); i++) {
        			fprintf(fdebug, "+%s ", iss[i].c_str());
        			ins.push_back(getInside(iss[i], '\"', '\"'));
        			
        			fprintf(fdebug, "-%s ", getInside(iss[i], '\"', '\"').c_str());
        		}
        		fprintf(fdebug, "\n");
			} else if(line_cnt == 4) { //outs
        		lhs = getInside(line, '\"', '\"');
			} else if(line_cnt == 6) { // kernel
        		kernel = getInside(line, '\"', '\"');
        	} else if(line_cnt == 7) { // grad_to
        		string ds = getInside(line, '[', ']');
        		vector<string> dss = split(ds, ',');
        		for(unsigned i = 0; i < dss.size(); i++) {
        			tars.push_back(getInside(dss[i], '\"', '\"'));
        		}
        	}
        }
        Node p = Node(NodeType::e1, kernel);
        String tar, lhs_full, tar_full;
        Vector<String> kernels;
        set<string> ins2;
        for(unsigned i = 0; i < tars.size(); i++) {
        	tar = tars[i];
			Node np = p.getD(lhs, tar);
			np.get_full(lhs, tar, lhs_full, tar_full);
			np.swaplt(lhs, tar, lhs_full, tar_full);
			kernels.push_back(package(np.str));
			fprintf(fdebug, "%s\n", package(np.str).c_str());
        	np.collectIns(ins2);
		}

        infile.close();
        std::ofstream ofile(outpath + outfiles[i], std::ios::out);
        string output;
        for(int i = 1; i <= 8; i++) {
        	if(i == 3) { // ins
        		
        		output += "    \"ins\": [";
        		int fir = 0;
        		for(set<string>::iterator it = ins2.begin(); it != ins2.end(); ++it) {
        			if(fir++) output += ", ";
        			output += "\"" + *it + "\"";
        		}
        		output += "],\n";
        	} else if(i == 4) { //outs
        		output += "    \"outs\": [";
        		for(unsigned i = 0; i < tars.size(); i++) {
        			if(i > 0) output += ",";
        			output += "\"d" + tars[i] + "\"";
        		}
        		output += "],\n";
        	} else if(i == 6) { // kernel
        		output += "    \"kernel\": \"";
        		for(unsigned i = 0; i < kernels.size(); i++) {
        			output += kernels[i];
        		}
        		output += "\"\n";
        	} else if(i == 7) { // grad_to
        		
        	} else {
        		output += lines[i] + "\n";
        	}
        }
        ofile << output;
        ofile.close();
        fclose(fdebug);
    }
	
	/*
	const int N = 8;
	String str[N] = {"C<4, 16>[i, j] = A<4, 16>[i, j] * B<4, 16>[i, j] + 1.0;", 
	"B<4, 16>[i, j] = A<4, 16>[i, j] * A<4, 16>[i, j] + 1.0;",
	"C<4, 16>[i, j] = A<4, 16>[i, k] * B<16, 16>[k, j];",
	"A<16, 32>[i, j] = B<16, 32>[i, k] * C<32, 32>[k, j];",
	"A<16, 32>[i, j] = B<16, 32>[i, k] * C<32, 32>[k, j];",
	"A<16, 32>[i, j] =  B<16, 32, 4>[i, k, l] * C<32, 32>[k, j] * D<4, 32>[l, j];",
	"B<16, 32>[i, j] = A<32, 16>[j, i];",
	"B<4, 6>[i, j] = A<4>[i]"};
	
	
	String ans[N] = {"dA<4, 16>[i, j] = dC<4, 16>[i, j] * B<4, 16>[i, j];",
	"dA<4, 16>[i, j] = dB<4, 16>[i, j] * A<4, 16>[i, j] + A<4, 16>[i, j] * dB<4, 16>[i, j];",
	"dA<4, 16>[i, k] = dC<4, 16>[i, j] * B<16, 16>[k, j];",
	"dB<16, 32>[i, k] = dA<16, 32>[i, j] * C<32, 32>[k, j];",
	"dC<32, 32>[k, j] = dA<16, 32>[i, j] * B<16, 32>[i, k];",
	"dB<16, 32, 4>[i, k, l] = dA<16, 32>[i, j] * C<32, 32>[k, j] * D<4, 32>[l, j];",
	"dA<32, 16>[j, i] = dB<16, 32>[i, j];",
	"dA<4>[i] = dB<4, 6>[i, j];",
	};
	
	String ls[N], tars[N];
	
	for(int i = 0; i < N; i++) {
		ls[i] = str[i].substr(0, 1);
		tars[i] = ans[i].substr(1, 1);
		Node p = Node(NodeType::e1, str[i]);
		
		String lhs, tar, lhs_full, tar_full;
		lhs = ls[i], tar = tars[i];
		Node np = p.getD(lhs, tar);
		np.get_full(lhs, tar, lhs_full, tar_full);
		np.swaplt(lhs, tar, lhs_full, tar_full);
		cout << package(np.str) << endl << ans[i] << endl << endl;
	}
	*/
}


int main() {
	cerr << "--main0--" << endl;
	solveProject2();
	cerr << "--main1--" << endl;
	solveProject1();
	cerr << "--main2--" << endl;


	return 0;
}
