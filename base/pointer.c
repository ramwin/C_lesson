#include <stdio.h>

struct Student {
    short id;  // 2字节
    char name[3];  // 3 x 1字节
};  // 最后对其到max(2, 1)字节,所以是6字节

int main() {
    void *p;  // void的指针每次+1
    struct Student* q;  // Student的指针每次+6
    struct Student alice;
    p = &alice;
    q = &alice;
    /*
     * p = 0x7ffe6c668be2, p+1= 0x7ffe6c668be3
       q = 0x7ffe6c668be2, q+1= 0x7ffe6c668be8
       * /

    printf("p = %p, p+1= %p\n", p, p+1);
    printf("q = %p, q+1= %p\n", q, q+1);
};
