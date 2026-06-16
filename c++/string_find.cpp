#include <stdio.h>
#include <iostream>

using namespace std;


void test1() {
  string s = "2345634";
  int index = s.find("34", 3);
  cout << index << endl;
  cout << (s.find("a") == string::npos) << endl;
};

void test2() {
  // string::npos其实是 18446744073709551615 全为1(64个)的数字
  cout << string::npos << endl;
};

int main() {
  test2();
};
