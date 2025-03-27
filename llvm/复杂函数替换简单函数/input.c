#include <stdio.h>

int simple() {
    printf("yes");
    return 0;
};

int complicate() {
    printf("no");
    return 32435;
};

int main() {
    int b = complicate();
    printf("b当前是: %d\n", b);
    return b;
}
