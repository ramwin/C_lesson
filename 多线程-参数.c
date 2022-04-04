#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>
#include <stdio.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
int a = 8;


typedef struct thread_arguments {
    int id;
    char *msg;
} thargs_t;

void *myThreadFun(void *vargp)
{
    printf("调用myThreadFun\n");
    thargs_t *param = (thargs_t *)vargp;
    printf("转化完毕\n");
    printf("%d\n", param->id);
    printf("%s\n", param->msg);
    sleep(1);
    return NULL;
}

void test() {
    // 测试有参数
    pthread_t thread_id;
    thargs_t param;
    param.id = 8;
    param.msg = (char *)"Hello World";
    pthread_create(&thread_id, NULL, myThreadFun, &param);
    param.id = 18;
    param.msg = (char *)"Hello World2";
    pthread_create(&thread_id, NULL, myThreadFun, &param);
    pthread_join(thread_id, NULL);
}

void basic()
{
    clock_t start = clock();
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    clock_t end = clock();
    exit(0);
}

int main() {
    test();
    return 0;
}
