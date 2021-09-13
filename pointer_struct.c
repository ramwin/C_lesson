#include <string.h>
#include <stdio.h>


struct Student
{
    int age;
    char name[100];
    double weight;
};

int main() {
    struct Student *p;
    double *z;
    int *i;
    Student student;
    student.age = 18;
    strcpy(student.name, "ramwin");
    student.weight = 51.9;
    strcpy(student.name, "alice");
    printf("student.name %s\n", student.name);
    p = &student;
    printf("double %d\n", sizeof(double));
    printf("int %d\n", sizeof(int));
    printf("char %d\n", sizeof(char));
    printf("所以student的尺寸是: %d\n", sizeof(double) + sizeof(int) + 100 * sizeof(char));
    printf("p %d\n", p);
    printf("p+1 %d\n", p+1);
    z = &student.weight;
    i = &student.age;
    printf("student.weight的指针是: %d\n", z);
    printf("student.age的指针是(多了104哦): %d\n", i);
    printf("student.age (p->age): %d\n", p->age);
}
