// Autor: Rui Mu
// Date: 2020-09-10
// C Program: Hello world

// 2521，9024 学完，debug能力，还有编程思维

#include <stdio.h>

int main(int argc, char *args[]) {
    int number = 0;
    while (1) {
        printf("请输入一个数字：");
        if (scanf("%d", &number) == 1) {
            printf("your input is %d\n", number);
        }
        if (number > 100) {
            break;
        }
    }

    return 0;
}