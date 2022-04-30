#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char a = ' ';
  cout << std::isspace(a) << endl;
  a = '\n';
  cout << std::isspace(a) << endl;
  a = '\t';
  cout << std::isspace(a) << endl;
  a = '\r';
  cout << std::isspace(a) << endl;
  a = '\v';
  cout << std::isspace(a) << endl;
  a = '\f';
  cout << std::isspace(a) << endl;
  char b = 'a';
  cout << std::isspace(b) << endl;
};

