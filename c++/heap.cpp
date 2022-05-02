#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void print(vector<int> heap) {
  for (auto i=heap.begin(); i!=heap.end(); i++) {
    cout << *i << ",";
  };
  cout << endl;
};


int main() {
  vector<int> heap = {
    4,
    2, 1,
    3
  };
  print(heap);
  make_heap(heap.begin(), heap.end());
  cout << "排heap后\n";
  print(heap);
  pop_heap(heap.begin(), heap.end());
  cout << "pop_head后\n";
  heap.pop_back();
  print(heap);
};

