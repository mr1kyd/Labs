cmake_minimum_required(VERSION 3.6)
project(Lab_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h)
add_executable(Lab_1 ${SOURCE_FILES})