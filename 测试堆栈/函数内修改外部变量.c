#include <stdio.h>

void foo(int *x) {
    for (int i=-3; i<=3; i++) {
        printf("%d\n", *(x+i));
        (*(x+i))++;
    }
};

int main(int argc) {
    int array[7] = {1, 2, 3, 4, 5, 6, 7};
    foo(&array[3]);
    printf("我把x+i的变量的值都变了, 第二次循环就都是+1\n");
    foo(&array[3]);
    return 0;
};
