cmake_minimum_required(VERSION 3.6)
project(CC4652_Hash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LDE.hpp No.hpp Hash.hpp)
add_executable(CC4652_Hash ${SOURCE_FILES})