//
// Created by Rui Mu on 22/9/20.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"
typedef struct node* Node;

struct node {
    int data;
    // 下一家是谁
    Node next;
};



struct list {
    Node first;
    int total;
};

Node createNode(int data) {
    // 森林里面盖房子 == 内存上分配空间
    Node newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList createLinkedList() {
    LinkedList newList = malloc(sizeof(struct list));
    newList->first = NULL;
    newList->total = 0;

    return newList;
}

void insertLinkedList(LinkedList linkedList, int data){
    assert(linkedList!=NULL);
    Node newNode = createNode(data);
    if (linkedList->total == 0) {
        linkedList->first = newNode;
        linkedList->total ++;
    } else {
        Node lastNode = linkedList->first;
        while(lastNode->next!=NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        linkedList->total++;
    }
}

void printNode(Node house){
    assert(house!=NULL);
    printf("data of node :%d\n", house->data);
}

void freeNode(Node node) {
    assert(node!=NULL);
    free(node);
}

void freeLinkedList(LinkedList linkedList) {
    assert(linkedList!=NULL);
    Node tempNode = linkedList->first;
    while (tempNode!=NULL) {
        Node nextNode = tempNode->next;
        freeNode(tempNode);
        tempNode = nextNode;
    }
    free(linkedList);
}

void printLinkedList(LinkedList linkedList) {
    assert(linkedList!=NULL);
    Node first = linkedList->first;
    while (first!=NULL) {
        printNode(first);
        first = first->next;
    }
}


