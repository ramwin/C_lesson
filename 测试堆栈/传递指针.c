#include <stdio.h>

void foo(int *x) {
  printf("传入的x的地址是: %p\n", &x);
  printf("x的值是: %p\n", x);
  (*x)++;
};

int main() {
  int a = 1;
  // 这个地方把a的地址当操作参数传给了x. 所以会需要栈里面申请地址并拷贝a的地址过去
  foo(&a);
  printf("a的地址是: %p\n", &a);
  printf("a = %d\n", a);
};
