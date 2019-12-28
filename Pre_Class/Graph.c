//
// Created by YUJiehu on 2019-05-28.
//

// 图：vertex,edge.
// 有向图，无向图
//
// 【悉尼，墨尔本，布里斯班，北京，上海】

// 0,1,
// vertix 0，n - 1

// array,list,matrix
// spinning tree.
#include "list.h"

int main(int argc,char* argv[]) {

    int numberOfVertex = 5;
    LinkedList *edges;
    edges = malloc(numberOfVertex * sizeof(LinkedList));

    for(int i = 0;i<numberOfVertex;i++) {
        edges[i] = createLinkedList();
    }

    insertListSorted(edges[0],1);
    insertListSorted(edges[0],2);
    insertListSorted(edges[2],4);
    insertListSorted(edges[3],4);

    // insertListSorted(edges[3],0);

    // insertListSet(edges[2],3);

    // insertListSet(edges[2],3);
    // insertListSorted(edges[0],3)

    for(int i = 0;i<numberOfVertex;i++) {
        printf("current vertex is %d: the edges are:\n",i);
        printDoubleLinkedListNext(edges[i]);

        printf("\n");
    }
}



