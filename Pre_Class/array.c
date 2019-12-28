//
// Created by Rui.Mu on 2019-05-22.
//

// https://www.cnblogs.com/onepixel/p/7674659.html

#include <stdio.h> // include standard I/O library defs and functions

#define SIZE 6     // define a symbolic constant



void swap_pointer(int* p1,int* p2) {
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}





void swap(int array[],int i,int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

}

/**
 * bubble sorting
 * @param array
 * @param n
 */
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {        // 相邻元素两两对比
                // swap element
                swap(array,j,j + 1);
            }
        }
    }
}

/**
 * insertion sorting
 * @param array
 * @param n
 */
void insertionSort(int array[], int n) {  // function headers must provide types
    int i;                                 // each variable must have a type
    for (i = 1; i < n; i++) {              // for-loop syntax
        int element = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = element;
    }
}

// logical AND
// abbreviated assignment j=j-1
// statements terminated by ;
// code blocks enclosed in { }
int main(int argc, char *argv[]) {
    // gcc array.c -o a.exe
    // ./a.out 1 2

    // argc = 3
    // argv[]

    // argv[0] // ./a.out

    // argv[1]
    // argv[2]





    int numbers[SIZE] = {3, 6, 5, 2, 4, 1};  /* array declaration
                                                 and initialisation */
    int i;
    insertionSort(numbers, SIZE);
    for (i = 0; i < SIZE; i++)
        printf("%d\n", numbers[i]);             // printf defined in <stdio>
    return 0;
}

