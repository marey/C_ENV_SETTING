//
// Created by YUJiehu on 2019-05-28.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _DoubleLinkedList *LinkedList;

LinkedList createLinkedList();

void StackPush(LinkedList list, int data);

int StackPop(LinkedList list);

bool isEmpty(LinkedList list);

void freeStack(LinkedList list);

void insertListSet(LinkedList list, int data);

void insertListSorted(LinkedList list, int data);


void printDoubleLinkedListNext(LinkedList list);


