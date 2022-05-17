#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int main() {
  void* x;
  vector<int> list;
  x = &list;
  // vector<int> list2;
  cout << "x的地址是: " << &x << endl;
  cout << "x的值是: " << x << endl;
  cout << "list的地址是: " << &list << endl;
  vector<int> *list3;
  list3 = &list;
  cout << "list3的值是: " << list3 << endl;
  list3->push_back(3);
  cout << list.size() << endl;
};
