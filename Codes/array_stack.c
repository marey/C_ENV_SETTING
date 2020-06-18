//
// Created by Rui Mu on 17/6/20.
//
#include "arrat_stack.h"
// poperties
// array
// size/total

// operations
// create
// push
// pop
// checkEmpty/isEmpty
// free

struct _Stack {
    char values[100];
    int total;
};

Stack createStack() {
    // 8bytes
    // 特别要注意
    Stack newStack = malloc(sizeof(struct _Stack));
    // assert(newStack != NULL);
    if (newStack != NULL) {
        newStack->total = 0;
    }

    return newStack;
}

void pushStack(Stack stack, char value) {
    // 0 1 2 3 4 5 6 7
    // 1 2 3 4 5
    if (stack!=NULL) {
        stack->values[stack->total] = value;
        stack->total++;
    }
}

char popStack(Stack stack) {
    // 0 1 2 3 4 5 6 7
    // 1 2 3 4 5
    // total = 5
    if (stack!=NULL && stack->total > 0) {
        stack->total--;
        return stack->values[stack->total];
    }

    return NULL;
}

bool checkEmpty(Stack stack){
    if (stack!=NULL && stack->total > 0) {
        return false;
    }
    return true;
}

void freeStack(Stack stack){
    free(stack);
}



