#include <stdio.h>


int get_stack_addr() {
    int x = 7;
    printf("栈地址: %d\n", &x);
    return 0;
};


int main() {
    get_stack_addr();
    int x = 1;
    printf("x的地址是: %d\n", &x);
    get_stack_addr();
}
