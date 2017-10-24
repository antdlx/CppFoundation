cmake_minimum_required(VERSION 3.6)
project(CppFoundation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES linklist/linklist.h linklist/linklist.cpp linklist/linklist_main.cpp)
add_executable(CppFoundation ${SOURCE_FILES})