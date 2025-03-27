#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define STUDENT_CNT 10000

struct {
  int a[1000];
  int age;
} typedef Student;

Student students[STUDENT_CNT];

void init() {
  for (int i=0; i<STUDENT_CNT; i++) {
    students[i].age = i;
  };
};

int foo(int x) {
  for (int i=0; i< 100; i++) {
    x = (x * x) % 65579;
  };
  return x;
};

int main() {
  printf("Student的字节数: %lu\n", sizeof(Student));
  printf("foo(3) = %d\n", foo(3));
  init();
  clock_t start_t, end_t;
  sleep(1);
  start_t = clock();
  int total_age = 0;
  for (int i=0; i<STUDENT_CNT; i++) {
    // 有预取耗时2256, 没预取耗时2889
    // __builtin_prefetch(&students[i+1].age);
    total_age += foo(students[i].age);
  };
  end_t = clock();
  printf("total_age现在是 %d\n", total_age);
  printf("耗时: %lu\n", end_t - start_t);
}
