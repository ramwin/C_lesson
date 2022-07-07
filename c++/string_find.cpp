#include <stdio.h>
#include <iostream>

using namespace std;


int main() {
  string s = "2345634";
  int index = s.find("34", 3);
  cout << index << endl;
  cout << (s.find("a") == string::npos) << endl;
};

