#include <stdio.h>


int main() {
    // 申请的a在栈里，所以8M以后就报错了
    int a[7 * 1024 * 1024 / 4];
    a[0] = 2;
    printf("%d\n", a[0]);
};
