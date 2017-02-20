cmake_minimum_required(VERSION 3.6)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TString.h TString.cpp)
add_executable(lab1 ${SOURCE_FILES})