#include <stdio.h>


int foo(int x) {
    return x + 1;
};

int fibonacci(int x) {
    if (x <= 2) {
        return 1;
    } else {
        return fibonacci(x-2) + fibonacci(x-1);
    };
};

int main(int argc, char *argv[]) {
    printf("the_number_or_argc_is: %d\n", argc);
    // for (int i=0; i<argc; i++) {
    //     printf("the %d parameter is %s\n", i, argv[i]);
    // }
    foo(argc);
    return 0;
};
