#include <iostream>

using namespace std;

class Person
{
  public:
    int age;
};

struct Student: Person {
  int grade;
};

int main() {
  Student student;
  student.age = 18;
  student.grade = 3;
  cout << student.grade << endl;
  cout << student.age << endl;
}
