#include <stdio.h>
#include <iostream>

using namespace std;


class Person {
  public:
    int age;
};


int main() {
  Person alice, bob;
  alice.age = 19;
  bob = alice;
  alice.age = 20;
  printf("BOB现在还是%d岁\n", bob.age);
  printf("但是ALICE现在%d岁了\n", alice.age);
};

