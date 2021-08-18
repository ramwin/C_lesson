#include <stdio.h>
// int main1() {
//     char a[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
//     printf("输出: %s \n", a);
//     printf("输出: %lu \n", a[0]);
//     printf("%lu", sizeof(1));
//     printf("size of a0 : %lu\n", sizeof(a[0]));
//     printf("size of a : %lu\n", sizeof(a));
//     printf("a变量大小: %lu \n", sizeof(a));
//     return 0;
// }

int main() {
    char arr[5] = { 'H', 'e', 'l', 'l', 'o'};
    printf("%s\n", arr);
    printf("double: %lu\n", sizeof(double));
    printf("double: %lu\n", sizeof(float));
    int a;
    a += 1;
    // int a
    printf("a: %d\n", a);
    return 0;
}
