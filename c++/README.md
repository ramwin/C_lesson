## 输入输出

    std::cout << "c=" << c << std::endl;
    using namespace std;
    cout << "c=" << c << endl;

* 输入
如果是char，输入太多字符会导致只能保存前面的2个字符
```cpp
cin >> a >> b;
```
如果是`char[]`, 会导致内存是连续的
```cpp
char c[3];
char d[4];
cin >> c >> d;
输入123\n456, 输出竟然是123456 456
```

* 输出
```cpp
cout << name;
cerr << 'error';
clog << "log message";
```

* 精度控制
```cpp
cout << fixed << setprecision(4) << <double> << endl;
```

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
