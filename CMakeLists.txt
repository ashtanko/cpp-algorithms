cmake_minimum_required(VERSION 3.9)
project(
        cpp_algorithms
        LANGUAGES CXX
        VERSION 1.0.0
        DESCRIPTION "Algorithms implemented in C++."
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_algorithms main.cpp)

add_subdirectory(leetcode)

