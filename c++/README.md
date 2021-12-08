# 函数

## 输入输出

    std::cout << "c=" << c << std::endl;
    using namespace std;
    cout << "c=" << c << endl;

## Lambda 函数与表达式

    [](int x, int y){ ++global_x; }
    [](int x, int y){ return x < y; }
    [](int x, int y) -> int { int z = x + y; return z + x; }
    [](int x, int y){ return x + y; }(1, 2)  // 结果是3


## 类

    ```
    class Person {
    public:
        int age;
        int getage() {
          return this->age;
        }
    }
    class Women: public Person
    {
        public:
            int age;
            int getage() {
              return this->age - 1;
            }
    }
    ```

## [模板](https://www.runoob.com/cplusplus/cpp-templates.html)
模板设置参数后＝》模板函数  
模板函数再次编译后才能调用  
