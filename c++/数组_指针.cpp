#include <stdio.h>
#include <iostream>

using namespace std;


int a[4] = {1, 2, 3, 4};

int b[5] = {2, 4, 6, 8, 10};

int *c;

int main() {
  c = b;
  for (int i = 0; i<=4; i++) {
    cout << *(c + i) << endl;
  };
};
