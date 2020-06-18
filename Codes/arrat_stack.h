//
// Created by Rui Mu on 17/6/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct _Stack* Stack;

Stack createStack();

void pushStack(Stack stack, char value);

char popStack(Stack stack);

bool checkEmpty(Stack stack);

void freeStack(Stack stack);
