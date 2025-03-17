#include <stdio.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char a[10];
    a[0] = 'A';
    a[1] = 'B';
    int b = open("/tmp/c_file", O_WRONLY);
    write(b, a, 2);
    close(b);
};
