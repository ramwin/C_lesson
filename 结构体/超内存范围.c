#include <stdio.h>



struct Person {
    int id;
    int age;
    int large[1024 * 1024];
};


int add(int x, int y) {
    int d = 9;
    printf("x(%d)地址: %p\n", x, &x);
    printf("y(%d)地址: %p\n", y, &y);
    printf("d(%d)地址: %p\n", d, &d);
    return x + y;
};


int test() {
    // add(a, b);
    int a = 0;
    int b = 18;
    struct Person *person;
    printf("a(%d)地址: %p\n", a, &a);
    printf("b(%d)地址: %p\n", b, &b);
    person = &a;
    printf("person地址: %p\n", person);
    printf("person.id: %d\n", person->id);
    printf("person.age: %d\n", person->age);
    person->age = 32;
    printf("person.age = 32 后， b从18变了(%d)地址: %p\n", b, &b);
};

int test1(int age, int id) {
    printf("测试超出内存范围");
    struct Person *person;
    person = &age;
    printf("person.age: %d\n", person->age);
    printf("person.id: %d\n", person->id);
    int y = 1024 * 1024 - 1;
    printf("id的地址: %p\n", &id);
    printf("age的地址: %p\n", &age);
    printf("y的地址: %p\n", &y);
    person -> large[y] = 32;
    printf("y对应元素地址: %p\n", &person->large[y]);
    printf("person.large[%d]: %d\n", y, person->large[y]);
};

int main() {
    struct Person person;
    printf("结构体内部内存地址排序:\n age: %p\n, id: %p\n", &person.age, &person.id);
    test();
    test1(18, 3);
}
