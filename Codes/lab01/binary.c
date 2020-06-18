# include "IntStack.h"
# include <stdio.h>
# include <stdlib.h>


void method(int *total) {
    (*total)++;
}

int main() {
    int array1[] = {2, 2, 3, 3, 3};
    int array2[] = {2, 2, 2, 3, 3, 4};
    int m = 5, n = 6;

    int *array3 = malloc(sizeof(int) * (m + n));
    int index1 = 0, index2 = 0;

    int index3 = 0;

    while(index1 < m && index2 < n){
        if (array1[index1] < array2[index2]) {
            array3[index3] = array1[index1];
            index3++;
            index1++;
        }

        if(array1[index1] > array2[index2]) {
            array3[index3] = array2[index2];
            index3++;
            index2++;
        }
        if(array1[index1] == array2[index2]) {
            array3[index3] = array1[index1];
            index3++;

            array3[index3] = array2[index2];
            index3++;

            index1++;
            index2++;
        }
    }

    while(index1 < m) {
        array3[index3] = array1[index1];
        index3++;
        index1++;
    }
    while(index2 < n) {
        array3[index3] = array2[index2];
        index3++;
        index2++;
    }


    for(int i=0;i<(m+n);i++) {
        printf("===%d====\n",array3[i]);
    }


    free(array3);



}