//
// Created by Rui Mu on 22/9/20.
//


typedef struct list* LinkedList;

LinkedList createLinkedList();

void printLinkedList(LinkedList linkedList);

void insertLinkedList(LinkedList linkedList, int data);

void freeLinkedList(LinkedList linkedList);