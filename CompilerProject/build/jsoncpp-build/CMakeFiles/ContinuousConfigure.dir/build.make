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

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/progress.make

jsoncpp-build/CMakeFiles/ContinuousConfigure:
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/jsoncpp-build && /usr/bin/ctest -D ContinuousConfigure

ContinuousConfigure: jsoncpp-build/CMakeFiles/ContinuousConfigure
ContinuousConfigure: jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/build.make

.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure

.PHONY : jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/build

jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/jsoncpp-build && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousConfigure.dir/cmake_clean.cmake
.PHONY : jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/clean

jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/depend:
	cd /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1 /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/jsoncpp-build /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : jsoncpp-build/CMakeFiles/ContinuousConfigure.dir/depend

