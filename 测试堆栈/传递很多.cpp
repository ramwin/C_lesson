#include <stdio.h>
#include <iostream>

using namespace std;

void foo(int & x) {
  x++;
};


int main() {
  int result;
  for (auto i=0; i<=1000; i++) {
    foo(result);
  };
  return 0;
};

