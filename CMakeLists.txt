cmake_minimum_required(VERSION 3.21)
project(polygon)

set(CMAKE_CXX_STANDARD 17)

add_executable(polygon main.cpp check_dot.cpp check_dot.h  check_error.cpp   check_error.h)
