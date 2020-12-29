cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 90)

add_executable(C Algorithm/IntSetTest2.c Algorithm/IntSet.h Algorithm/IntSet.c)