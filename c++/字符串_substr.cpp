#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
  string before = "before";
  string after = before.substr(0, 6);
  cout << after << "\n";
  printf("%s %p\n", before.c_str(), before.begin());
  printf("%s %p\n", after.c_str(), after.begin());
  after = "after";
};

