cmake_minimum_required(VERSION 3.20)
project(same_tree)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(binary-tree-playground)

add_executable(same_tree main.cpp)
target_link_libraries(same_tree binary_tree)