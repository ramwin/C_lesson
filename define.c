// #include <stdio.h>

// define 一定要加括号
// #define WIDTH 80
// #define LENGTH WIDTH + 10
// gcc -save-temps basic.cpp -o out
// 
// int main() {
//     int var = LENGTH * 20;
//     printf("var = %d\n", var);
// };


// 宏的顺序不一定重要
#define WIDTH LENGTH + 10
#define LENGTH HEIGHT + 10
#define HEIGHT  0


int main() {
    int var = WIDTH;
    // printf("var = %d\n", var);
};
