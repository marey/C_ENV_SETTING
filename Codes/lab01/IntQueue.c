# include <stdio.h>
# include <stdlib.h>
# include "IntQueue.h"
# include <assert.h>

typedef struct{
	int item[MAXITEMS];
	int head;
	int tail;
}queueRep;

static queueRep queueObject;
void QueueInit() {            // set up empty stack
   queueObject.head = 0;
   queueObject.tail = 0;
}
void QueueEnqueue(int num){
	// queue is full
	if ((queueObject.tail + 1) % MAXITEMS == queueObject.head)return;
	queueObject.item[queueObject.tail] = num;
	queueObject.tail = (queueObject.tail + 1)%MAXITEMS;
	return;
}
int QueueIsEmpty(){
	return queueObject.head == queueObject.tail;
}
int QueueDequeue(){
	if (queueObject.head == queueObject.tail) return -1;
	int result = queueObject.item[queueObject.head];
	queueObject.head = (queueObject.head + 1)%MAXITEMS;
	return result;
}


