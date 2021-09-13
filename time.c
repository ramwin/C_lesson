#include <time.h>
#include <stdio.h>
#include <string.h>

int main() {
    // 1. 直接获取时间
    size_t t;
    t = time(NULL);
    printf("t当前是: %d\n", t);

    // 2. 获取时间对象
    time_t rawtime;
    time_t another;
    struct tm *info;  // info 指向tmp的指针
    another = time(&rawtime);  // 因为指针传递进去了，所以这个变量直接被修改了
    printf("another: %d\n", another);
    printf("rawtime当前是: %d\n", rawtime);
    info = localtime(&rawtime);  // gmtime
    printf("当前时间 %d:%d:%d\n", info->tm_hour, info->tm_min, info->tm_sec);
}
