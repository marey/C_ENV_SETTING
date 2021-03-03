// Autor: Rui Mu
// Date: 2020-09-10
// C Program: Hello world

// 2521，9024 学完，debug能力，还有编程思维
// OK fine
#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[]) {
    List list1 = createList();
    // 创建了第一户
    insertListToLast(list1, 1, 3);
    insertListToLast(list1, 2, 5);
    insertListToLast(list1, 3, 100);

    // 打印所有的Node
    printList(list1);

    List list2 = createList();
    // 创建了第一户
    insertListToLast(list2, 1, 3);
    insertListToLast(list2, 2, 5);
    insertListToLast(list2, 4, 100);
    printList(list2);

    List list3 = intersection(list1, list2);
    List list4 = unionList(list1, list2);

    printList(list3);
    printList(list4);


    freeList(list1);
    freeList(list2);
    freeList(list3);
    freeList(list4);
}