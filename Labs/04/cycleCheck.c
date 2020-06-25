// Graph ADT
// Adjacency Matrix Representation ... COMP9024 20T2
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int c[100];
int i=0,j=0;
int dfsCycleCheck(Graph g,Vertex v){   
    assert(g != NULL);
    c[v]=1;
    for (i=v+1;i<g->nV;i++){
        if (g->edges[v][i]){
            if(c[i]){
                return 1;
            }
            else{
                if (dfsCycleCheck(g,i)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void){
    int n,TF=1;
    Edge e;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    
    Graph g=newGraph(n); 
    while (TF){
        printf("Enter an edge (from): ");
        TF=scanf("%d",&e.w);
        if(TF){
            printf("Enter an edge (to): ");
            TF=TF&&scanf("%d",&e.v);
            insertEdge(g,e);
        }
    }
    printf("Done.\nThe graph ");
    if(dfsCycleCheck(g,0)){
        printf("has a cycle.");
    }
    else{
        printf("is a acyclic.");
    }
    freeGraph(g);
    
}