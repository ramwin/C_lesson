#include <stdio.h>
#include <stdlib.h>


static int static1[30000];
int ram[30000] = {0};
static int static2[30000];


void test() {
    int i;
    char *string0 = malloc(1000);
    char *string2 = malloc(1000);
    printf("test函数的      \t%p\n", &test);
    printf("ram的地址       \t%p\n", ram);
    printf("static1的地址   \t%p\n", static1);
    printf("static2的地址   \t%p\n", static2);
    printf("堆1的           \t%p\n", string0);
    printf("后申请的地址大  \t%p\n", string2);
    printf("栈的            \t%p\n", &i);
    printf("栈的            \t%p\n", &string2);
};

int main() {
    test();
};

