#include <iostream>
using namespace std;

int main() {
  // 如果是char， 只会读取到前2个字节。中文就乱码
  char c[3];
  char d[4];
  cin >> c >> d;
  cout << "c=" << c << endl;
  cout << "d=" << d << endl;
  return 0;
}
