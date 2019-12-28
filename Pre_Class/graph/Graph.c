//
// Created by YUJiehu on 2019-01-09.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Graph.h"

typedef struct GraphRep {
    int **edges;    // adjacency matrix
    int nV;         // vertices;
    int nE;         // edges
} GraphRep;

Graph newGraph(int V) {
    assert(V >=0);
    int i;

    Graph g = malloc(sizeof(GraphRep));

    assert(g!=NULL);
    // vertices
    g->nV = 0;
    // edges
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges!=NULL);

    for(i=0;i<V;i++){
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i]!=NULL);
    }

    return g;
}

/**
 * check value vertices
 * @param g
 * @param v
 */
bool validV(Graph g, Vertex v) {
    return (g!=NULL && v >=0 && v< g->nV);
}

/**
 * insert edge
 * @param g graph
 * @param e edge
 */
void insertEdge(Graph g, Edge e) {
    if(!g->edges[e.v][e.w]) {
        g->edges[e.v][e.w] = 1;
        g->edges[e.w][e.v] = 1;
    }
    g->nE ++;
}

/**
 * remove the edge
 * @param g
 * @param e
 */
void removeEdge(Graph g,Edge e) {
    if(g->edges[e.v][e.w]) {
        g->edges[e.v][e.w] = 0;
        g->edges[e.v][e.w] = 0;
    }

    g->nE--;
}

/**
 * check adjacent
 * @param g
 * @param x
 * @param w
 * @return
 */
bool adjacent(Graph g,Vertex x,Vertex w) {

    assert(g!=NULL &&  validV(g,v) && validV(g,w) );

    return (g->edges[v][w] !=0);
}

void showGraph(Graph g) {
    assert(g!=NULL);
    int i,j;

    printf("Number of vertices : %d\n",g->nV);
    printf("Number of edges: %d\n",g->nE);
    for (i = 0;i<g->nV;i++){
        for (j=i+1;j<g->nV;j++){
            if (g->edges[i][j])
                printf("Edge %d - %d \n",i,j);
        }
    }
}

void freeGraph(Graph g) {
    assert(g!=NULL);
    int i;
    for(i = 0;i< g->nV;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

