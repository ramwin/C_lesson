#include <stdio.h>

int main() {
    char t = 'b';
    printf("变量t的内存地址: %d\n", &t);
    int x = 0;
    printf("变量x的内存地址: %d\n", &x);
    char z = 'a';
    char o;
    printf("变量z的内存地址: %d\n", &z);
    printf("变量o的内存地址: %d\n", &o);
    int a = 0;
    printf("变量a的内存地址: %d\n", &a);
    int b = 0;
    printf("变量b的内存地址: %d\n", &b);
    int c = 0;
    printf("变量c的内存地址: %d\n", &c);
    int d = 0;
    printf("变量d的内存地址: %d\n", &d);
    int e = 0;
    printf("变量e的内存地址: %d\n", &e);
    int f = 0;
    printf("变量f的内存地址: %d\n", &f);
}
