//
// Created by YUJiehu on 2019-01-11.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "Graph.h"

/**
 * struct
 */
typedef struct GraphRep {
    List *edges;
    int nV;
    int nE;
} GraphRep;

/**
 * new graph
 * @param nV vertices
 * @return return new graph
 */
Graph newGraph(int nV) {
    assert(nV >= 0);
    int i;

    Graph g = malloc(sizeof(Graph));
    assert(g != NULL);
    g->nV = nV;
    g->nE = 0;
    // create edges
    g->edges = malloc(nV * sizeof(List));
    // assert edges
    assert(g->edges !=NULL);
    // edges
    for(i = 0;i<nV;i++) {
        g->edges[i] = NULL;
    }

    return g;
}

/**
 * check vertex valid
 * @param g graph
 * @param v vertex
 * @return
 */
bool validV(Graph g,Vertex v) {
    return (g!=NULL && v>=0 && v<g->nV);
}

// insert edege
void insertEdge(Graph g,Edge e) {
    if(!inLL(g->edges[e.v],e.w)) {
        g->edges[e.v] = insert(g->edges[e.v],e.w);
        g->edges[e.w] = insert(g->edges[e.w],e.v);
        g->nE ++;
    }
}

void removeEdge(Graph g,Edge e) {
    if(inLL(g->edges[e.v],ew)) {
        g->edges[e.v] = delete(g->edges[e.v],e.w);
        g->edges[e.w] = delete(g->edges[e.w],e.w);
        g->nE--;
    }
}

void adjacent(Graph g,Vertex v,Vertex w) {
    return in(g->edges[v],w);
}

void showGraph(Graph g) {
    int i;
    for(i=0;i<g->nV;i++) {
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
