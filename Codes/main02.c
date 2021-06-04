#include <stdlib.h>
#include <stdio.h>

// 这是我的第一个函数
int main(int argc, char *argv[]) {

    // printf("number of argument: %d\n", argc);
//    int total = 0;
//    for(int i = 1; i< argc; i++) {
//        printf("param index: %d, value: %s\n", i, argv[i]);
//        total = total + atoi(argv[i]);
//    }
//    printf("total: %d\n", total);





    int n = 10;

    // 没有初始化任何内容
    int eli_numbers[n];
    // 不指定数组的长度
    int numbers01[] = {1,2,3,4,5};
    // 指定数组的长度
    int numbers02[5] = {1,2,3,4,5};
    // 仅初始化期中的某些值
    int numbers03[5] = {1,2,3};
    // 根据变量
    int m = 10;
    int* eli_nums = malloc(sizeof(int) * m);


    eli_numbers[0] = 100;
    eli_numbers[1] = 35;

    eli_numbers[8] = 77;
    // 地址
    printf("the address of array: %p\n", eli_numbers);
    // 查看地址上面的value
    printf("the value of address: %d\n", *eli_numbers);
    // 数组
    printf("the item of array: %d\n", eli_numbers[0]);
    printf("the item of array: %p\n", &eli_numbers[0]);

    printf("the address of array: %p\n", eli_numbers + 8);
    // 查看地址上面的value
    printf("the value of address: %d\n", *(eli_numbers + 8));
    // 数组
    printf("the item of array: %d\n", eli_numbers[8]);
    printf("the item of array: %p\n", &eli_numbers[8]);


    int m = 10;

    int* eli_nums = malloc(sizeof(int) * m);
    eli_nums[0] = 100;
    eli_nums[1] = 35;
    eli_nums[8] = 77;
    printf("====================\n");
    // 地址
    printf("the address of array: %p\n", eli_nums);
    // 查看地址上面的value
    printf("the value of address: %d\n", *eli_nums);
    // 数组
    printf("the item of array: %d\n", eli_nums[0]);
    printf("the item of array: %p\n", &eli_nums[0]);
    printf("the address of array: %p\n", eli_nums + 8);
    // 查看地址上面的value
    printf("the value of address: %d\n", *(eli_nums + 8));
    // 数组
    printf("the item of array: %d\n", eli_nums[8]);
    printf("the item of array: %p\n", &eli_nums[8]);

    free(eli_nums);

    return 0;
}
