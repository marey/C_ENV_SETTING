//
// Created by YUJiehu on 2019-05-28.
//

#include "list.h"


bool checkCycle(int visited[],int vertex) {
    if (visited[vertex] == 1){
        return true;
    }else {
        visited[vertex] = 1;
        return false;
    }
}

int main() {
    LinkedList stack = createLinkedList();
    int numberOfVertices = 5;

    int visited[numberOfVertices] = {0,0,0,0,0};

    int edges[5][5];
    edges[1][2] = 1;
    edges[1][3] = 1;
    edges[2][3] = 1;
    edges[3][1] = 1;
    StackPush(stack,1);
    LinkedList *edges = []

    while(!isEmpty(stack)) {
        int sourceVertix = StackPop(stack);

        LinkedList currentList = edges[sourceVertix]

        header = currentList.header;
        while(header!=NULL) {
            if (checkCycle(visited,header->data)) {
                continue
            }else {
                StackPush(stack, header->data);
            }
            header = header->next;
        }
        printf("%d\n",sourceVertix);


        1,2,3,4,5,0
    }
}
