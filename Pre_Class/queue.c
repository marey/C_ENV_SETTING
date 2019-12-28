//
// Created by Rui.Mu on 2019-05-22.
//
#include "IntStack.h"
#include <assert.h>

#define MAXITEMS 10

static struct {
    int item[MAXITEMS];
    int top;
} queueObject;

void QueueInit() {
    queueObject.top = -1;
}

int QueueIsEmpty() {
    return (queueObject.top < 0);
}

void QueueEnqueue(int n) { // insert int at end of queue
    assert(queueObject.top < MAXITEMS - 1);
    queueObject.top++;
    for (int i = queueObject.top; i > 0; i--) {
        queueObject.item[i] = queueObject.item[i - 1];
    }

    //5 1，2，3

    queueObject.item[0] = n;
}

int QueueDequeue() {
    assert(queueObject.top > -1);
    int i = queueObject.top;
    int n = queueObject.item[i];
    queueObject.top--;
    return n;
}

