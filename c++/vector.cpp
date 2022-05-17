#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void test1() {
  cout << "反向迭代" << endl;
  vector<char> a { 'a', 'b', 'c', 'd'};
  // a.push_back('a');
  // a.push_back('b');
  // a.push_back('c');
  for (auto i=a.rbegin(); i!=a.rend(); i++) {
    cout << *i;
  }
};


int main() {
    std::vector<int> a;
    a.push_back(3);
    a.push_back(4);
    std::cout << a[0];
    std::cout << a[1];
    test1();
};
