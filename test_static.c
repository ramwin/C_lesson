#include <stdio.h>

void f() {
    static g = 3;  // 只赋值一次. 变成0后也不会变成3
    g--;
    printf("g=%d\n", g);
};

int main() {
    for (int i=0;  i<=20; i++) {
        f();
    };
};
