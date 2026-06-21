#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;


int main() {
  map<char, int> a;
  a['a'] = 32;
  a['c'] = -3;
  cout << a.at('a') << endl;
  cout << a['c'] << endl;
};

