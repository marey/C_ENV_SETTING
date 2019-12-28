//
// Created by YUJiehu on 2019-01-11.
//

#include <stdbool.h>

#ifndef COMP9024_LIST_H
#define COMP9024_LIST_H

// list
// it's a node header
typedef Node *List;

/**
 * insert data
 * @return
 */
List insert(List,int);

/**
 * delete data
 * @return
 */
List delete(List,int);

/**
 * check exist
 * @return
 */
bool in(List,int);

/**
 * free list
 */
void freeLL(List);

/**
 * show list
 */
void show(List);

#endif //COMP9024_LIST_H
