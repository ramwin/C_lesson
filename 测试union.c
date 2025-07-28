#include <stdio.h>

union A {
    int a[100];
    struct {
        char name[10];
    };
};

int main() {
    union A a;
    printf("%ld\n", sizeof(union A));
};

