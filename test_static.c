#include <stdio.h>

static int i[1024*1024*1024];
unsigned int global_int_array[1024*1024*1024];

void f() {
    static int g = 3;  // 只赋值一次. 变成0后也不会变成3
    int i[2*1024*1000];
    g--;
    printf("g=%d\n", g);
};

int main() {
    printf("%ld\n", sizeof(global_int_array));
    for (int i=0;  i<=20; i++) {
        f();
    };
    for (unsigned int i=0; i<=1024*1024*1024; i++) {
        global_int_array[i] = i;
    }
    return 0;
};
