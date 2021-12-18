#include <iostream>
using namespace std;


namespace first_space {
  void func() {
    cout << "第一个命名空间\n";
  }
}

namespace second_space {
  void func() {
    cout << "第二个命名空间\n";
  }
}

int main() {
  first_space::func();
  second_space::func();
}
