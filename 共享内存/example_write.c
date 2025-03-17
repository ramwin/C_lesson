#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int          fd;
    char         *addr;
    size_t       length;

    fd = open(argv[1], O_RDWR | O_CREAT, 0664);
    length = 1024 * 1024 * 1024;
    // length = 1024;
    printf("文件打开了\n");
    printf("mmap前: %p\n", addr);
    addr = mmap(NULL, length,
            PROT_WRITE|PROT_WRITE,
            MAP_SHARED, fd, 0);
    printf("mmap完成: %p\n", addr);
    printf("mmap结果: %d\n", errno);
    addr[4] = 'Y';
    // printf("读取了内存: %s\n", addr);
    // write(STDOUT_FILENO, addr, length);
    int linesize = 12;
    int line_count = length / linesize;
    int step = 2;  // 每63字节写入一次
    for (int i = 0; i<line_count; i++) {
        addr[linesize * i] = 'f';
        addr[linesize * i + linesize - 1] = '\n';
    };
    scanf("敲击回车结果");
    munmap(addr, length);
    close(fd);
}
