//
// Created by YUJiehu on 2019-01-09.
//

#include <stdbool.h>

#ifndef COMP9024_LIST_H
#define COMP9024_LIST_H

typedef struct Node *List;

List insertLL(List, int);

List deleteLL(List,int);

bool inLL(List,int);

void freeLL(List);

void showLL(List);

#endif //COMP9024_LIST_H
