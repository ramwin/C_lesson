#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;


int main() {
  std:array<int, 10> list = {1, 2, 3, 4, 5, 9, 8, 7, 6};
  sort(list.begin(), list.end());
  for (int i = 0; i < 9; i++) {
    cout << list[i] << endl;
  }
};
