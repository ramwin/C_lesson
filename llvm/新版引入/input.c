#define student_cnt 10000


int array[student_cnt];

// void init() {
//   for (int i=0; i<student_cnt; i++) {
//     array[i] = i;
//   };
// };

// int main() {
//   init();
//    int total=0;  // %2 total的地址
//    int upper = student_cnt-200;  // %3
//    for (int i=1024; i<upper; i++) {  // i %4
//      total += array[i];  // %15 = %2 + %12 %12就是array[i]的地址.
//    }
//    return 0;
// }


int g = 1024;

int main() {
  // block0 %1=0 %2 =0
  // 循环是br3
  for (int i=0; i<100; i++) {
    g+=i; // %8 = i32* @g; %9 = %8 + %7;  store i32 %9, i32* @g
  }
  // 
  return g - 4950;  // 结果是%15 = %14 - 4950
}
