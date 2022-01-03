#include <stdlib.h>
#include <stdio.h>

int main() {
    char *string0 = malloc(32);
    char *string1 = malloc(64);
    char *string2 = malloc(128);
    if (string0 && string1 && string2)
        printf("申请失败\n");
    else
        printf("申请了内存地址0: %p\n", string0);
        printf("申请了内存地址1: %p\n", string1);
        printf("申请了内存地址2: %p\n", string2);
    return 1;
}
