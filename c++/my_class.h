#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    int age;
    string name;
    Student(string name) :name(name) {};
    void hello() {
      cout << "你好，我的名字叫: " << name << "\n";
    };
    void display() {
      cout << "我是学生: " << name << "\n";
    };
    ~Student() {
      cout << "我 [" << name << "] 毕业了\n";
    };
};

class Hobby {
  public:
    string name;
    Hobby(string name) :name(name){
      cout << "爱好: [" << name << "]__init__" << "\n";
    }
    ~Hobby() {
      cout << "失去爱好: [" << name << "]\n";
    }
    void display() {
      cout << "Hobby::display 我是爱好: [" << name << "]\n";
      cout << "我的内存地址: " << &name << "\n";
    }
};
