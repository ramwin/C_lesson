#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;


void basic() {
  set<int> a;
  a.insert(2);
  cout << "a.insert(3).second: " << a.insert(3).second << endl;  // 1
  cout << "a.insert(3).second: " << a.insert(3).second << endl;  // 0
  cout << "a.erase(1): " << a.erase(1) << endl;  // 0
  cout << "a.erase(3): " << a.erase(3) << endl;  // 1
  cout << "a.size(): " << a.size() << endl;  // 1
}

int main() {
  basic();
}
