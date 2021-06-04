#include <stdlib.h>
#include <stdio.h>

void test01() {
    int n;
    printf("n is : %d\n", n);
}

void test02() {
    int n;
    printf("n is : %d\n", n + 10);
}

void test03() {
    int n = 10;
    printf("n is : %d\n", n + 10);
}

void test04() {
    int *numbers = malloc(sizeof(int) * 10);
    numbers[0] = 10;
    free(numbers);

    numbers[0] = 10;

    printf("first is:%d", numbers[0]);
}

// 这是我的第一个函数
int main(int argc, char *argv[]) {

    test01();

    test02();

    test03();

    test04();

    return 0;
}
