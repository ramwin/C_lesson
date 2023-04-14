#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
  vector<int> a;
  for (int i=5; i>=0; i--) {
    a.push_back(i);
  }
  vector<int>::iterator index = std::find(a.begin(), a.end(), 3);
  printf("4的位置是: %lu", std::distance(a.begin(), index));
};
