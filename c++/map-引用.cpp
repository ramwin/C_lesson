#include <stdio.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;


struct Student {
  int id;
  char name[32];  // 32+4=36, 最后没有额外的\0
  int age;
  set<int> friends;
};

map<int, Student> students;

void test_copy() {
  // 直接使用 = 会把结构体全部拷贝过来
  cout << sizeof(struct Student) << endl;
  struct Student alice;
  cout << "alice的地址\t" << &alice << endl;
  cout << "alice的地址+1\t" << &alice + 1 << endl;
  cout << "alice的id地址\t" << &alice.id << endl;
  cout << "alice的id地址+1\t" << &alice.id + 1 << endl;
  cout << "alice的friends地址\t" << &alice.friends << endl;
  students[alice.id] = alice;  // alice的添加是复制了所有信息;
  cout << "students的地址\t" << &students[alice.id] << endl;
  cout << "students的friends地址\t" << &students[alice.id].friends << endl;
  alice.friends.insert(3);
  cout << "alice insert后 students的friends没变" << endl;
  cout << "alice的size\t" << alice.friends.size() << endl;
  cout << "friends的size\t" << students[0].friends.size() << endl;
};

int main() {
  test_copy();
};
