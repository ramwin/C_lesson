#include <stdio.h>
#include <memory>
#include "my_class.h"

using namespace std;


int main() {
  {
    int a = 0;
    unique_ptr<Hobby> p = make_unique<Hobby>("打羽毛球");
    p->display();
    unique_ptr<Hobby> q = std::move(p);
    p = make_unique<Hobby>("打乒乓球");
    q->display();
    p->display();
    q = std::move(p);
    q->display();
  }
  {
    double a = 1.1;
    unique_ptr<Student> q = make_unique<Student>("amy");
    q->display();
  }
};
