#include <stdio.h>
#include <time.h>

int main() {
    time_t start;
    start = time(NULL);
    printf("当前时间戳(秒): %ld\n", start);  // 1742806116

    clock_t c = clock();
    printf("当前clock: %ld", c);  // 372
    clock_t d = clock();
    printf("当前clock: %ld", d);  // 373
};

