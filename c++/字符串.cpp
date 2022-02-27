#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1 = "runoob";
  string str2 = "google";
  string str3;
  // string的sizeof是指针的size. .size是字符串的长度
  cout << "string的size: " << sizeof(str1) << " != string.size: " << str1.size() << endl;
  str3 = str1;
  cout << sizeof(str3) << endl;
  cout << "str1的第一个字母: " << str1[0] << endl;
  cout << "str3的第一个字母: " << str1[0] << endl;
  char *a;
  cout << "str1的第一个字母地址: " << static_cast<const void *>(&str1[0])  << endl;
  cout << "str3的第一个字母地址: " << static_cast<const void *>(&str3[0]) << endl;
  cout << "字符串赋值会把字符复制过去" << endl;
  for (int i = 0; i<=100; i++) {
    str1.append(1, '*');
    cout << "str1当前长度: " << str1.size() << endl;
    cout << "str1的地址: " << static_cast<const void *>(&str1[0]) << endl;
  }
  cout << "字符串的append可能导致重新memalloc" << endl;
};
