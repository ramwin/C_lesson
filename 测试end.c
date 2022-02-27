#include <stdio.h>

int end() {
    return 3;
};

int _end() {
    return 3;
};

int main() {
    int y;
    y = _end();  // 这样就会报错哦
    printf("y=%d\n", y);
};
