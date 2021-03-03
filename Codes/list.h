
typedef struct house *Node;
typedef struct list *List;

// 创建list
List createList();
// 插入list
void insertListToLast(List list, int code, int number);
// 打印list
void printList(List list);
// 交集
List intersection(List list1, List list2);
// 合集
List unionList(List list1, List list2);
// 释放内存
void freeList(List list1);