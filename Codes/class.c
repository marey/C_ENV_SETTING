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

    char word[1024];
    // 如果stdin里面的内容长度大于 1024，最长读取1024
    // 小于1024
    // /Users/ruimu/CLionProjects/COMP9024_20T2/Codes/a.txt
    FILE *file = fopen("a.txt","r");
    char split_chars[5] = " ,\n\r";
    char *token;

    if (file!=NULL) {
        // 打开并读取文件
        while (fgets(word, 1024, file) != NULL) {
            // delete \n
            word[strlen(word) - 1] = '\0';
            // 此处代码段，需要记下来
            token = strtok(word, split_chars);
            while( token!=NULL) {
                printf("token is %s \n", token);
                // 特别要注意，此处是NULL
                token = strtok(NULL, split_chars);
            }

        }
        fclose(file);
    }




}