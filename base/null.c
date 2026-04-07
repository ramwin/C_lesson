#include <stdio.h>

int main() {
    int h;
    int *p = NULL;
    // 其实NULL就是0, 但是容易有歧义
    if (p == 0) {
        printf("p是null, 无法解引用\n");
    } else {
        printf("p(如果为NULL)的指针是 %p %d\n", p, *p);
    }
    p = &h;
    h = 4;
    printf("p(如果为h=4的地址)的指针是 %p %d\n", p, *p);
    // 因为p是int的指针,所以+1是加到第二个int,4字节
    printf("p(如果为h=4的地址)如果+1指针是 %p %d\n", p + 1, *(p+1));
};

