#include <stdio.h>



int main() {
  int a = 7;
  int g[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
  for (int i=0; i<10; i++) {
    g[i] += a;
    printf("%d, ", g[i]);
  };
  printf("\n");
  return g[a];
};
