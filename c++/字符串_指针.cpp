#include <stdio.h>
#include <iostream>

using namespace std;


void test1() {
  // 同一个字符串，地址是从小编到大的. 注意p1的地址和字符串的地址是不一样的
  printf("测试一个字符串\n");
  const char* p1 = "aaaaa";
  printf("p1地址是: %p\n", &p1);
  printf("字符串的地址是: %p\n", p1);
  printf("pt+1的地址是: %p, 字符是%c\n", &p1[1], p1[1]);  // p1[1]获取的是p1指针地址+1对应的元素. &p1[1] 就是该元素的地址
  printf("p1+1的地址是: %p, 字符是%c\n", p1+1, *(p1+1));  // p1 + 1 获取的是p1指针地址+1对应的地址， *(p1+1) 就是该地址对应的元素
};


void test2() {
  printf("==========测试2个字符串的地址============\n");
  const char* p1 = "bbbbbbbbbb";
  const char* p2 = "12345678901234567890";
  const char* p3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  printf("p1的地址是: %p\n", p1);
  printf("p2的地址是: %p\n", p2);
  printf("p3的地址是: %p\n", p3);
  int p2_p1 = (p2 - p1);
  int p3_p2 = (p3 - p2);
  printf("p2地址(长20)比p1(长10)多: %d\n", p2_p1);
  printf("p3地址(长30)比p2(长20)多: %d\n", p3_p2);
  printf("函数内部，是按照前面的变量占用小地址， 后面的用大地址，p2_p1=11, 因为p1有10个字符,加空字符结尾。 为什么p3-p2=28呢\n");
}

void test3() {
  printf("=============测试字符串越界=============\n");
  const char* p1 = "abcdefghij";
  const char* p2 = "0123456789";
  for (int i = 0; i<=30; i++) {
    printf("p1[%d] = %c\n", i, p1[i]);
  }
  printf("=============不仅越界了，还把p1[%%d] = 打印出来了\n");
}

void test4() {
  // 果然，遇到\0就停止输出了
  printf("============我手动加一个\0==========\n");
}


int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
