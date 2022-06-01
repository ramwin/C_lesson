# [LLVM](./llvm/README.md)


# C_lession

[runoob官网](https://www.runoob.com/cprogramming/c-tutorial.html)  
[微软文档](https://docs.microsoft.com/zh-cn/cpp/c-language)  

## gdb
* help
* start
* next
* list
* break+num
* quit[q]

## 程序结构 [hello world](./hello_world.c)
[教程](https://www.runoob.com/cprogramming/c-program-structure.html)

### [获取main函数的参数](./参数-main.c)
```
int main(int argc, char * argv[]) {
    printf("参数个数: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
};
```


## 注释
[链接](https://www.runoob.com/cprogramming/c-basic-syntax.html)

    // 单行
    /* 多行
    */

## [数据类型](数据类型.c)
* char 1字节
* unsigned char 1字节
* range
一组数据
```
{0, 1, 2, 3}
```

### 整数
```
int a = 052;  // 八进制, 所以是42
int a = 0x12;  // 十六进制;
```
* int 4字节(根据系统而定)
* long 8字节(根据系统而定)


### 小数
* float  只能保留7位小数(根据系统而定)
* double float
* long double


## 变量
[链接](https://www.runoob.com/cprogramming/c-variables.html)  
局部变量的初始值是不确定的. 但是全局变量的初始值默认是0(估计是因为全局变量的值写入了elf)
```
int a;  a 的值不确定哦  // 10亿次需要2.076秒，快了大概3%
int a = 0; a 确定是0  // 10亿次需要2.143秒 
int a, b, c;
a = b = c = 4;  // 可以同时赋值
int var; 声明并初始化var, 申请了变量的内存地址
extern int var; 仅仅声明, 不需要编译器申请内存
```
* 寄存器变量
```
register int a;  // a保存在寄存器里, 不保证, 只是个hint
```
* static变量
```
static int a;  // 变量只能被当前文件访问
另外一个好处是, 函数内的static, 运行完毕后不会被销毁. 所以全局静态变量可以放在函数内部. 并且这个变量只会被初始化一次
int increment() {
    static int a = 1; 必须赋予一个constant value, 不能等于一个变量
    a++;
    return a;
};
```

* const常量
```
#define NAME value  // 但是这样会导致所有用的地方都赋值一份到内存吧
const value
```

## 内置函数
* sizeof(int/a/a[0])
unary operator, 不是函数哦
返回占用内存字节大小

```
printf("%lu", sizeof(1));
>>> 4
```


### 字符串
* 赋值
```
#include <string.h>
strcpy( Student.name, "ramwin");
```

# 输入输出

## 输出

### printf[格式化](https://www.runoob.com/cprogramming/c-function-printf.html)
输出并会返回输出内容的长度  
```
printf("%lu", <32位无符号整数>)  // 但是lu也能显示超过32位的，怀疑有兼容
printf("%llu", <64位无符号整数>)
printf("%s", <字符串>)
```
* %u: 无符号整数(short或者int)
* %d: 整数, short int
* %p: 地址
* %c: 字符
* %f: 浮点数, %.2f 必定保留2位小数
* %s: 字符串, %10s 必定保留至少10的宽度(前面加空格)
* %o: 八进制数字
* %x/%X: 十六进制数字(会根据x或者X变化大小写)

## 输入scanf
```
int var, varb;
scanf("%d%d", &var, &varb);  # 遇到space才输入, 所以可以输入"123 456\n" "123\n456\n"
```

## Operator
* lvalue: 存在identifiable location in memory的object
所以必须是变量. 不能是expression, function, const
* rvalue: 不存在identifiable location
表达式, 函数, 常量

### binary operator
`+, -, *, /, %, &&, ||, ==, !=, <=, >=, <, >`

### unary operator
++, --, 必须作用于lvalue  
++a, pre-incrementing, 先加后用  
a++, post-incrementing  

## 编译原理

### Lexical analysis
第一步词法分析, 生成token  
词法分析总是寻找最长匹配  
`a+++b`变成token:`a ++ + b`
`a + ++b`变成token: `a + ++ b`
```
a=4, b=3
a+++b = 7
a=4, b=3
a + ++b = 8
```
a+++++b变成token: `a ++ ++ + b`, a++没问题,a++的结果是rvalue, 再++就error了

## 判断


## 数组
* 字符数组
```
char a[6];
char a[6] = {"s", "t", "r", "i", "n", "g}  // 有人说最后要加\0, 但是我字符串都固定长度了，最后不需要加\0了吧。
print("%s", a)  // 只会输出 string，试了好多次，总觉得是gcc在最后默认加\0了, 测试验证，的确是的 a[6] 总是0, a[7]是随机。那不就内存不安全了吗，经过测试，应该是超过程序自带的内存就报错，否则是返回真正的内存的?
print("%lu\n", a[50])  // 总是不报错并且返回一个数字
print("%lu\n", a[5000])  // 有可能因为内存不够超过范围而报错
```


## 指针

### 定义指针

    ```
    struct Student *p;  // 定义结构体的指针
    p = &student
    p + 1  // 这样会直接增加strudent的size
    ```

### 使用指针

    ```
    p->age;  // 获取p对应的student的age
    ```


## 结构体
* [最简单的](./结构体/base.c)

[例子](./pointer_struct.c)

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

* [使用指针强转继承](./结构体/结构体继承.c)

    struct Person a;
    struct Animal *f = (struct Animal *) &a;


* 如果强制访问超内存的结构体
[测试](./结构体/超内存范围.c)  
这样会导致结构体访问的内存不再是属于程序, 如果内存没有超过, 会导致误修改其他变量  


    int a = 0;
    int b = 18;
    struct Person *person;
    person = &a;
    person->age = 32;  // b会变成32


## [预处理器](https://docs.microsoft.com/zh-cn/cpp/preprocessor/preprocessor-directives?view=msvc-170)
理解成编译前执行文本替换的操作

### define  
只会替换token, 不会替换双引号内部的字符
```
#include <stdio.h>
#define MAX_ARRAY_LENGTH 20

int main() {
    printf("最大的长度是: %d\n", MAX_ARRAY_LENGTH);
}
```
注意, define后面一定要加括号, 先expansion 然后evaluation
```
#define WIDTH 80
#define LENGTH + 10  // 注意，我是80 + 10 而不是 90
var = LENGTH * 20;  会变成 80 + 10 * 20 = 280 而不是 180
```
* 多行
```
#define greater(x, y) if (x > y) \
                        printf("x比较大")
                      else
                        print("y比较大")
```
* 特殊变量
注意哦, 先expansion后evaluation. 所以这些都是固定的. 每次运行都是编译时候的数字
`__DATE__` 日期
`__TIME__` 时间

## 头文件;包;多文件
[链接](https://www.runoob.com/cprogramming/c-header-files.html)
1. gcc test.c
这样test.c里面可以直接用lib.c里面的函数，但是有warning, 因为编译test.c时不知道函数从哪来

2. 使用头文件引入
```
#include "lib.c"  // 引入当前目录下
#include <stdio.h>  // 引入系统目录
```

## time.h
[runoob](https://www.runoob.com/cprogramming/c-standard-library-time-h.html)
[例子](./time.c)
    
```
time_t rawtime;
time(&rawtime);  // 内部把 rawtime 的值变了
或者 rawtime = time(NULL);  // 外部赋予了rawtime的值
这样rawtime就是时间戳(秒)了

struct tm *info;  // info 指向一个tm的指针
info = localtime(&rawtime);  // 把rawtime的指针传入得到info
info->tm_sec;  // 获取秒
```

* [clock](https://en.cppreference.com/w/c/chrono/clock)
```
#include <time.h>
clock_t start = clock();
clock_t end = clock();
printf("耗时: %u\n", end - start);
```

## 内存分配方式
* [内存地址不是按照顺序申请的](内存地址不是按照顺序申请的)
```
t, z, o 可能分配到一起
char t = 'b';
printf("变量t的内存地址: %d\n", &t);
int x = 0;  // x的内存会放到后面。
printf("变量x的内存地址: %d\n", &x);
char z = 'a';
char o;
```

* [栈地址是从大往小申请,预计8M](./测试堆栈/栈地址大概8M.c)
* 但是函数内部是按照顺序从小往大申请的
* 函数变量，

    外部函数
        a
        b = a + 4
        c = b + 4
        int(a, b)
    二级函数int(x, y)
        y最大 = c + 
* 堆地址比栈的地址要小. 一般从小到大申请

### 内存的分段
通过`size a.out`来查看一个程序的分段
* text  
二进制代码
* data
注意, 初始化怎么判断的?, 根据是不是等于0判断的. 所以int a = 0; 仍然没有初始化
初始化了的全局变量
初始化了的static
* bss
没有初始化的static
没有初始化的全局变量

## GCC
[文档](https://zhuanlan.zhihu.com/p/39219541)
* -E
把文件预处理后输出, 不进行compiler proper(一般用后缀名.i)
```
gcc -E define.c -o define.i
```
* -S
只进行编译(compiler proper)，而不进行链接(assemble)
```
gcc -S define.i -o define.s
```
* -c
进行(compile)汇编或者(assemble)集成
```
gcc -c define.s -o define.o
```
* 最后链接

## binutil

### nm
```
nm a.out | sort 看所有的符号的位置
```

### objdump
```
objdump -d --disassemble="函数名" <二进制文件>
```

## stdlib
* [atoi](https://www.delftstack.com/howto/c/c-string-to-int/#atoi-function-to-convert-a-string-to-an-integer-in-c)
把字符串转化成数字
```
int atoi(const char *str);
atoi("32") == 32;
```

## 文件读写
[runoob](https://www.runoob.com/cprogramming/c-file-io.html)  
[示例](./file.c)  

* FILE fgetc
```
FILE *fopen( const char * filename, const char * mode );
FILE *f = fopen("123.txt", "r");
int c = fgetc(f);
char d = fgetc(f);
printf("前两个字符是%c%c\n", c, d);
```

* fgets
获取最多个255-1字符，写入字符串. 遇到换行符或者文件结束就结束. 然后会在字符串末尾加一个null
```
FILE *f = fopen("123.txt", "r");
char buff[255];
fgets(buff, 255, f);
```

* `ftell(FILE *p)`
返回当前文件的读取到的位置

* fseek
和python类似, 或者说python和C类似
```
fseek(FILE *p, -1, SEEK_END) 
```

* ftell
返回当前的index

## pthread
[教程](https://www.geeksforgeeks.org/multithreading-c-2/)  
[基础功能](thread.c)  
[多线程-参数](./多线程-参数.c)

## limits  
* `INT_MIN`
* `INT_MAX`
* `UINT_MAX`
* `SHRT_MIN`
* `SHRT_MAX`

[next](https://www.youtube.com/watch?v=5JXcX0IqRUo&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=22)
