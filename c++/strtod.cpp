#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  const char* p = "11.9";
  const char* q = "1119";
  // double b = strtod(p, nullptr);
  double b = strtod(p, nullptr);
  cout << b << endl;
  return 0;
};

