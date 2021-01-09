cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 90)

add_executable(C algorithm/ch7/IntSet.h algorithm/ch7/IntSet.c algorithm/ch7/IntSetTest2.c)
