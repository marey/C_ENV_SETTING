//
// Created by YUJiehu on 2019-01-11.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

/**
 * new structure
 */
typedef struct node {
    int v;
    struct node *next;
} Node;

/**
 * make a new node
 * @param n vertex value
 * @return 返回Node
 */
Node *makeNode(int n) {
    Node *new = malloc(sizeof(Node));
    assert(new !=NULL);

    // 返回节点
    new->v = n;
    // 返回next
    new->next = NULL;

    // return new node
    return new;
}

/**
 * insert value
 * @param L List
 * @param n value of vertex
 * @return list
 */
List insert(List L,int n) {

    // check current node exists
    if(in(L,n)) {
        return L;
    }

    // create new node
    Node *new = makeNode(n);
    // new node made as new header
    new->next = L;
    // return new header
    return new;
}

/**
 * delete node
 * @param L list
 * @param n node
 * @return
 */
List delete(List L,int n) {
    // null
    if(L == NULL) {
        return L;
    }
    // match the value
    if (L->v == n) {
        return L->next;
    }

    // delete the value
    L->next = delete(L,n);

    // return the L
    return L;
}

/**
 * check vertex exists
 * @param L list
 * @param n vertex value
 * @return true exist/false not exists
 */
bool in(List L,int n) {

    // return false
    if(L == NULL) {
        return false;
    }
    // return true
    if(L->v == n) {
        return true;
    }
    // exist
    return in(L->next,n);
}

/**
 * show the list
 * @param L list
 */
void show(List L) {
    // false
    if(L == NULL) {
        putchar("\n");
    }else {
        printf("%d ",L->v);
        show(L->next);
    }
}

/**
 * free list
 * @param L list
 */
void freeLL(List L) {
    // free list
    if(L!=NULL) {
        // next node
        freeLL(L->next);
        // current node
        free(L);
    }
}
