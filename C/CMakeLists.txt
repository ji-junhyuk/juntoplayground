cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C IntDequeue.h IntDeque.c IntDequeueTest.c)