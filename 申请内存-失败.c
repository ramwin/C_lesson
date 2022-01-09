#include <stdlib.h>
#include <stdio.h>

int string1_length = 25;


int main() {
    char *string0 = malloc(2);
    char *string1 = malloc(string1_length);
    char *string2 = malloc(7);
    if (string0==NULL || string1==NULL || string2==NULL)
        printf("申请失败\n");
    else
        printf("申请了string0内存地址0: %p\n", string0);
        printf("  string0[1]的地址: %p\n", &string0[1]);
        printf("  string0[2]的地址: %p\n", &string0[2]);
        printf("申请了内存地址1: %p, %d\n", string1, string1-string0);
        printf("  string1[-1]的地址: %p\n", &string1[string1_length-1]);
        printf("申请了内存地址2: %p, %d\n", string2, string2-string1);
    return 1;
}
