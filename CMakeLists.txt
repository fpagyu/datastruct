cmake_minimum_required(VERSION 3.10)
project(datastruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(datastruct main.cpp tree/avl.h tree/tree.h tree/bst.h)