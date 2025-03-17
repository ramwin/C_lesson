#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char a[10];
    FILE *f = fopen("123.txt", "r");
    int b = open("/tmp/c_file", O_RDONLY);
    printf("文件句柄: %d\n", b);
    a[0] = 'a';
    a[1] = 'a';
    a[2] = '\x00';
    // read(b, a, 1);
    int r = read(b, a, 1);
    if (r == -1) {
        printf("directory %d %d\n", EISDIR, errno);
        printf("读取失败\n");
    };
    printf("读取结果: %d\n", r);
    // a[0] = fgetc(b);
    printf("%s", a);
};

