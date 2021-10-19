#include <stdio.h>
#include <stdlib.h>


int get_stack_addr() {
    int x = 7;
    printf("栈地址: %p\n", &x);
    return 0;
};


int main() {
    // get_stack_addr();
    // 尺寸 字节
    // 24   32
    // 25   48
    // 26   48
    // 55   64
    for (int size = 0; size<= 70; size++) {
    char *description;
    char *description1;
    char *description2;
    description = (char *)malloc(size);
    description1 = (char *)malloc(size);
    description2 = (char *)malloc(size);
    printf("description的地址是: %p\n", description);
    printf("description1的地址是: %p\n", description1);
    printf("description2的地址是: %p\n", description2);
    printf("尺寸 %d 对应的地址偏移是: %lu, %lu\n",
            size,
            description1 - description,
            description2 - description1);
    }
    // get_stack_addr();
}
