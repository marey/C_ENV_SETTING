//
// Created by Rui Mu on 17/6/20.
//
#include "arrat_queue.h"
// poperties
// array
// size/total

// operations
// create
// push
// pop
// checkEmpty/isEmpty
// free

struct _Queue {
    int values[100];
    int total;
};

Queue createQueue() {
    // 8bytes
    // 特别要注意
    Queue newQueue = malloc(sizeof(struct _Queue));
    // assert(newQueue != NULL);
    if (newQueue != NULL) {
        newQueue->total = 0;
    }

    return newQueue;
}

void enterQueue(Queue queue, int value) {
    // 0 1 2 3 4 5 6 7
    // 1 2 3 4 5
    if (queue!=NULL) {
        queue->values[queue->total] = value;
        queue->total++;
    }
}

int deQueue(Queue queue) {
    // 0 1 2 3 4 5 6 7
    // 1 2 3 4 5
    // 2 3 4 5
    if (queue!=NULL && queue->total > 0) {
        int result = queue->values[0];
        for(int i=1;i<queue->total;++){
            queue->values[i-1] = queue->values[i];
        }
        queue->total--;
        return result;
    }

    return NULL;
}

bool checkEmpty(Queue queue){
    if (queue!=NULL && queue->total > 0) {
        return false;
    }
    return true;
}

void freeQueue(Queue queue){
    free(queue);
}



