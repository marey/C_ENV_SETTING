//
// Created by Rui Mu on 22/9/20.
//

#include "list.h"

int main() {
    LinkedList linkedList = createLinkedList();
    insertLinkedList(linkedList,1);
    insertLinkedList(linkedList,1);



    freeLinkedList(linkedList);
}
