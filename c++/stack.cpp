#include <stdio.h>
#include <stack>

using namespace std;


void test1() {
    printf("基础用法\n");
    stack<int> a;
    a.push(3);
    a.push(4);
    printf("插入3,4后, 长度为: %lu\n", a.size());
    int b = a.top();
    printf("使用top拿到顶部数据 %d\n", b);
    a.pop();
    printf("pop后, 长度为: %lu\n", a.size());
};


int main() {
  test1();
};
