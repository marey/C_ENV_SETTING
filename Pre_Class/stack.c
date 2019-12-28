//
// Created by Rui.Mu on 2018-12-16.
//
#include "stack.h"
#define MAXITEMS 10

static struct {
    int item[MAXITEMS];
    int top;

} stackObject;

void StackInit() {
    // set up empty stack
    stackObject.top = -1;
}

int StackIsEmpty() {
    // check whether stack is empty
    return (stackObject.top < 0);
}

void StackPush(int n) {
    // insert int on top of stack
    assert(stackObject.top < MAXITEMS - 1);
    stackObject.top++;
    int i = stackObject.top;
    stackObject.item[i] = n;


    // 1，2，3，5
}

int StackPop() {
    assert(stackObject.top > -1);
    int i = stackObject.top;
    int n = stackObject.item[i];
    stackObject.top--;

    return n;
}




