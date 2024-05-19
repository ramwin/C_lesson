#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>
 
atomic_int acnt;
int cnt;
 
int f(void* thr_data)
{
    // 虽然能保证++是原子的，但是返回数据的时候不一定是只加了1
    int cache, minus;
    for(int n = 0; n < 10000; ++n) {
        ++cnt;
        cache = acnt;
        minus = ++acnt - cache;
        if (minus != acnt) {
            printf("不一样的数字\n");
        }
        // for this example, relaxed memory order is sufficient, e.g.
        // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);
    }
    return 0;
}
 
int main(void)
{
    // 多线程操作int类型会有冲突。atomic_int类型不会有冲突
    thrd_t thr[10];
    for(int n = 0; n < 10; ++n)
        thrd_create(&thr[n], f, NULL);
    for(int n = 0; n < 10; ++n)
        thrd_join(thr[n], NULL);
 
    printf("The atomic counter is %u\n", acnt);
    printf("The non-atomic counter is %u\n", cnt);
}
