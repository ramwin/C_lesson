// https://leetcode-cn.com/problems/reverse-integer/
#include <stdio.h>
int reverse(int x) {
    int y = 0;
    int l = 0;
    while(x) {
        l = x%10;
        x /= 10;
        y = y * 10 + l;
        printf("x现在是: %d\n", x);
    }
    printf("y最后是: %d\n", y);
    return y;
}

int main() {
    int a;
    a = 123;
    printf("转化: %d\n", a);
    reverse(a);
    return 0;
}
