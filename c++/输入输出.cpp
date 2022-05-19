#include <iostream>
using namespace std;

void test_sscan() {
  char input[] = "25 54.32E-1 Thompson 56789 0123";
  int a;
  float b;
  char c[10];
  std::sscanf(input, "%d%f%9s", &a, &b, &c);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
};

int main() {
  test_sscan();
}
