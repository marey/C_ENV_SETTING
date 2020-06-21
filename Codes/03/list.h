//
// Created by Rui Mu on 20/6/20.
//

typedef struct _node NodeT;

struct _node {
    int data;
    struct _node *next;
};

NodeT *joinLL(NodeT *list,int v);

void showLL(NodeT *list);

void  freeLL(NodeT *list);

