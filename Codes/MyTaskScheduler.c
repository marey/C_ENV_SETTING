#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// This template is only a guide 
// You need to include additional fields, data structures and functions


// BinomialHeaps
//
// BinomialHeap 2的k次方个nodes 同时满足的是一个二项堆 c(k,i) i表示的是level，k表示的是depth
// HeapNode


//      11
//    20  30
//        40

//     15
//   30   40
// 60
// merge two heaps
//          11
//    20 ->  30->       15
//             \>
////           40     30   40
////             60

// depth
//
// size = nodes of heap    size = 2 的 depth 次方


// heaps
//  BinomialHeaps
//   11    ->     15      ->   20     ->         30
//                 20         30 40          40  50  30
//                              50            60  70   80
//                                                    90



// data type for heap nodes
typedef struct HeapNode {
    // each node stores the priority (key), name, execution time,
    //  release time and deadline of one task
    int key; //key of this task
    int TaskName;  //task name
    int Etime; //execution time of this task
    int Rtime; // release time of this task
    int Dline; // deadline of this task
    // add additional fields here
    // 兄弟姐妹
    struct HeapNode *siblings;
    // 所有的孩子
    struct HeapNode *children;
    int size; // number of nodes
    int depth;
} HeapNode;

//data type for a priority queue (heap) 
typedef struct BinomialHeap { //this is heap header
    int size;      // count of items in the heap
    struct HeapNode *root;
    struct BinomialHeap *next;
} BinomialHeap;


// 1.heap,
// 2.after merge
//  BinomialHeaps
// k = log(n)
// k /log(n)
//               first
//   11    ->     15      ->   20     ->         30
//                 20         30 40          40  50  30
//                              50            60  70   80
//
//              second
//   9    ->     13      ->   15     ->         20
//                 20         30 40          40  50  30
//                              50            60  70   80
//
// third
// 9
//  11
//

//data type for a priority queue (heap)
typedef struct BinomialHeaps { //this is heap header
    int size;      // count of items in the heap
    struct BinomialHeap *first;
} BinomialHeaps;


// create a new heap node to store an item (task) 
HeapNode *newHeapNode(int k, int n, int c, int r, int d,
                      ...) { // k:key, n:task name, c: execution time, r:release time, d:deadline
    // ... you need to define other parameters yourself)
    HeapNode *new;
    new = malloc(sizeof(HeapNode));
    assert(new != NULL);
    new->key = k;
    new->TaskName = n;
    new->Etime = c;
    new->Rtime = r;
    new->Dline = d;
    // initialise other fields
    new->siblings = NULL;
    new->children = NULL;
    return new;
}

BinomialHeap *newHeap() {
    BinomialHeap *new;
    new = malloc(sizeof(BinomialHeap));
    assert (new != NULL);

    new->size = 0;
    new->next = NULL;
    new->root = NULL;

    return new;
}

// create a new empty heap-based priority queue
BinomialHeaps *newHeaps() { // this function creates an empty binomial heap-based priority queue
    BinomialHeaps *T;
    T = malloc(sizeof(BinomialHeaps));
    assert (T != NULL);
    // initialise all the fields here
    T->size = 0;
    T->first = NULL;
    return T;
}

// 假设 first的root 永远比second的root的value小
// 1, 2
// 2,1
// 1,2
BinomialHeap *mergeTwoHeaps(BinomialHeap *first, BinomialHeap *second) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    if (first->size == 0) {
        free(first);
        return second;
    }
    if (second->size == 0) {
        free(second);
        return first;
    }

    if (first->root->key > second->root->key) {
        return mergeTwoHeaps(second, first);
    }
    //      11
    //    20  30
    //        40


    //     15
    //   30   40
    // 60
    if (first->root->children == NULL) {
        // first  11
        // second 12

        //     11
        //       12
        first->root->children = second->root;
        first->size = first->size + second->size;
        free(second);
        return first;
    } else {
        HeapNode *tempNode = first->root->children;
        while (tempNode->siblings != NULL) {
            tempNode = tempNode->siblings;
        }
        tempNode->siblings = second->root;
        first->size = first->size + second->size;
        free(second);
        return first;
    }
}

void mergeHeapToBinomialHeaps(BinomialHeap *heap, BinomialHeaps *heaps) {
    // heap
    //   12
    // 30  100
    //      200

    // heaps
//  BinomialHeaps
//   11    x     15      ->   20     ->         30
//                 20         30 40          40  50  30
//                              50            60  70   80
//
    if (heap != NULL && heap->size > 0) {
        if (heaps->first == NULL) {
            heaps->first = heap;
            heaps->size = heap->size;
        } else {
            // 如果第一个node就相等
            if (heap->size == heaps->first->size) {
                BinomialHeap *mergeHeap = heaps->first;
                heaps->first = heaps->first->next;
                mergeHeap->next = NULL;
                heaps->size = heaps->size - mergeHeap->size;

                mergeHeap = mergeTwoHeaps(heap, mergeHeap);
                // 11
                //   12
                mergeHeapToBinomialHeaps(mergeHeap, heaps);
                heaps->size = heaps->size + mergeHeap->size;
            } else {
                BinomialHeap *pre = heaps->first;
                BinomialHeap *second = heaps->first->next;
                while (second != NULL) {
                    if (second->size == heap->size) {
                        // heap
                        //   12
                        // 30  100
                        //      200

                        //  BinomialHeaps
                        //               first        second
                        //   11    ->     15      ->   20     ->         30
                        //                 20         30 40          40  50  30
                        //                              50            60  70   80
                        break;
                    }
                    pre = pre->next;
                    second = second->next;
                }
                if (second == NULL) {
                    pre->next = heap;
                    heaps->size = heaps->size + heap->size;
                } else {
                    // heap
                    //   12
                    // 30  100
                    //      200

                    // n
                    // log（n) = k
                    //  k-1,k-2,k-3  1
                    // k*(k-1)/2

                    // 1,2 ,3 ,4 ,5 ,6,8,10(k个点）
                    // 1,2

                    // 1，2,4,8,16,32
                    //   4

                    // k = log(n)
                    // (logn)的平方
                    //  BinomialHeaps
                    //               first        second
                    //   11    ->     15      ->   20     ->         30
                    //                 20         30 40          40  50  30
                    //                              50            60  70   80
                    pre->next = second->next;
                    second->next = NULL;
                    heaps->size = heaps->size - second->size;
                    BinomialHeap *mergeHeap = mergeTwoHeaps(heap, second);
                    mergeHeapToBinomialHeaps(mergeHeap, heaps);
                    heaps->size = mergeHeap->size + heap->size;
                }
            }
        }
    }
}


// put the time complexity analysis for Insert() here
// insert complexity
void Insert(BinomialHeaps *T, int k, int n, int c, int r,
            int d) { // k: key, n: task name, c: execution time, r: release time, d:deadline
    // You don't need to check if this task already exists in T
    //put your code here

    HeapNode *newNode = newHeapNode(k, n, c, r, d);
    BinomialHeap *new_heap = newHeap();
    new_heap->root = newNode;
    new_heap->next = NULL;
    new_heap->size = 1;
    mergeHeapToBinomialHeaps(new_heap, T);
}

int sizeOfHeapNode(HeapNode *tempNode) {
    int result = 0;

    if (tempNode != NULL) {
        result = result + sizeOfHeapNode(tempNode->siblings);
        result = result + sizeOfHeapNode(tempNode->children);
        result++;
    }


    return result;
}


// put your time complexity for RemoveMin() here
HeapNode *RemoveMin(BinomialHeaps *T) {
    // put your code here
    //               first        second
    //   11    X     15      ->   10     ->         30
    //                 20         30 40          40  50  30
    //                              50            60  70   80

    // 30   40
    //        50



    // 11
    //   30

    // 40        11
    //   50    15   30
    //          20
    HeapNode *result = NULL;
    if (T != NULL && T->size > 0) {
        BinomialHeap *second = T->first->next;
        BinomialHeap *first = T->first;

        BinomialHeap *minHeapPre = T->first, *minHeap = T->first;

        result = first->root;
        while (second != NULL && second->root != NULL) {
            if (second->root->key < result->key) {
                // 找到最小值
                result = second->root;
                minHeapPre = first;
                minHeap = second;
            }
            first = first->next;
            second = second->next;
        }

        if (minHeap == T->first) {
            T->first = minHeap->next;
            minHeap->next = NULL;
            T->size = T->size - minHeap->size;
        } else {
            minHeapPre->next = minHeap->next;
            minHeap->next = NULL;
            T->size = T->size - minHeap->size;
        }

        HeapNode *tempNode = minHeap->root->children;
        HeapNode *next = NULL;
        while (tempNode != NULL) {
            next = tempNode->siblings;
            tempNode->siblings = NULL;
            BinomialHeap *new_heap = newHeap();
            new_heap->root = tempNode;
            new_heap->next = NULL;
            new_heap->size = sizeOfHeapNode(tempNode);
            mergeHeapToBinomialHeaps(new_heap, T);
            tempNode = next;
        }
    }
    return result;
}

int Min(BinomialHeaps *T) {
    // put your code here
    int result = 0;
    if (T != NULL && T->size > 0) {
        BinomialHeap *first = T->first;
        result = first->root->key;
        while (first->next != NULL && first->next->root != NULL) {
            if (result > first->next->root->key) {
                result = first->next->root->key;
            }
            first = first->next;
        }
    }
    return result;

}

void readTasksFromFile(char *fileName, BinomialHeaps *T) {
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        int v, c, r, d;
        while (fscanf(file, "%d %d %d %d", &v, &c, &r, &d) != EOF) {
            Insert(T, r, v, c, r, d);
        }
        fclose(file);
    }

}


// put your time complexity analysis for MyTaskScheduler here
int TaskScheduler(char *f1, char *f2, int m) {
    // put your code here
    BinomialHeaps *releasedHeaps = newHeaps();
    BinomialHeaps *deadlineHeaps = newHeaps();


    readTasksFromFile(f1,releasedHeaps);

    // 当前每一个core任务开始时间为0
    int timeFrame = 0;
    int *cores = malloc(m * sizeof(int));
    for (int i=0;i<m;i++) {
        cores[i] = 0;
    }

    FILE *file = fopen(f2,"w");


    // 肯定有任务在执行
    while(releasedHeaps->size >0 || deadlineHeaps->size >0) {
        if (deadlineHeaps->size == 0 && timeFrame < Min(releasedHeaps)) {
            timeFrame = Min(releasedHeaps);
        }
        for (int i=0;i<m;i++) {
            cores[i] = timeFrame;
        }


        // insert 5个
        while(releasedHeaps->size >0 && Min(releasedHeaps) < timeFrame) {
            HeapNode *node = RemoveMin(releasedHeaps);
            Insert(deadlineHeaps, node->Dline, node->TaskName,node->Etime,
                    node->Rtime,node->Dline);
        }
        HeapNode *deadlineNode = RemoveMin(deadlineHeaps);
        // 找最小的core和value
        int minCoreValue = INT8_MAX;
        int coreOfMinValue = INT8_MAX;
        for (int i=0;i<m;i++) {
            if (minCoreValue > cores[i]) {
                minCoreValue = cores[i];
                coreOfMinValue = i;
            }
        }

        if (cores[coreOfMinValue] + deadlineNode->Etime < deadlineNode->Dline) {
            // print result;
            fprintf(file, "%d Core%d %d",deadlineNode->TaskName,coreOfMinValue + 1, coreOfMinValue);
            cores[coreOfMinValue] = cores[coreOfMinValue] + cores[coreOfMinValue];
        } else {
            return 0;
        }
        minCoreValue = INT8_MAX;
        for (int i=0;i<m;i++) {
            if (minCoreValue > cores[i]) {
                minCoreValue = cores[i];
            }
        }
        timeFrame = minCoreValue;
        free(deadlineNode);
    }
    free(cores);

    return 1;
}

int main() //sample main for testing 
{
    int i;
    i = TaskScheduler("samplefile1.txt", "feasibleschedule1.txt", 4);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is a feasible schedule on 4 cores */
    i = TaskScheduler("samplefile1.txt", "feasibleschedule2.txt", 3);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is no feasible schedule on 3 cores */
    i = TaskScheduler("samplefile2.txt", "feasibleschedule3.txt", 5);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is a feasible schedule on 5 cores */
    i = TaskScheduler("samplefile2.txt", "feasibleschedule4.txt", 4);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is no feasible schedule on 4 cores */
    i = TaskScheduler("samplefile3.txt", "feasibleschedule5.txt", 2);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is no feasible schedule on 2 cores */
    i = TaskScheduler("samplefile4.txt", "feasibleschedule6.txt", 2);
    if (i == 0) printf("No feasible schedule!\n");
    /* There is a feasible schedule on 2 cores */
    return 0;
}
