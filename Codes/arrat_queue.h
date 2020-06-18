//
// Created by Rui Mu on 17/6/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct _Queue* Queue;

Queue createQueue();

void enterQueue(Queue queue, int value);

int deQueue(Queue queue);

bool isEmptyQueue(Queue queue);

void freeQueue(Queue stack);
