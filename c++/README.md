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
cout << static_cast<const void *>(&str) << endl;  # 通过强转地址成无类型指针来避免cout自动转化
```

* 精度控制
```cpp
cout << fixed << setprecision(4) << <double> << endl;
```

## Lambda 函数与表达式

```
[](int x, int y){ ++global_x; }
[](int x, int y){ return x < y; }
[](int x, int y) -> int { int z = x + y; return z + x; }
[](int x, int y){ return x + y; }(1, 2)  // 结果是3
```

## 结构体
其实c++里面的结构体就是类, 类就是结构体. [测试](./结构体-类.cpp)

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
* 构造函数
[样例](类销毁.cpp)
```
class Hobby {
    public:
        Hobby(string name) :name(name) {
        }
}
```

* [析构函数:销毁功能]
[样例](类销毁.cpp)
```
struct B
{
    ~B() { cout << "啊，我死了\n"; }
}
```

## [模板](https://www.runoob.com/cplusplus/cpp-templates.html)
模板设置参数后＝》模板函数  
模板函数再次编译后才能调用  
[同样的参数, 生成的模板函数的地址不一致](./模板-测试地址.cpp)

## 命名空间

* 基础用法

```
namespace first_space {
    void func() {}
}
namespace second_space {
    void func() {}
}
first_space::func()
```

* 直接引入

```
using std::cout
cout << '';
```

## 字符串
```
#include <string>
```

* [基本用法](./字符串.cpp)  
字符串的赋值会把字符复制过去

* int isalnum( int ch );
如果是[a-zA-Z0-9],则返回非0（不一定是8哦), 否则返回0

## Containers

## Vector

## memory
* [std::move](./std_move.cpp)
用来复制对象的引用
