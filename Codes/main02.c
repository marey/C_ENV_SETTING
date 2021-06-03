#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("number of argument: %d\n", argc);

    for(int i = 0; i< argc; i++) {
        printf("param index: %d, value: %s\n", i, argv[i]);
    }

    return 0;
}
