cmake_minimum_required(VERSION 3.19)
project(assignment2 C)

set(CMAKE_C_STANDARD 11)

add_executable(assignment2 main.c functions.h inputPlayers.c board.c validMoves.c makeMove.c)