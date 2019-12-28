//
// Created by Rui.Mu on 2019-05-22.
//
#ifndef LISTITERINT_H
#define LISTITERINT_H

#include <stdio.h>

typedef struct IteratorIntRep *IteratorInt;

IteratorInt IteratorIntNew(); 
int add(IteratorInt it, int v);
int hasNext(IteratorInt it);
int hasPrevious(IteratorInt it);
int *next(IteratorInt it);
int *previous(IteratorInt it);
int deleteElm(IteratorInt it);
int set(IteratorInt it, int v);
int *findNext(IteratorInt it, int v);
int *findPrevious(IteratorInt it, int v);
void reset(IteratorInt it);
void freeIt(IteratorInt it);
void print(IteratorInt it);

#endif
