#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>
#define size 20000000
/*
 * 测试不同cacheline对应的速率
 * 结果
 * 同一个cacheline的单线程读写速度为 600+
 * 循环的读写速度为(总是cachemiss)   82+
 * 双线程对2个cacheline同时操作的速度(2个线程不抢占cacheline) 270+
 * 双线程对同一个cacheline的操作速度(2个线程总是抢占cacheline) 119+
 * */

struct Student1 {
    int age;
    char name[28];
};

struct Student2 {
    int age;
    char name[60];
};

struct Student1 students1[size];
struct Student2 students2[size];

void test_cache() {
    printf("让每个student增加1岁\n");
    clock_t start, end;
    start = clock();
    for (int i=0; i<size; i++) {
        students1[i].age = i;
    }
    end = clock();
    printf("%lu字节的循环速率为: %ld(%ld -> %ld)\n",
            sizeof(struct Student1),
            size / (end - start),
            start, end
            );

    start = clock();
    for (int i=0; i<size; i++) {
        students2[i].age = i;
    }
    end = clock();
    printf("%lu字节的循环速率为: %ld(%ld -> %ld)\n",
            sizeof(struct Student2),
            size / (end - start),
            start, end
            );
};


void *test_thread2(void *arg) {
    // 对64字节的数据进行双线程循环循环
    clock_t start, end;
    int start_index = *(int *)arg;
    printf("从数字: %d 开始执行\n", start_index);
    start = clock();
    for (int i=start_index; i<size; i++) {
        students2[(start_index + 1) % 2].age += i;
    }
    end = clock();
    printf("%lu字节的循环速率为: %ld(%ld -> %ld)\n",
            sizeof(struct Student2),
            size / (end - start),
            start, end
            );
};


void *test_thread(void *arg) {
    // 对32字节的数据进行双线程循环循环
    clock_t start, end;
    int start_index = *(int *)arg;
    if (start_index == 1) {
        start_index = 0;
    }
    printf("从数字: %d 开始执行\n", start_index);
    start = clock();
    for (int i=start_index; i<size; i++) {
        students1[(start_index + 1) % 2].age += i;
    }
    end = clock();
    printf("%lu字节的循环速率为: %ld(%ld -> %ld)\n",
            sizeof(struct Student1),
            size / (end - start),
            start, end
            );
};


int main() {
    clock_t start, end;
    printf("Student1的size应该是32: %lu\n", sizeof(struct Student1));
    printf("Student2的size应该是64: %lu\n", sizeof(struct Student2));
    pthread_t thread_ord, thread_even;
    int index_0=0;
    int index_1=1;
    /*
     * 当单线程执行时,因为32size的student会进入cache,所以速度很快,64比较慢
     * */
    test_cache();
    /*
     * 多线程执行时,因为32size的student会进入cache,导致2个cpu互相抢占内存, 我觉得理论上64字节应该更快,但实际上不是. 不知道为什么
     * */
    start = clock();
    pthread_create(&thread_even, NULL, &test_thread, (void *)&index_0);
    pthread_create(&thread_ord,  NULL, &test_thread, (void *)&index_1);
    pthread_join(thread_even, NULL);
    pthread_join(thread_ord,  NULL);
    end = clock();
    printf("32字节的内存互相读写的耗时: %ld\n", end - start);

    start = clock();
    pthread_create(&thread_even, NULL, &test_thread2, (void *)&index_0);
    pthread_create(&thread_ord,  NULL, &test_thread2, (void *)&index_1);
    pthread_join(thread_even, NULL);
    pthread_join(thread_ord,  NULL);
    end = clock();
    printf("64字节的内存互相读写的耗时: %ld\n", end - start);

    /* 看看有没有数据冲突, 结果没有 */
    for (int i=0; i<10; i++) {
        printf("%d %d %d\n", i, students1[i].age, students2[i].age);
    }
    return 0;
    for (int i=0; i<size; i++) {
        if (students1[i].age != i * 2) {
            printf("数据冲突,报错\n");
            break;
        }
    }
    for (int i=0; i<size; i++) {
        if (students2[i].age != i * 2) {
            printf("数据冲突,报错\n");
            break;
        }
    }
    /* 我如何能允许内存写入不一致呢 */
};
