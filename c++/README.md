[cppreference](https://en.cppreference.com/w/cpp/header)

## 语法
### 引用
[传递指针](../测试堆栈/传递指针.cpp)  
从代码上看, 的确是只有引用, 没有栈内存, 但实际上汇编里, 一个函数应该不可能知道
他操作哪个变量的. 所以要么就是汇编里实际上还是传递了指针, 要么就是把这个函数展开,
放在外部函数里. 待测试(顺带测inline时是否要申请栈内存)


### while
```cpp
while (condition) statement
while (condition) {
    statements
}
while (condition)
  statements
```

## 输入

### sscanf
把字符串根据指定的格式进行解析
```
char input[] = "25 54.32E-1 Thompson 56789 0123"
int a;
float b;
char c[10]
std::sscanf(input, "%d%f%9s", &a, &b, &c)
```

### getline
获取一行的字符串
```
std:string name;
std::getline(std::cin, name);
cout << name << endl;
```

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

* 如果是`char[]`, 会导致内存是连续的
```cpp
char c[3];
char d[4];
cin >> c >> d;
输入123\n456, 输出竟然是123456 456
```

## 输出
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 支持三种输入的构造
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
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
```cpp
struct B
{
    ~B() { cout << "啊，我死了\n"; }
}
```

### Magic Method
[案例](./magic_method.cpp)
```cpp
class EvenBigger {
  public:
    int num;
    EvenBigger(int num): num(num) {
    };
    bool operator<(EvenBigger another) {
      cout << "比较" << num << " < " << another.num << endl;
      if ((num % 2) == (another.num % 2)) {
        return num < another.num;
      }
      if (num % 2 == 0) {
        return false;
      }
      return true;
    };
};
```

## [模板](https://www.runoob.com/cplusplus/cpp-templates.html)
模板设置参数后＝》模板函数  
模板函数再次编译后才能调用  
[同样的参数, 生成的模板函数的地址不一致](./模板-测试地址.cpp)

## 命名空间
* 基础用法
```cpp
namespace first_space {
    void func() {}
}
namespace second_space {
    void func() {}
}
first_space::func()
```

* 直接引入

```cpp
using std::cout
cout << '';
```

## 字符串 string

```cpp
#include <string>
char p[] = {'1', '2', '3'};
string result = p;  // 把C类型的字符串转化成c++的string. 但是字符串会被拷贝而不是引用
```

### [string 字符串](https://en.cppreference.com/w/cpp/string/basic_string)  
[基本用法](./字符串.cpp)  

字符串的赋值会把字符复制过去

    ```cpp
    string a = string(10, 'a');  # 生成10个'a'
    ```

* [find](https://en.cppreference.com/w/cpp/string/basic_string/find)
[测试](string_find.cpp)

查找字符串出现的位置。

    ```cpp
    string s = "12345";
    s.find("23")  //  存在返回索引，否则返回 string::npos
    ```

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
见`字符串.cpp test4`
```
string a = "abcd";
string b = a.substr(1, 2);  // b的字符是从a拷贝过来的
```

### Search
* `size_type find(const basic_string &str)`
```
if (string.find(char) != string.npos) {
    cout << "找到了"
}
```

### Constants
npos 代表了不存在的字符位置。(实际等于0b111...111, 但是不要用-1)

### 数字转化
* stoi/stol/stoll 把字符变成整数


## Containers

### [Map](https://en.cppreference.com/w/cpp/container/map)
```
std::map<std::string, int>
std::map<int, int> dict;
dict[2] = 3;
dict.count(2) == 0

// 迭代
for (const auto& [key, value] : m) {
    cout << '[' << key << "] = " << value << "; ";
};
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
保存动态长度的列表
```
std:vactor<int> list = {1, 2, 3}
list2 = list  // 复制是复制所有内存
#include <algorithm>
std:sort(list.begin(), list.end());  // 排序
```

#### Element access
* back
最后一个元素
* front
第一个元素

#### iterators
* rbegin
反向迭代
```
  vector<char> a { 'a', 'b', 'c', 'd'};
  for (auto i=a.rbegin(); i!=a.rend(); i++) {
    cout << *i;
  }
```

#### Modifiers
* `pop_back`
移除最后一个元素

* `push_back`

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


### [set](https://en.cppreference.com/w/cpp/container/set)
[基础](./set.cpp)
* [insert](https://en.cppreference.com/w/cpp/container/set/insert)  
    插入元素，返回pair, first是指向插入元素的iterator, second是bool,代表是否真的插入
* erase  
    返回bool代表是否真的移除

* [find](https://en.cppreference.com/w/cpp/container/set/find)
查找元素。返回iterator(=set.end()代表没找到)

```cpp
set<int>::iterator b;
b = a.find(5);
if (b == a.end()) {
    cout << "没找到\n";
} else {
    cout << "找到了\n";
}
```


### [multiset](https://en.cppreference.com/w/cpp/container/multiset)
和set一样，但是能保存一个元素很多次

* erase(key)
删除所有key

* erase(iterator)
仅仅删除某个iterator下的元素

* iterator lower_bound(const Key& key)
找到某个key的最小的iterator.

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


## algorighm
### heap
* `make_heap(vector.begin(), vector.end())`
把vector排成堆。first最大
* `pop_head(vector.begin(), vector.end())`
把最大的移动到最后
* `std::push_head(v.begin(), v.end())`
把最后的数字放入堆
