#include <iostream>
using namespace std;

int main (){
  int a = 5;
  cout << "调用main函数" << "\n";

  int *b;
  b = &a;

  int &c = a;

  cout << "a的地址是" << &a << "\n";
  cout << "b的地址是" << &b << "\n";
  cout << "c的地址是" << &c << "\n";

  *b += 1;
  c += 1;

  cout << a << "\n";

  cout << "a的地址是" << &a << "\n";
  cout << "b的地址是" << &b << "\n";
  cout << "c的地址是" << &c << "\n";
}
