//
// Created by Rui Mu on 20/6/20.
//
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



NodeT *makeNewNode(int v) {
    NodeT *   newNode = malloc(sizeof(struct _node));
    if (newNode!=NULL) {
        newNode->data = v;
        newNode->next = NULL;
    }
    return newNode;
}


NodeT *joinLL(NodeT *list,int v){

    // NodeT *newNode = malloc(sizeof(NodeT));
    NodeT *   newNode = makeNewNode(v);

    if (list ==NULL) {
        list =  newNode;
    }else {
        // temp 永不为空
        NodeT *temp = list;
        while(temp->next!=NULL) {
            temp = temp->next;
        }

//        while (true) {
//            if (temp->next == NULL) {
//                break;
//            }else {
//                temp = temp->next;
//            }
//        }

        temp->next = newNode;
    }

    return list;
}

void showLL(NodeT *list){

    if (list !=NULL) {
        printf("%d", list->data);

        NodeT *temp = list->next;
        while( temp!=NULL) {
            printf("-->%d",temp->data);
            temp = temp->next;
        }

        printf("\n");
    }

}

void  freeLL(NodeT *list){
    NodeT *first = list;
    // 1 2 3 4 5
    while(first!=NULL) {
        NodeT *next = first->next;
        free(first);
        first = next;
    }

}

void  freeLL2(NodeT *list){
    if(list!=NULL) {
        freeLL(list->next);
        free(list);
    }
}

