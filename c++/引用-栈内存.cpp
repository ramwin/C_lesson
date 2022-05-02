#include <stdio.h>
#include <iostream>

using namespace std;


int test2(int a) {
  a++;
  cout << "test2中: a的地址是: " << &a << endl;
  return a;
};

int test1(int& a) {
  cout << "a的地址是: " << &a << endl;
  a++;
  a = test2(a);  // 引用内赋值，直接改变地址对应的数据
  return a;
};

int test(int& a) {
  cout << "a的地址是: " << &a << endl;
  test1(a);
  return a;
};

int main() {
  int a = 3;
  cout << "a的地址是: " << &a << endl;
  test(a);
  cout << "a的地址是: " << &a << endl;
  cout << a;
};

