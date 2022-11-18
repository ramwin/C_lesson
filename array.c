#include <stdio.h>



void print(int arr[], int size) {
    for (int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
};


void no_init() {
    int no_init[1000];
    printf("如果没有初始化, 值不一定为0, 是: %d\n", no_init[500]);
};


void init() {
    int arr[10] = {[0]=1, [5]=2};
    printf("可以部分初始化, 初始化不是0: %d\n", arr[5]);
    printf("可以部分初始化, 其他都是0: %d\n", arr[3]);
};

void revers_designator() {
    int arr[] = {[3]=2, [0]=0, 1, 2, 3, 4};
    print(arr, sizeof(arr)/sizeof(arr[0]));
};

void variable_array_init() {
    // 直接报错了, 无法编译
    int y=5;
    // int arr[y] = {0, 1, 2, 3};
    // print(arr, sizeof(arr) / sizeof(arr[0]));
};


int main() {
    no_init();
    init();
    revers_designator();
    // variable_array_init();
    return 0;
}
