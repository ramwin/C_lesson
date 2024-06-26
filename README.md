```{toctree}
./基础语法.md
```

# LLVM
```{toctree}
./llvm/README.md
```

# [C++](./c++/README.md)

# C_lession

[runoob官网](https://www.runoob.com/cprogramming/c-tutorial.html)  
[微软文档](https://docs.microsoft.com/zh-cn/cpp/c-language)  


# gdb
* help
* start
* next
* list
* break+num
* quit[q]

# 基础库 lib
## string
* strlen
返回字符串的长度(不包含 `\0` )

* strcpy(a, b)
复制b指针对应的字符串到a指针, 包括null也会复制过去.

* strncat(a, b, size) 更安全的strcat
把size个字符从b复制到a的末尾

* strcat(a, b)
从b复制到a的末尾

* strcmp
比较2个字符串, 定义里是返回 `<0, =0, <0` 的值
```
printf("%d", strcmp("123", "234"));
-1  // -1是特例
```

# 编译原理

## 动态库与静态库

### youtube教程
`https://www.youtube.com/watch?v=YtiPCPtmZrs`
```
gcc -fPIC(position indenpent code) -shared -
gcc -I./include 来增加.h文件
gcc -c ./src/main.c -I./include 只生成.o文件, 就是library; gcc main.o mymath.o -o prog 这个就是链接了.
ar r(replace)c(create)s(create index) mymath.a mymath.o mymath2.o 避免每次都要发很多静态.o
gcc -fPIC -shared ./src/mymath. -I./include.o -o libmymath.so(shared object)
gcc ./src/main.c -o prog -I./include -lmymath(链接上mymath.so并且不需要lib和so) -L./(不然报错,需要告诉linker文件位置)
./prog 报错, 因为无法找到libmymath.so. 因为runtime时不知道,需要设置LD_LIBRARY_PATH=""
objdump -t ./prog 发现multi和add是未定义 UND 的
```

### runoob教程
[runoob文档](https://www.runoob.com/w3cnote/cpp-static-library-and-dynamic-library.html)
* 编译静态库
静态库是指编译时, 把库的内容放入最终的target. 优点是移植方便. 缺点是重复占用内存.
```shell
gcc -c ramwin.c -o libramwin.a
```
* 使用静态库
```shell
gcc use.c \
    -Istatic_lib \  # 支持引用static_lib里面的头文件
    -Lstatic_lib/ -lramwin  # 把static_lib里面的 libramwin.a 也编译进来
```

* 编译动态库
动态库在多个程序执行时, 库函数占用同一片内存. 动态库更新时, 可以免去程序重新编译部署的麻烦
```shell
gcc -fPIC -c ramwin.c -o libramwin.o  # -fPIC 创建与地址无关的编译程序（pic，position independent code），是为了能够在多个应用程序间共享。
gcc -shared -o libramwin.so libramwin.o
# 或者一次到位
gcc -fPIC -shared -o libramwin.so ramwin.c
```

* 使用动态库
```
gcc ./use_dynamic.c  -L./dynamic_lib/ -lramwin
./a.out  # 报错了
./a.out: error while loading shared libraries: libramwin.so: cannot open shared object file: No such file or directory
```
因为系统执行的时候, 不知道从哪引入ramwin.so, 需要复制到/usr/lib下, 也可以复制到 `/usr/local/lib` 下, 但是执行前要设置`export LD_LIBRARY_PATH=/lib:/usr/lib:/usr/local/lib`


## Lexical analysis
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


# 工具
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

[next](https://www.youtube.com/watch?v=LJ0m-8zGRB4&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=71)
