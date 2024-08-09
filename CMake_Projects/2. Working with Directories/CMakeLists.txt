cmake_minimum_required(VERSION 2.8.7)
project(directory_test)
 
#Bring the headers, such as Student.h into the project
include_directories(Include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
#Uses the SOURCES variable, rather than an explicit reference to each source file, in order to build the testStudent executable program.
add_executable(ComplexNumbers ${SOURCES})
