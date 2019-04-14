cmake_minimum_required(VERSION 3.10)
project(datastruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(datastruct main.cpp tree/avl_tree.cpp tree/avl_tree.h tree/tree.cpp tree/tree.h tree/b_search.cpp tree/b_search.h)