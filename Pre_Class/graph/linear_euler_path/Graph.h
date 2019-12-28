//
// Created by YUJiehu on 2019-01-11.
//

#ifndef COMP9024_GRAPH_H
#define COMP9024_GRAPH_H

#include <stdbool.h>

// graph
typedef GraphRep *Graph;
// vertices are ints
typedef int Vertex;

// edge
typedef struct edge {
    Vertex v;
    Vertex x;
} Edge;

// 添加新的图形
Graph newGraph(int);
// 添加边
void insertEdge(Graph,Edge);
// remove edge
void removeEdge(Graph,Edge);
// adjacent
bool adjacent(Graph,Vertex,Vertex);
// show graph
void showGraph(Graph);
// free
void freeGraph(Graph);

#endif //COMP9024_GRAPH_H
