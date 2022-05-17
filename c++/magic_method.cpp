#include <stdio.h>
#include <iostream>

using namespace std;

class EvenBigger {
  public:
    int num;
    EvenBigger(int num): num(num) {
    };
    bool operator<(EvenBigger another) {
      cout << "比较" << num << " < " << another.num << endl;
      if ((num % 2) == (another.num % 2)) {
        return num < another.num;
      }
      if (num % 2 == 0) {
        return false;
      }
      return true;
    };
};

int main() {
  EvenBigger a(2);
  EvenBigger b(4);
  EvenBigger c(3);
  cout << (a < b) << endl;
  cout << (a < c) << endl;
  cout << (c < b) << endl;
};

