#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;


void print(auto map) {
  for (auto pair: map) {
      cout << pair.first << "=" << pair.second << endl;
  }
};


int test1() {
  // 测试不存在的key, 会输出0
    std::map<int, int> dict;
    dict[1] = 3;
    cout << dict[1] << endl;
    // cout << dict[2] << endl;  // 这个输出0, 并且会导致2被加入dict
    cout << "从dict里面找2: " << dict.count(2) << endl;
    dict[2] = 3;
    cout << "从dict里面找2: " << dict.count(2) << endl;
    print(dict);
    for (int i=0; i<=10000; i++) {
      if (dict[i] != 0) {
        cout << i << endl;
      }
    }
    return 0;
};

int test2() {
  // 测试2个字符串算不算2个key. 算1个key
  std::map<std::string, int> dict;
  std::string str1 = "from";
  std::string str2 = "from";
  dict[str1] = 3;
  cout << (str1 == str2) << endl;
  cout << dict[str2] << endl;
  print(dict);
  return 0;
};


int main() {
  cout << "测试1" << endl;
  test1();
  cout << "测试2" << endl;
  test2();
  return 0;
}
