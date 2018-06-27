#Sets the minimum version of CMake for this project
cmake_minimum_required(VERSION 2.8.7)

#Sets the project name
project (hello)

#First argument is name of the output binary after compailation
#Second argument is name of the input source file from which to build the executable. 
add_executable(HelloWorld hello.cpp)
