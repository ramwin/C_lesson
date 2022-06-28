#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void print(const vector<char>& vec) {
  for (auto x: vec) {
    cout << ' ' << x;
  }
  cout << '\n';
};

void test1() {
  cout << "反向迭代" << endl;
  vector<char> a { 'a', 'b', 'c', 'd'};
  // a.push_back('a');
  // a.push_back('b');
  // a.push_back('c');
  for (auto i=a.rbegin(); i!=a.rend(); i++) {
    cout << *i;
  }
  cout << "\n";
};

void test_modify() {
  vector<char>::iterator pointer;
  vector<char> array {'a', 'b', 'c', 'd'};
  for (pointer=array.begin(); pointer!=array.end(); pointer++) {
    if (*pointer == 'b') {
      cout << "找到B\n";
      break;
    } else {
      cout << "找到了" << *pointer << "\n";
    }
  }
  cout << "插入1之前: pointer=" << *pointer << endl;
  print(array);
  pointer = array.insert(pointer, '1');
  cout << "%p\n" << &pointer << endl;
  cout << "插入1之后: pointer=" << *pointer << endl;
  print(array);
  cout << "size: " << array.size() << endl;
}


int main() {
    std::vector<int> a;
    a.push_back(3);
    a.push_back(4);
    std::cout << a[0];
    std::cout << a[1];
    test1();
    test_modify();
};
