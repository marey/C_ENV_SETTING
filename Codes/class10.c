//
// Created by Rui Mu on 17/6/20.
//
//
// heap 堆           最大堆，最小堆
// stack 栈
// queue 队列


// stack 栈     last in first out
//  1 2 3 4 5
//
// push

// 5
// 4
// 3
// 2
// 1

// print()
// 5 4 3 2 1

// reverse    bracket(括号匹配算法）   逆波兰表达式

// queue 队列   first in first out
//  1 2 3 4 5
//
// push
// 1 2 3 4 5

// print
// 1 2 3 4 5

// C 基本数据类型
// int char float double
// array
#include "arrat_stack.h"
#include <string.h>

int main() {
    // 括号匹配算法
    // (()(())){()}
    //  左右括号，不匹配
    // 右边有
    // 左边有
    char brackts[] = "(()(())){()}\0";
    Stack stack = createStack();
    for (int i = 0; i < strlen(brackts); i++) {
        if (brackts[i] == '{' || brackts[i] == '[' || brackts[i] == '(') {
            pushStack(stack, brackts[i]);
            continue;
        }
        if (brackts[i] == '}' || brackts[i] == ']' || brackts[i] == ')') {
            if (checkEmpty(stack) == true) {
                printf(" right brackts much more!");
                break;
            } else {
                char pop_char = popStack(stack);
                if (brackts[i] == '}' && pop_char == '{') {
                    continue;
                } else if (brackts[i] == ']' && pop_char == '[') {
                    continue;
                } else if (brackts[i] == ')' && pop_char == '(') {
                    continue;
                } else {
                    printf(" right brackts not match!");
                }
            }
        }
    }

    if (checkEmpty(stack) == true) {
        printf(" all brackets matched!");
    } else {
        printf(" left brackts not match!");
    }

}


