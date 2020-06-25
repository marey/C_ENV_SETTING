// Graph ADT interface ... COMP9024 20T2
#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
   Vertex v;
   Vertex w;
} Edge;

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);