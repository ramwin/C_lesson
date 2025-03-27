#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define student_cnt 10000

struct {
  int a[1000];
  int age;
} typedef Student;

Student students[student_cnt];

void init() {
  for (int i=0; i<student_cnt; i++) {
    students[i].age = i;
  };
};

double foo(double x) {
  for (int i=0; i<=4; i++) {
    x = cos(sin(x + 2));
  };
  return x;
};

int main() {
  printf("Student的字节数: %lu\n", sizeof(Student));
  init();
  clock_t start_t, end_t;
  sleep(1);
  start_t = clock();
  double total_age = 0;
  for (int i=0; i<student_cnt-200; i++) {
    // __builtin_prefetch(&students[i+30].age);
    total_age += foo((double)students[i].age);
  };
  end_t = clock();
  printf("total_age现在是 %f\n", total_age);
  printf("耗时: %lu\n", end_t - start_t);
}
