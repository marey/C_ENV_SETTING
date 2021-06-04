#include <stdlib.h>
#include <stdio.h>

// 这是我的第一个函数
int main(int argc, char *argv[]) {

    printf("number of argument: %d\n", argc);
    int total = 0;
    for (int i = 1; i < argc; i++) {
        printf("param index: %d, value: %s\n", i, argv[i]);
        total = total + atoi(argv[i]);
    }
    printf("total: %d\n", total);

    return 0;
}
