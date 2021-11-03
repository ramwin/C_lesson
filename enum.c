#include <stdio.h>
enum DAY {
    mon=1,
    tue,
    wed,
};

int main() {
    enum DAY day;
    day = wed;
    printf("enum字节数%lu\n", sizeof(DAY));
    printf("星期%d", day);
    return 0;
}
