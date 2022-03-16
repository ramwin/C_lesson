#include <stdio.h>

// 读一个文件
void read() {
    FILE *f = fopen("123.txt", "r");
    int c = fgetc(f);
    char d = fgetc(f);
    printf("读取一个字符%c\n", c);
    printf("读取第二个字符%c\n", d);
    printf("当前读到了%d\n", ftell(f));
    fclose(f);
};

void readall() {
    FILE *f = fopen("123.txt", "r");
    char buff[255];
    fgets(buff, 255, f);
    printf("读取了字符串: %s\n", buff);
    printf("当前读到了%d\n", ftell(f));
};

void seek(){
    FILE *f = fopen("123.txt", "r");
    fseek(f, -1, SEEK_END);
    char end = fgetc(f);
    fseek(f, 0, SEEK_SET);
    char first = fgetc(f);
    printf("第1比特是: %c\n", first);
    fseek(f, 1, SEEK_CUR);
    char third = fgetc(f);  // 返回当前的位置
    printf("第%d比特是: %c\n", ftell(f), third);
    printf("最后一个比特是: %c(大概是换行符吧)\n", end);
};

int main() {
    read();
    readall();
    seek();
    return 0;
};
