#include <stdio.h>
#include <stdlib.h>

#define size 8000000

struct Student {
    int age;
    char name[1];
};

struct Student *students[size];

int main() {
    /*
        现象: 每次至少malloc 16字节. 并且不会page table会复用
        1 306
        20以下 8000000 变306M
        23 306
        24 306
        25 428  // 这时候一下子增加了16字节
        30 428
    */
    printf("%lu\n", sizeof(struct Student));
    for(int i=0; i<=size; i++) {
        students[i] = malloc(24);
        students[i]->age=i;
    }
    // free不需要信息,因为申请的内存前几个字节是control_block
    for(int i=0; i<=size; i++) {
        if (i%2 == 0) {
            free(students[i]);
        }
    }
    for(int i=0; i<=size; i++) {
        if (i%2 == 0) {
            // 因为25无法分配, 前面都是空洞, 所以如果11行改成25, 内存占用反而比较小
            // 那下次malloc的时候怎么知道前面有空洞呢
            students[i] = malloc(25);
            students[i]->age=i;
        }
    }
    int j;
    scanf("%d", &j);
    // 从printf看每次虚拟内存增加32字节. 明明只申请了5字节
    // 但是从实际占用来看,每次都是给了40字节
    for (int i=0; i<size; i++) {
        if (size <= 800) {
            printf("%p %d\n", students[i], students[i]->age);
        }
    }
};
