#include <stdio.h>
#include <iostream>

using namespace std;


void foo(int & x) {
  printf("传入的x的地址是: %p\n", &x);
  x++;
};


int main() {
  int a = 1;
  printf("a的地址是: %p\n", &a);
  // 这个地方时直接用的引用, 不会额外申请栈内存, 所以x的地址就是a的地址. 
  foo(a);
  printf("a = %d\n", a);
};
