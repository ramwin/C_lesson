#include <stdio.h>

// 读一个文件
int read() {
    FILE *f = fopen("123.txt", "r");
    int c = fgetc(f);
    char d = fgetc(f);
    printf("读取一个字符%c\n", c);
    printf("读取第二个字符%c\n", d);
    printf("当前读到了%d\n", ftell(f));
    fclose(f);
    return 0;
};

int readall() {
    FILE *f = fopen("123.txt", "r");
    char buff[255];
    fgets(buff, 255, f);
    printf("读取了字符串: %s\n", buff);
    printf("当前读到了%d\n", ftell(f));
}

int main() {
    read();
    readall();
    return 0;
};
