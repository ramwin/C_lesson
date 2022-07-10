#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;


void basic() {
  multiset<int> a;
  a.insert(1);
  a.insert(3);
  a.insert(1);
  cout << "size: " << a.size() << endl;
  // a.erase(1);
  a.erase(a.lower_bound(4));
  for(auto &i: a) {
    cout << i << endl;
  }
};


int main() {
  basic();
};
