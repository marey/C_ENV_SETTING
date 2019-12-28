//
// Created by YUJiehu on 2019-01-09.
//

#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define ENOUGH 10000;

typedef struct GraphRep {
    Edges *edges;// array of edges
    int nV;
    int nE;
    int n;
} GraphRep;

Graph newGraph(int V) {
    assert(V >=0);

    Graph g = malloc(sizeof(GraphRep));
    assert(g!=NULL);
    g->nV = V;
    g->nE = 0;

    g->n = ENOUGH;

    g->edges = malloc(g->n * sizeof(Edge));

    assert(g->edges!=NULL);

    return g;
}

bool eq(Edge e1,Edge e2) {
    return ((e1.v == e2.v  && e1.w == e2.w)
    ||(e1.v == e2.w && e1.w = e2.v))
}

void insertEdge(Graph g,Edge e) {
    assert(g!=NULL && g->nE < g->n);


    int i=0;
    while (i<g->nE && !eq(e,g->edges[i])) {
        i++;
    }

    if (i==g->nE) {
        g->edges[g->nE++] = e;
    }
}

/**
 * 删除边框
 * @param g
 * @param e
 */
void removeEdge(Graph g,Edge e) {
    // not null
    assert(g!=NULL);

    int i=0;
    // check是否存在
    while (i<g->nE && !eq(e,g->edges[i])) {
        i++;
    }

    // exist
    if (i<g->nE) {
        g->edges[i] = g->edges[--g->nE];
    }
}

/**
 * 计算相邻的顶点
 * @param g graph
 * @param x 顶点
 * @param y 顶点
 * @return 返回true还是false
 */
bool adjacent(Graph g,Vertex x, Vertex y) {
    // assert
    assert(g!=NULL);

    Edge e;
    // vertices
    e.v = x;e.w = y;

    int i = 0;

    while(i < g->nE) {
        if (eq(e,g->edges[i]))
            return true;

        i++;
    }

    return false;

}

void showGraph(Graph g) {
    assert(g!=NULL);

    printf("Number of vertices: %d\n",g->nV);

    printf("Number of edges :%d\n",g->nE);

    int i;

    for(i = 0; i<g-nE;i++) {
        printf("Edge %d - %d \n",g->edges[i].v,g->edges[i].w);
    }
}

void freeGraph(Graph g) {
    assert(g!=NULL);
    free(g->edges);
    free(g);
}


