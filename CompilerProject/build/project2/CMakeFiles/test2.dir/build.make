# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build

# Include any dependencies generated for this target.
include project2/CMakeFiles/test2.dir/depend.make

# Include the progress variables for this target.
include project2/CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include project2/CMakeFiles/test2.dir/flags.make

project2/CMakeFiles/test2.dir/run2.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/run2.cc.o: ../project2/run2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project2/CMakeFiles/test2.dir/run2.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/run2.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/run2.cc

project2/CMakeFiles/test2.dir/run2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/run2.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/run2.cc > CMakeFiles/test2.dir/run2.cc.i

project2/CMakeFiles/test2.dir/run2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/run2.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/run2.cc -o CMakeFiles/test2.dir/run2.cc.s

project2/CMakeFiles/test2.dir/run2.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/run2.cc.o.requires

project2/CMakeFiles/test2.dir/run2.cc.o.provides: project2/CMakeFiles/test2.dir/run2.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/run2.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/run2.cc.o.provides

project2/CMakeFiles/test2.dir/run2.cc.o.provides.build: project2/CMakeFiles/test2.dir/run2.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o: ../project2/kernels/grad_case1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case1.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case1.cc

project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case1.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case1.cc > CMakeFiles/test2.dir/kernels/grad_case1.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case1.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case1.cc -o CMakeFiles/test2.dir/kernels/grad_case1.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o: ../project2/kernels/grad_case10.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case10.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case10.cc

project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case10.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case10.cc > CMakeFiles/test2.dir/kernels/grad_case10.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case10.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case10.cc -o CMakeFiles/test2.dir/kernels/grad_case10.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o: ../project2/kernels/grad_case2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case2.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case2.cc

project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case2.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case2.cc > CMakeFiles/test2.dir/kernels/grad_case2.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case2.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case2.cc -o CMakeFiles/test2.dir/kernels/grad_case2.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o: ../project2/kernels/grad_case3.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case3.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case3.cc

project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case3.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case3.cc > CMakeFiles/test2.dir/kernels/grad_case3.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case3.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case3.cc -o CMakeFiles/test2.dir/kernels/grad_case3.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o: ../project2/kernels/grad_case4.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case4.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case4.cc

project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case4.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case4.cc > CMakeFiles/test2.dir/kernels/grad_case4.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case4.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case4.cc -o CMakeFiles/test2.dir/kernels/grad_case4.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o: ../project2/kernels/grad_case5.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case5.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case5.cc

project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case5.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case5.cc > CMakeFiles/test2.dir/kernels/grad_case5.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case5.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case5.cc -o CMakeFiles/test2.dir/kernels/grad_case5.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o: ../project2/kernels/grad_case6.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case6.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case6.cc

project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case6.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case6.cc > CMakeFiles/test2.dir/kernels/grad_case6.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case6.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case6.cc -o CMakeFiles/test2.dir/kernels/grad_case6.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o: ../project2/kernels/grad_case7.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case7.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case7.cc

project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case7.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case7.cc > CMakeFiles/test2.dir/kernels/grad_case7.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case7.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case7.cc -o CMakeFiles/test2.dir/kernels/grad_case7.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o: ../project2/kernels/grad_case8.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case8.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case8.cc

project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case8.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case8.cc > CMakeFiles/test2.dir/kernels/grad_case8.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case8.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case8.cc -o CMakeFiles/test2.dir/kernels/grad_case8.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o


project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o: project2/CMakeFiles/test2.dir/flags.make
project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o: ../project2/kernels/grad_case9.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/kernels/grad_case9.cc.o -c /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case9.cc

project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/kernels/grad_case9.cc.i"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case9.cc > CMakeFiles/test2.dir/kernels/grad_case9.cc.i

project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/kernels/grad_case9.cc.s"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2/kernels/grad_case9.cc -o CMakeFiles/test2.dir/kernels/grad_case9.cc.s

project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.requires:

.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.requires

project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.provides: project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.requires
	$(MAKE) -f project2/CMakeFiles/test2.dir/build.make project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.provides.build
.PHONY : project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.provides

project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.provides.build: project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o


# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/run2.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case1.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case10.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case2.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case3.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case4.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case5.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case6.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case7.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case8.cc.o" \
"CMakeFiles/test2.dir/kernels/grad_case9.cc.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

project2/test2: project2/CMakeFiles/test2.dir/run2.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o
project2/test2: project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o
project2/test2: project2/CMakeFiles/test2.dir/build.make
project2/test2: project2/CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable test2"
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project2/CMakeFiles/test2.dir/build: project2/test2

.PHONY : project2/CMakeFiles/test2.dir/build

project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/run2.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case1.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case10.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case2.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case3.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case4.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case5.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case6.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case7.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case8.cc.o.requires
project2/CMakeFiles/test2.dir/requires: project2/CMakeFiles/test2.dir/kernels/grad_case9.cc.o.requires

.PHONY : project2/CMakeFiles/test2.dir/requires

project2/CMakeFiles/test2.dir/clean:
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 && $(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : project2/CMakeFiles/test2.dir/clean

project2/CMakeFiles/test2.dir/depend:
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1 /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/project2 /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2 /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/project2/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project2/CMakeFiles/test2.dir/depend

