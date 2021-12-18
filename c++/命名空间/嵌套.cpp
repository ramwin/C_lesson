#include <iostream>

using namespace std;

namespace namespace_namea {
  int a_only = 11;
  int a_b_both = 12;
  namespace namespace_nameb {
    int a_b_only = 21;
    int a_b_both = 22;
  }
}

namespace namespace_namea {
  // int a_only = 11;  // 报错, 同样的命名空间可以理解成代码拼接在一起
  int extra_a = 13;
}

int main() {
  using namespace namespace_namea;
  cout << a_only << endl;
  cout << extra_a << endl;
  cout << namespace_nameb::a_b_only << endl;
}
