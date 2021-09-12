#include <stdio.h>
#include <string.h>
union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;
    data.i = 1;
    printf("data使用的尺寸是%d \n", sizeof(data));
    printf("data.i %d \n", data.i);
    data.i = 2;
    data.f = 1.11;
    printf("data.i %d \n", data.i);
};
