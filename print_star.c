#include <stdio.h>

void print_star(int x) {
    int row_max = x;
    int column_max = 2 * row_max - 1;
    for (int row=1; row<=row_max; row++) {
        for (int column=1; column<=x-row; column++) {
            printf(" ");
        }
        for (int column=x-row+1; column<x+row; column++) {
            printf("*");
        }
        printf("\n");
    }
};

int main() {
    print_star(4);
    print_star(40);
};

