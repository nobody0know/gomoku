cmake_minimum_required(VERSION 3.24)
project(gomoku_new)

set(CMAKE_CXX_STANDARD 17)

add_executable(gomoku_new main.cpp chess_ai.cpp chess_ai.h main.h)
