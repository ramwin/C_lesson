#include <stdio.h>
#define A 1;

int foo() {
  return A;
}
int simple() {
    printf("yes");
    return 0;
};

int complicate() {
    printf("no");
    return 32435;
};

int main() {
  int a = foo();
  int b;
  if (a>=60) {
    b = simple();
  } else {
    if (a > 50) {
      b = complicate();
    } else {
      b = complicate() + 1;
    }
  }
  return b;
}
