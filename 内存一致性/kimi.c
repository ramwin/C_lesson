#include <stdio.h>
#include <pthread.h>

static long COUNT = 10000;

#define debug 0

typedef struct 
{
    pthread_mutex_t lock;
    long value;
} NODE;

NODE data[2];

void *my_add_func(void *args){
    NODE *mydata = (NODE *)args;
    for(long i = 0; i < COUNT; i++){
#if debug
        printf("线程%d变更为%ld; ", (long int)args, mydata->value);
#endif
        pthread_mutex_lock(&mydata->lock);
        mydata->value += i;
#if debug
        printf("线程%d变更为%ld\n", (long int)args, mydata->value);
#endif
        pthread_mutex_unlock(&mydata->lock);
    }
    return NULL;
}

int main(){
    int thread_num = 2;
    pthread_t pt[thread_num];
    for(int i = 0; i < thread_num; i++){
        pthread_mutex_init(&data[i].lock, NULL);
        pthread_create(&pt[i], NULL, my_add_func, (void *)&data[i]);
    }
    for(int i = 0; i < thread_num; i++){
        pthread_join(pt[i], NULL);
        pthread_mutex_destroy(&data[i].lock);
    }

    for (long i=0; i<2; i++) {
        printf("%ld\n", data[i].value);
    }
    
    return 0;
}
