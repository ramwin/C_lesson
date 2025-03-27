#include <stdio.h>

int cache = 9;
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
    int d = complicate();
    int e = b + d;
    printf("e当前是: %d\n", e);
    printf("cache当前是: %d\n", cache);
    return e;
}
