#include <stdio.h>
#include <time.h>
#include <threads.h>
#include <pthread.h>

#define START 30
#define END 43

int result[END - START];
pthread_t thread_ids[END - START];

int foo(int x) {
    if (x <= 1) {
        return 1;
    };
    return foo(x-1) + foo(x-2);
};

int call(int i) {
    clock_t start = clock();
    result[i-START] = foo(i);
    clock_t end = clock();
    printf(" foo(%d) = %d", i, result[i-START]);
    printf("耗时: %u\n", end - start);
    return i;
};

void *thread(void *argp) {
    call(1);
};

int main() {
    clock_t main_start = clock();
    thrd_t *thr;
    for (int i=START; i<END; i++) {
        // 单线程耗时5秒
        // call(i);
        // 多线程
        pthread_create(&thread_ids[i], NULL, thread, NULL);
    }
    for (int i=START; i<END; i++) {
        // 单线程耗时5秒
        // call(i);
        // 多线程
        pthread_join(&thread_ids[i], NULL);
        // pthread_create(&thread_ids[i], NULL, thread, NULL);
    }
    clock_t main_end = clock();
    printf("总耗时: %u\n", main_end - main_start);
    for (int i=0; i<END-START; i++) {
        printf("result[%d] = %d\n", i, result[i]);
    }
};
