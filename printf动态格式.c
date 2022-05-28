#include <stdio.h>

int main(int argc) {
    argc = argc * 100;
    printf("argc = %d\n", argc);
    char chars[argc*4];
    for (int i=0; i<argc; i++) {
        chars[3*i] = '%';
        chars[3*i+1] = 'd';
        chars[3*i+2] = ' ';
    };
    printf(chars, 1, 2, 3);
    return '0';
};
