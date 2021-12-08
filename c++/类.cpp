#include <iostream>
#include <stdio.h>

using namespace std;

class Person
{
  public:
    int age;
    int getage() {
      return this->age;
    }
};

// 继承
class Women: public Person
{
  public:
    int getage() {
      return this->age - 1;
    }
};

class Men: public Person
{
  public:
    int getage() {
      return this->age;
    }
};

int main1() {
  Person person;
  person.age = 18;
  Women women;
  women.age = 18;
  Men men;
  men.age = 18;
  cout << "人的年龄: " << person.getage() << endl;
  cout << "女人的年龄:" << women.getage() << endl;
  cout << "男人的年龄:" << men.getage() << endl;
  return 0;
}

int main() {
  return main1();
}

// class Man
// {
//   public:
//     int age;
//     int getage() {
//       return this->age;
//     }
// }


