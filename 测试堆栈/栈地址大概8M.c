#include <stdio.h>

int f(int x) {
    int p;
    printf("调用f, x(%d)内存地址: %d\n", x, &x);
    if ((x == 1) || (x == 2)) {
        return 1;
    }
    return f(x-1) + x;
};

int main() {
    // int x = 262000;  // 这个就溢出, segmentation fault了
    int x = 260000;  // 这个就不会溢出
    printf("f(%d)是: %d\n", x, f(x));
}
