cmake_minimum_required(VERSION 3.14)
project(COMP9024_21T1 C)

set(CMAKE_C_STANDARD 11)

# include_directories(Tutorial_Class/Week04)
# 工程文件
# 1.1个工程文件只能有一个main方法入口
# file01.c  method main
# file02.c  method main
add_executable(COMP9024_21T1
        Codes/main.c
        )

