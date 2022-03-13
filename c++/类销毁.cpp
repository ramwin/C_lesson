#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

struct B
{
  B() { cout << "创建了B\n"; }
  ~B() { cout << "销毁了B\n"; }
};


int main() {
  cout << "main\n";
  struct B b;
  cout << "有创建吗\n";
};
