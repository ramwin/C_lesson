#include <iostream>

using namespace std;

template <typename T> T add(T a, T b) {
  return a + b;
};

int main() {
  int (*p)(int, int);
  p = add<int>;

  int (*q)(int, int);
  q = add<int>;

  // return p(1, 2) + q(1, 2);
  cout << p(1, 2) << endl;
  cout << q(1, 2) << endl;
  cout << "add<int>的地址是:" << &p << endl;
  cout << "add<int>的地址是:" << &q << endl;
};
