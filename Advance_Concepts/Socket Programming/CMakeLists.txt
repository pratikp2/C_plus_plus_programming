cmake_minimum_required(VERSION 2.8.7)
project(Socket_Program_Server)

#Specifies the build type on single-configuration generators Possible values are Debug,Release,empty,RelWithDebInfo and MinSizeRel
set(CMAKE_BUILD_TYPE Release)
 
#Bring the headers, such as Student.h into the project
include_directories(inc)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
#Generate the Dynamic/Shared library from the sources
add_library(testStudent SHARED ${SOURCES})
 
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)
