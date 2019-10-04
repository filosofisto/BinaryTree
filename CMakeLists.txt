cmake_minimum_required(VERSION 3.15)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinaryTree main.cpp BinaryTree.cpp BinaryTree.h Node.cpp Node.h)