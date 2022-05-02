#include <stdio.h>
#include <iostream>

using namespace std;


int test1(int& a) {
  cout << "a的地址是: " << &a << endl;
  a++;
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

