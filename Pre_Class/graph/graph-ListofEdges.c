//
// Created by YUJiehu on 2019-01-09.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "Graph.h"
#include "list.h"

typedef struct GraphRep {
    List *edges; // array of lists
    int nV;
    int nE;
} GraphRep;

Graph newGraph(int nV) {
    assert(nV>=0);
    int i;

    Graph g = malloc(sizeof(GraphRep));

    assert(g!=NULL);

    g->nv = nV;
    g->nE = 0;

    g->edges = malloc(nV * sizeof(List));
    assert(g->edges!=NULL);

    for(i = 0;i<nV;i++) {
        g->edges[i] = NULL;
    }

    return g;
}


bool validV(Graph g,Vertex v) {
    return (g!=NULL && v >=0 && v < g->nV);
}

void insertEdge(Graph g,Edge e) {
    assert(g!=NULL && validV(g,e.v) && validV(g,e.w);
    if (!inLL(g->edges[e.v],e.w)) {
        g->edges[e.v] = insertLL(g->edges[e.v],e.w);

        g->edges[e.w] = insertLL(g->edges[e.w],e.v);

        g->nE ++;
    }
}

void removeEdge(Graph g,Edge e) {

    if(inLL(g->edges[e.v],e.w)) {
        g->edges[e.v] = deleteLL(g->edges[e.v],e.w);
        g->edges[e.w] = deleteLL(g->edges[e.w],e.v);
        g->nE --;
    }
}

void adjacent(Graph g,Vertex v,Vertex w) {
    return inLL(g->edges[v],w);
}

void showGraph(Graph g) {
    int i;
    for (i = 0;i<g->nV;i++) {
        printf("%d -",i);
        showLL(g->edges[i]);
    }
}

void freeGraph(Graph g) {
    int i;
    for(i = 0;i<g->nE;i++) {
        freeLL(g->edges[i]);
    }

    free(g);
}
