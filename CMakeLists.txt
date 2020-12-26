cmake_minimum_required(VERSION 3.14)
project(COMP9024_20T2 C)

set(CMAKE_C_STANDARD 11)

# include_directories(Tutorial_Class/Week04)
# 工程文件
# 1.1个工程文件只能有一个main方法入口
# file01.c  method main
# file02.c  method main
add_executable(COMP9024_20T2
        Codes/main.c
        )

add_executable(COMP9024_20T2_LIST_MAIN
        Codes/list.h
        Codes/list.c
        Codes/list_main.c
        )

