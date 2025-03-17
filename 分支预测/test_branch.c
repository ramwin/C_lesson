#include <stdio.h>

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)


int main() {
    int result = 0;
    int end;
    scanf("%d", &end);
    for (int i=0; i<end; i++) {
        // 默认是unlikely
        if (i % 19 == 0) {
            result++;
        } else {
            result = result * 7;
        }
    }
    return result;
};
