cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C IntStack.c IntStack.h IntStackTest.c)