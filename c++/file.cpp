#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void read() {
  string a;
  ifstream infile;
  infile.open("123.txt");
  infile >> a;
  cout << "读取了" << a << endl;
  cout << a.size() << endl;
};

int main() {
  read();
};
