#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    printf("%d\n", getpid());
    scanf("%d", &i);
    printf("%d\n", getpid());
};

