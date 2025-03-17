#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    printf("我还没fork: %d\n", getpid());
    int forkid;
    forkid = fork();
    if ( forkid != 0 ) {
        for (i=1; i<1000; i++) printf("parent process\n");
        printf("我是父进程: %d 生成了子进程 %d\n", getpid(), forkid);
    } else {
        for (i=1; i<1000; i++) printf("child process\n");
        printf("我是子进程: %d - %d\n", getpid(), forkid);
    }
    // 2个进程都会print,都会读stdinout
    printf("输入输出在 %d %d\n", getpid(), forkid);
    // scanf("%d", &i);
    printf("输入输出在 %d %d\n", getpid(), forkid);
};

