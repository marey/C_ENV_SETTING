//
// Created by YUJiehu on 2019-05-28.
//

// 1->2->3->4

// iterate
// next
// previous

#include "list.h"

typedef struct Node {
    struct Node *previous;
    struct Node *next;
    int data;
    int weight;
    int time;
} *LinkedNode;

struct _DoubleLinkedList {
    LinkedNode header;
    LinkedNode tail;
    LinkedNode current;
    int numberOfNodes;
};

// 1,2,3,4,6
// SET()


LinkedNode createNode(int data) {
    LinkedNode newNode = malloc(sizeof(struct Node));
    // check null, no memory
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    return newNode;
}


void StackPush(LinkedList list, int data){


    // last in, first out
    // create new node
    LinkedNode newNode = createNode(data);
    if(list !=NULL) {
        if(list->header == NULL) {
            list->header = newNode;
            list->tail = newNode;
            list->current = list->header;
            list->numberOfNodes++;
        } else {

            // 7, 1,3,4,5,6
            // newNode 7
            list->header->previous = newNode;
            newNode->next = list->header;
            list->header = newNode;
            list->numberOfNodes++;
        }
    }
}

int StackPop(LinkedList list){
    int result = 0;
    // 1,2,3,4,5
    if (list->header!=NULL) {
        LinkedNode tempNode = list->header;
        list->header = list->header->next;

        // 1,2,3,4,5
        if (list->header != NULL) {
            list->header->previous = NULL;
        }
        list->numberOfNodes--;
        result = tempNode->data;

        free(tempNode);
    }
    return result;
}

bool isEmpty(LinkedList list){
    return (list == NULL || list->numberOfNodes == 0);
}



LinkedList createLinkedList() {
    LinkedList list = malloc(sizeof(struct _DoubleLinkedList));
    if (list !=NULL ) {
        list->header = NULL;
        list->tail = NULL;
        list->current = NULL;
        list->numberOfNodes = 0;
    }

    return list;
}





void reset(LinkedList list) {
    if (list!=NULL) {
        list->current = list->header;
    }
}


LinkedNode next(LinkedList list) {
    if (list->current!=NULL && list->current->next!=NULL) {

        LinkedNode result = list->current;

        list->current = list->current->next;

        return result;
    }
    return NULL;
}


void insertListSorted(LinkedList list, int data) {
    // create new node
    LinkedNode newNode = createNode(data);
    if(list !=NULL) {
        if(list->header == NULL) {
            list->header = newNode;
            list->tail = newNode;
            list->current = list->header;
            list->numberOfNodes++;
        } else {
            LinkedNode tempNode = list->header;

            bool exist = false;
            while(tempNode!=NULL) {

                // 1,3,5,7,9
                // insert 4
                if (tempNode->data > data){
                    // 3
                    // 1,3,    4        5,7,9

                    //tempNode = 5 previousNode = 3   newNode = 4
                    LinkedNode previousNode = tempNode->previous;
                    //
                    previousNode->next = newNode;
                    //
                    newNode->previous = previousNode;
                    // 5
                    tempNode->previous = newNode;


                    newNode->next = tempNode;
                    list->numberOfNodes++;
                    exist = true;
                    break;
                }
                tempNode = tempNode->next;
            }

            if (!exist) {
                // 1,3,5,7,9
                // newNode 10
                newNode->previous = list->tail;
                list->tail->next = newNode;
                list->tail = newNode;
                list->numberOfNodes++;
            }

        }
    }

}

void deletetDoubleList(LinkedList list, int data) {
    // create new node
    if(!isEmpty(list)) {
        LinkedNode deleteNode;
        if (list->header->data   == data) {
            deleteNode = list->header;
            list->header = list->header->next;
            list->numberOfNodes--;
            free(deleteNode);

            // 1

            if (isEmpty(list)){
                list->tail = NULL;
            }
        } else if (list->tail !=list->header && list->tail->data == data) {
            deleteNode = list->tail;
            // 1,2,3,4,5
            list->tail = list->tail->previous;
            list->tail->next = NULL;
            free(deleteNode);
        } else {
            LinkedNode tempNode =  list->header;
            while ((tempNode = tempNode->next)!=NULL) {
                if (tempNode->data == data) {
                    // 1,2,3,4  3
                    deleteNode = tempNode;
                    LinkedNode previousNode = tempNode->previous;
                    previousNode->next = tempNode->next;
                    previousNode->next->previous = previousNode;
                    free(deleteNode);
                }
            }
        }
    }

}

/**
 * 1,2,3,4,5
 *
 * 1,2,9,10
 * 8
 * insert 3
 * @param list
 * @param data
 */
void insertListSet(LinkedList list, int data) {
    // create new node
    LinkedNode newNode = createNode(data);
    if(list !=NULL) {
        if(list->header == NULL) {
            list->header = newNode;
            list->tail = newNode;
            list->current = list->header;
            list->numberOfNodes++;
        } else {

            bool exist = false;
            LinkedNode tempNode = list->header;
            while(tempNode!=NULL) {
                if (tempNode->data == data){
                    exist = true;
                    break;
                }
                tempNode = tempNode->next;
            }
            // 1,3,4,5,6
            // newNode 6
            if (!exist) {
                newNode->previous = list->tail;
                list->tail->next = newNode;
                list->tail = newNode;
                list->numberOfNodes++;
            }
        }
    }

}


void insertList(LinkedList list, int data) {
    // create new node
    LinkedNode newNode = createNode(data);
    if(list !=NULL) {
        if(list->header == NULL) {
            list->header = newNode;
            list->tail = newNode;
            list->current = list->header;
            list->numberOfNodes++;
        } else {

            // 1,3,4,5,6
            // newNode 6
            newNode->previous = list->tail;
            list->tail->next = newNode;
            list->tail = newNode;
            list->numberOfNodes++;
        }
    }

}


void printDoubleLinkedListNext(LinkedList list) {

    if (list!=NULL) {
        LinkedNode temp = list->header;

        while (temp!=NULL) {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

void freeNode(LinkedList list) {

    if (list!=NULL) {
        // 1->2->3
        LinkedNode temp = list->header;
        LinkedNode first = list->header;
        //node = 1
        while (temp != NULL) {
            first = first->next;
            // 1
            free(temp);
            // temp
            temp = first;
        }
        temp = NULL;
        first = NULL;
        free(list);
        list = NULL;
    }
}


void freeStack(LinkedList list) {
    freeNode(list);
}




