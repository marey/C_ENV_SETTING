
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "list.h"


struct house {
    // 门牌号
    int code;
    // 住了几口人
    int number;
    // 指引路标
    Node next;
    // 向前去找
    Node pre;
};


struct list {
    // 街道办
    Node header;
    Node last;
    // 街道口有一个指示牌
    int total;
};


Node makeNode(int code, int number) {
    Node newNode = malloc(sizeof(struct house));
    if (newNode != NULL) {
        newNode->code = code;
        newNode->number = number;
        newNode->next = NULL;
        newNode->pre = NULL;
    }
    return newNode;
}

List createList() {
    List newList = malloc(sizeof(struct list));
    newList->header = NULL;
    newList->last = NULL;
    newList->total = 0;
    return newList;
}
// 往街道上每次都插入房子
//  每次插入算法复杂度是O(1)
void insertListToLast(List list, int code, int number) {
    if (list->header == NULL) {
        // 只有一个房子的时候
        list->header = makeNode(code, number);
        list->last = list->header;
        list->total++;
    } else {
        // 已经知道最后一个last
        // 1 2 3 4->5(last)
        // newLast = 6
        Node newLast = makeNode(code, number);
        // 追加到最后
        newLast->pre = list->last;
        // 5->6
        list->last->next = newLast;
        // 6成为最后的last
        list->last = newLast;
        list->total++;
    }
}

void printList(List list) {
    // 不停的向下找
    Node temp = list->header;
    printf("List total: %d\n", list->total);
    // O(n)算法复杂度
    while (temp != NULL) {
        printf("code: %d, number: %d\n", temp->code, temp->number);
        temp = temp->next;
    }
}

// 判断是否存在
// 算法复杂度是O(n)
bool existsList(List list, int code) {
    bool result = false;
    Node temp = list->header;
    while (temp != NULL) {
        if (temp->code == code) {
            result = true;
            break;
        }
        temp = temp->next;
    }
    return result;
}

List intersection(List list1, List list2) {
    List result = createList();
    Node temp = list1->header;
    while (temp != NULL) {
        if (existsList(list2, temp->code) == true) {
            // 存在
            insertListToLast(result, temp->code, temp->number);
        }
        temp = temp->next;
    }

    return result;
}

List unionList(List list1, List list2) {
    List result = createList();
    Node temp = list1->header;
    while (temp != NULL) {
        if (existsList(result, temp->code) == false) {
            // 不存在
            insertListToLast(result, temp->code, temp->number);
        }
        temp = temp->next;
    }
    temp = list2->header;
    while (temp != NULL) {
        if (existsList(result, temp->code) == false) {
            // 不存在
            insertListToLast(result, temp->code, temp->number);
        }
        temp = temp->next;
    }

    return result;
}

void freeList(List list1) {
    if (list1!=NULL) {
        Node p = list1->header;
        while (p != NULL) {
            Node temp = p->next;
            free(p);
            p = temp;
        }
        free(list1);
    }
}



