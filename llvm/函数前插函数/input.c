#include <stdio.h>

int simple() {
    printf("yes");
    return 7;
};

int complicate() {
    printf("no");
    return 7;
};

int main() {
    int b = complicate();
    return b;
}
