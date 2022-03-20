#include <string>
#include <iostream>

using namespace std;

void rstrip(string &a) {
  a = a.substr(0, a.size() - 1);
  if (a.ends_with("c")) {
    rstrip(a);
  }
};

int main() {
  string str = "abcdefgccc";
  cout << "before: " << "\n";
  cout << str << "\n";
  rstrip(str);
  cout << "after: " << "\n";
  cout << str << "\n";
  return 0;
};

