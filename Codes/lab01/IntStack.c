# include <stdio.h>
# include <stdlib.h>
# include "IntStack.h"
# include <assert.h>

//
// 3
// 2
// 1


// 3  2 1


struct _stack {
    int item[MAXITEMS];
    int total;
};


Stack StackInit() {            // set up empty stack
    Stack stack = malloc(sizeof(struct _stack));
    stack->total = 0;
    return stack;
}

void StackPush(Stack stack, int num) {
    if (stack->total < MAXITEMS) {
        stack->item[stack->total] = num;
        stack->total++;
    }
}

// 1 2 3
// 1 2 3
// 3 2 1


int StackPop(Stack stack) {
    // 如果有3个元素，1，2 3，total 是3
    int result = -1;
    if (stack->total > 0) {
        result = stack->item[0];
        for(int i=1;i<stack->total;i++) {
            stack->item[i-1] = stack->item[i];
        }
        stack->total--;
    }
    return result;
}

bool StackIsEmpty(Stack stack) {
    bool result = false;
    if (stack->total == 0) {
        result = true;
    }
    return result;
}


