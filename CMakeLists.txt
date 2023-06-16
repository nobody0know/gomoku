cmake_minimum_required(VERSION 3.24)
project(delta_wuziqi)

set(CMAKE_CXX_STANDARD 17)

add_executable(delta_wuziqi main.cpp ChessAI.cpp ChessAI.h ChessBoard.cpp ChessBoard.h ChessMan.cpp ChessMan.h Judge.cpp Jude.h Match.cpp Match.h Point.cpp Point.h)
