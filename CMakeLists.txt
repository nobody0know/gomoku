cmake_minimum_required(VERSION 3.24)
project(delta_wuziqi)

set(CMAKE_CXX_STANDARD 17)

add_executable(delta_wuziqi main.cpp board.cpp board.h node_table.cpp node_table.h)
