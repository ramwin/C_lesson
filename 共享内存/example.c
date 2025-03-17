#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int          fd;
    char         *addr;
    char         result;
    size_t       length;

    fd = open(argv[1], O_RDONLY);
    length = 1024 * 1024 * 1024;
    addr = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0);
    printf("读取了内存: %c\n", addr[0]);
    // write(STDOUT_FILENO, addr, length);
    for (int i=0; i<length; i+=12) {
        result = addr[i];
    }
    scanf("读入");
    munmap(addr, length);
    close(fd);
    exit(EXIT_SUCCESS);
}
