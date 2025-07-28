#include <stdio.h>
#include <iostream>

using namespace std;


class Person
{
  public:
    int age;
    Person( int value)
    {
      age ++;
      cout << "初始化Person" << endl;
      age = value;
    }
};

class Student: public Person
{
  public:
    Student(double height, int age): Person(age)
    {
      cout << "初始化学生" << age << endl;
      height = height;
    }
};


int main() {
  Student a = Student(1.1, 2);
  cout << a.age << endl;
};
