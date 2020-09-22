//
// Created by Rui Mu on 22/9/20.
//
#include "Stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct stackObject {
    int values[MAX];
    int index;
};

/**
 * 创建一个栈
 * @return
 */
Stack newStack(){
    // 特别要注意：如果你的代码出现了segment fault 内存使用不当
    // 950行 segment fault
    // 60行 分配错误
    Stack new = malloc(sizeof(struct stackObject));
    new->index = 0;
    return new;
}

// 0    1  2
// 1

// 0    1     2   3    4   5
// 1    2     3   4    5
/**
 * 压栈
 */
void pushStack(Stack stack,int num){
    assert(stack!=NULL);
    if (stack->index < MAX) {
        stack->values[stack->index] = num;
        stack->index++;
    }
}

/**
 * 弹出栈
 * @return
 */
int popStack(Stack stack){
    assert(stack!=NULL);
    // 找不到值是-1
    int result = -1;
    if (stack->index > 0) {
        stack->index--;
        result = stack->values[stack->index];
    }
    return result;
}

/**
 * 判断是否为空
 * @return
 */
bool isEmptyStack(Stack stack){
    assert(stack!=NULL);

    return stack->index == 0;
}

/**
 * 释放stack
 */
void freeStack(Stack stack){
    assert(stack!=NULL);
    free(stack);
}