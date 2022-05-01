[cppreference](https://en.cppreference.com/w/cpp/header)

## 语法
### while
```
while (condition) statement
while (condition) {
    statements
}
while (condition)
  statements
```

## 输入输出

### getchar
获取一个stdin的字符
```
int a = getchar();  // 输入'a'
cout << a;
char b = getchar();  // 输入'a'
cout << b;
虽然cout的时候格式不一样(97, 'a')，但a==b会返回Ture
```

### cin
```
std::cout << "c=" << c << std::endl;
using namespace std;
cout << "c=" << c << endl;
```

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
char p[] = {'1', '2', '3'};
string result = p;  // 把C类型的字符串转化成c++的string. 但是字符串会被拷贝而不是引用
```

### [基本用法](./字符串.cpp)  
字符串的赋值会把字符复制过去

### `std::isspace(int ch)`:
返回是否是空.  
空的话返回Non-zero value, 非空返回0  

### `int isalpha( int ch )`
是不是字符[a-zA-Z]

### `int isalnum( int ch )`;
如果是[a-zA-Z0-9],则返回非0（不一定是8哦), 否则返回0

### `ends_with(string)`
返回是否以string结尾

### strtod
把字符串变成数字
```
const char* p = "111.11"
double f = str::strtod(p, nullptr) // 111.11
```

### substr(start, end)


## Containers

### [Map](https://en.cppreference.com/w/cpp/container/map)
```
std::map<std::string, int>
std::map<int, int> dict;
dict[2] = 3;
dict.count(2) == 0
```

### [Array](https://en.cppreference.com/w/cpp/container/array)
保存固定长度
```
std:array<int, 10> list;
std:array<char, 10> list;
#include <algorithm>
std:sort(std:array.begin(), std:array.end());
```

### [Vector](en.cppreference.com/w/cpp/container/vector.html)
保存动态长度
```
std:vactor<int> list = {1, 2, 3}
list2 = list  // 复制是复制所有内存
#include <algorithm>
std:sort(list.begin(), list.end());  // 排序
```


* count
返回0或者1

* `operator[]`
返回某个元素。如果不存在就是dict.end

* 迭代
```
void print(auto map) {
    for (const pair: map) {
        std::cout << pair.first << "=" << pari.second << end;
    }
}
```


## Vector

## memory
* [std::move示例](./std_move.cpp)
用来复制对象的引用

## [scope作用域](https://en.cppreference.com/w/cpp/language/scope)

## 文件
* std::ifstream
```
typedef basic_ifstream<char> 		ifstream;
```

* 读取文件直到换行符。注意换行符会被忽略
```
string a;
ifstream infile;
infile.open(<filename>)
infile >> a;
```
