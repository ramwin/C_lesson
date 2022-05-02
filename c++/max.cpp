#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
  vector<int> list{1, 2, 3};
  cout << *max_element(list.begin(), list.end()) << endl;
};

