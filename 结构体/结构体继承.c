#include <stdio.h>


struct Animal {
    int age;
};

struct Person {
    struct Animal father;
    char name;
};

int main() {
    struct Person a;
    a.father.age = 1;
    printf("当前年纪: %d\n", a.father.age);
    printf("指针: %p\n", &a);
    printf("Person 指针 + 1: %p\n", &a + 1);
    struct Animal *f = (struct Animal *) &a;
    printf("强转animal后的指针: %p\n", f);
    f->age = 2;
    printf("强转animal后的指针 + 1: %p\n", f + 1);
    printf("强转后person的age: %d\n", a.father.age);
    unsigned long x = (unsigned long) &a;
    printf("unsigned long的尺寸: %llu\n", sizeof(x));
    printf("强转成unsigned long: %llu\n", x);
    printf("强转成unsigned long + 1: %llu\n", x + 1);
}
