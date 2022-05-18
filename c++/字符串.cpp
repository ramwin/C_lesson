#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void test1() {
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
  cout << "字符串的append可能导致重新memalloc" << endl;
};


// 测试字符串的地址
void test2() {
  cout << "测试字符串的地址" << endl;
  string str1 = "";
  for (int i = 0; i<=31; i++) {
    str1.append(1, '*');
    cout << "str1当前长度: " << str1.size() << endl;
    cout << "str1的地址: " << static_cast<const void *>(&str1[0]) << endl;  // 字符串的地址随着长度变化，需要重新Malloc
    cout << "str1的变量地址" << &str1 << endl;  // 变量地址一直不变
  }
};

void test3() {
  // 生成连续多个字符
  string a = string(10, 'a');
  cout << a << a.size() << endl;
};


void test4() {
  string a = "abcd";
  string b = a.substr(1, 2);
  cout << static_cast<const void *>(&a[1]) << endl;
  cout << static_cast<const void *>(&b[0]) << endl;
  cout << b << endl;
};


int main() {
  // test1();
  // test2();
  // test3();
  test4();
  return 0;
};
