struct Person {
    char name[30];
    int age;
    int id;
};

int main() {
    struct Person person = {"张三", 18, 1};
    printf(person.name);
    return 0;
};
