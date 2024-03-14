#include <stdio.h>

int main() {
    int num = 0x12345678;
    char chData = *(char *)(&num);
    if (chData == 0x12) {
        printf("是大端");
    } else if (chData == 0x78) {
        printf("是小端");
    } else {
        printf("是异端");
    }
};
