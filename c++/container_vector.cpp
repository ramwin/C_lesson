#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::vector<int> list1 = {1, 2,3, 4};
  std::vector<int> list2 = list1;
  cout << list2[0] << endl;
  list1[0] = 3;
  cout << list2[0] << endl;
};

