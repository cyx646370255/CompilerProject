# CMake generated Testfile for 
# Source directory: /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner
# Build directory: /home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/jsoncpp-build/src/jsontestrunner
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(jsoncpp_readerwriter "/usr/bin/python3" "-B" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/runjsontests.py" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/bin/jsontestrunner_exe" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter PROPERTIES  WORKING_DIRECTORY "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/data")
add_test(jsoncpp_readerwriter_json_checker "/usr/bin/python3" "-B" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/runjsontests.py" "--with-json-checker" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/build/bin/jsontestrunner_exe" "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter_json_checker PROPERTIES  WORKING_DIRECTORY "/home/cyx/Desktop/project2-new/CompilerProject-2020Spring-Part1/3rdparty/jsoncpp/src/jsontestrunner/../../test/data")
