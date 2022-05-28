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
  foo(a);
  printf("a = %d\n", a);
};
