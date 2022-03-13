#include <stdio.h>
#include "my_class.h"
#include <memory>
#include <cassert>
#include <list>
#include <vector>


void display(string name, vector<int> &x) {
  cout << name << "的地址是: " << &x << endl;
  cout << name << "[0]的地址是: " << &x[0] << endl;
  cout << name << "[0] = " << x[0] << endl;
}


void normal() {
  cout << "========nomal=========\n";
  auto a = std::vector<int>(3, 2);
  auto b = a;
  display("a", a);
  display("b", b);
  cout << "一开始,a,b,a[0], b[0]地址都不一样" << endl;
  b[0] = 52;
  display("a", a);
  display("b", b);
  cout << "b[0]修改后，a不变\n";
};

void move() {
  cout << "======move========\n";
  std::vector<int> a = std::vector<int>(3, 2);
  display("a", a);
  std::vector<int> b = move(a);
  b[0] = 52;
  display("b", b);
  cout << "使用move的话, a的地址竟然变成了b的地址。b地址和a不一样，但是b的元素地址和a一致\n";
  display("a", b);
};

int main() {
  normal();
  move();
};
