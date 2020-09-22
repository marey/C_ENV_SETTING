//
// Created by Rui Mu on 22/9/20.
//
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// adt interface.
// poor design
// code style 3 分 0分


int main(int argc, char *argv[]){
    if (argc > 1) {
        Stack stack = newStack();
        for(int i=1;i < argc;i ++) {
            // 把参数压栈
            pushStack(stack, atoi(argv[i]));
        }
        while (!isEmptyStack(stack)) {
            int value = popStack(stack);
            printf("%d\n",value);
        }
    }
    return 1;
}
