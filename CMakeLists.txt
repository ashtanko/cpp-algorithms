cmake_minimum_required(VERSION 3.24)
project(
        cpp_algorithms
        LANGUAGES C CXX
        VERSION 1.0.0
        DESCRIPTION "Template project for code implemented in C and C++."
)

find_library(MATH_LIBRARY m)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_algorithms main.cpp)
add_subdirectory(leetcode)

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)

## Check for some required header files
include(CheckIncludeFile)
include(CheckSymbolExists)
check_include_file(stdbool.h HAS_STDBOOL_H)
check_include_file(inttypes.h HAS_INTTYPES_H)
check_include_file(complex.h HAS_COMPLEX_H)
if (HAS_COMPLEX_H)
    check_symbol_exists(complex complex.h HAS_COMPLEX_TYPE)
endif (HAS_COMPLEX_H)
if (NOT HAS_STDBOOL_H)
    message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif ()
if (NOT HAS_INTTYPES_H)
    message(FATAL_ERROR "Missing required header: 'inttypes.h'")
endif ()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
