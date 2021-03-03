cmake_minimum_required(VERSION 3.14)
project(C_ENV_SETTING C)

set(CMAKE_C_STANDARD 11)

# 1.1个工程文件只能有一个main方法入口
# file01.c  method main
# file02.c  method main
add_executable(C_ENV_SETTING
        Codes/main.c
        )

