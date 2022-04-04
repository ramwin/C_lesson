#include <stdio.h>
#include <time.h>


int foo(int x) {
    if (x <= 1) {
        return 1;
    };
    return foo(x-1) + foo(x-2);
};

int main() {
    int result;
    clock_t main_start = clock();
    for (int i=20; i<=30; i++) {
        clock_t start = clock();
        result = foo(i);
        clock_t end = clock();
        printf(" foo(%d) = %d", i, result);
        printf("耗时: %u\n", end - start);
    }
    clock_t main_end = clock();
    printf("总耗时: %u\n", main_end - main_start);
};
