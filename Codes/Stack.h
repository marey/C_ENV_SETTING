//
// Created by Rui Mu on 22/9/20.
//
#include <stdbool.h>
#define MAX 100

typedef struct stackObject *Stack;

/**
 * 创建一个栈
 * @return
 */
Stack newStack();

/**
 * 压栈
 */
void pushStack(Stack,int);

/**
 * 弹出栈
 * @return
 */
int popStack(Stack);

/**
 * 判断是否为空
 * @return
 */
bool isEmptyStack(Stack);


/**
 * 释放stack
 */
void freeStack(Stack);
