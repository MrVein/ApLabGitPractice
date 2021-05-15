cmake_minimum_required(VERSION 3.17)
project(BTS)

set(CMAKE_CXX_STANDARD 14)

add_executable(BTS main.cpp "Resource Files/BST.cpp" "Header Files/BST.h" "Resource Files/node.cpp" "Header Files/node.h")