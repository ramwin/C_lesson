#include <stdio.h>
/*
 * 函数的位置最小
 * 然后是全局变量
 * 最后是栈
 * */


const int a = 3;
static int b;


int add(int x, int y) {
    printf("调用函数\n");
    printf("x的地址        : \t%p\n", &x);
    printf("y的地址        : \t%p\n", &y);
    printf("全局变量a的地址: \t%p\n", &a);
    printf("static变量b的地址: \t%p\n", &b);
    return x + y;
}

int main() {
    b = 4;
    int x = 0;
    int y = 0;
    printf("x的位置         : \t%p\n", &x);
    printf("y的位置         : \t%p\n", &y);
    printf("函数的位置      : \t%p\n", &add);
    add(x, y);
}
