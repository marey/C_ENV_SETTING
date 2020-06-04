//
// Created by Rui Mu on 3/6/20.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// standard input output

// 1. 重点强调：C语言版本
// 2. 多加注释
// int char       float/double   unsigned

// 4bytes
// 0x000000   0x000004     0x000008
//    100      9999
// 1.标准输入，输入出
// <    >
int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argument index is %d, arguemnt is %s\n", i, argv[i]);
    }

    char word;
    // end of file
    while ((word = getchar()) != EOF) {
        if (isalpha(word)) {
            printf("%c", word);
        } else {
            printf("\n");
        }
    }
}