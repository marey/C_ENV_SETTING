//
// Created by YUJiehu on 2019-01-09.
//

#include "Graph.h"
#include <stdio.h>

#define NODES 5

int main(void) {

    Graph  g = newGraph(NODES);

    Edge e;

    e.v = 0; e.w = 4;
    insertEdge(g,e);

    e.v = 1;e.w = 3;
    insertEdge(g,e);

    e.v = 3;e.w = 1;
    insertEdge(g,e);
    e.v = 3;e.w = 4;

    showGraph(g,e);
    putchar("\n")

    e.v = 1; e.w = 3;
    removeEdge(g,e);
    e.v = 4;e.w = 0;
    removeEdge(g,e);
    e.v = 4;e.w = 1;
    removeEdge(g,e);
    showGraph(g);
    freeGraph(g);

    return 0;
}

