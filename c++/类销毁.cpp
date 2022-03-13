#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

struct B
{
  B() { cout << "创建了B\n"; }
  ~B() { cout << "销毁了B\n"; }
};

class Hobby {
  public:
    string name;
    Hobby(string name) :name(name){
      cout << "哎呀，你喜欢上了" << name << "\n";
    };
    ~Hobby() {
      cout << "哼，你不再喜欢" << name << "\n";
    };
};


int main() {
  cout << "main\n";
  struct B b;
  cout << "有创建吗\n";
  Hobby h("羽毛球");
  cout << "当前的喜好: " << h.name << "\n";
};
