//
// Created by YUJiehu on 2019-01-09.
//

#ifndef COMP9024_GRAPH_H
#define COMP9024_GRAPH_H

#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints;
typedef int Vertex;

// edges are pairs of vertices
typedef struct Edge {
    Vertex v;
    Vertex w;
} Edge;

Graph newGraph(int);
void insertEdge(Graph,Edge);
void removeEdge(Graph,Edge);
bool adjacent(Graph,Vertex,Vertex);
void showGraph(Graph);
void freeGraph(Graph);



#endif //COMP9024_GRAPH_H
