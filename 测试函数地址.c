#include <stdio.h>


int add(int x, int y) {
    printf("调用函数\n");
    printf("x的地址: %d\n", &x);
    printf("y的地址: %d\n", &y);
    return x + y;
}

int main() {
    int x = 0;
    int y = 0;
    printf("x的位置: %d\n", &x);
    printf("y的位置: %d\n", &y);
    printf("函数的位置: %d\n", &add);
    add(x, y);
}
