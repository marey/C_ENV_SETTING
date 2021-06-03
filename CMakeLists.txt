cmake_minimum_required(VERSION 3.14)
project(C_ENV_SETTING C)

set(CMAKE_C_STANDARD 11)



add_executable(C_ENV_SETTING
        Codes/main.c
        )


add_executable(test.exe
        Codes/main02.c
        )

add_executable(LinkedList
        Codes/main.c
        Codes/list.c
        Codes/list.h
        )

