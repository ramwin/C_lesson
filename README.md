# C_lession

[runoob官网](https://www.runoob.com/cprogramming/c-tutorial.html)  
[微软文档](https://docs.microsoft.com/zh-cn/cpp/c-language)  


## 程序结构 [hello world](./hello_world.c)
[教程](https://www.runoob.com/cprogramming/c-program-structure.html)

### [获取main函数的参考](./参数-main.c)


## 注释
[链接](https://www.runoob.com/cprogramming/c-basic-syntax.html)

    // 单行
    /* 多行
    */

## [数据类型](数据类型.c)
* char 1字节
* unsigned char 1字节
* int 4字节
* long 8字节


## 变量
[链接](https://www.runoob.com/cprogramming/c-variables.html)

    ```
    int a;  a 的值不确定哦  // 10亿次需要2.076秒，快了大概3%
    int a = 0; a 确定是0  // 10亿次需要2.143秒 
    ```

## 内置函数
* sizeof(int/a/a[0])
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

* [格式化](https://www.runoob.com/cprogramming/c-function-printf.html)

    ```
    printf("%lu", <32位无符号整数>)  // 但是lu也能显示超过32位的，怀疑有兼容
    printf("%llu", <64位无符号整数>)
    printf("%s", <字符串>)
    ```


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


## 预处理器
理解成编译前执行文本替换的操作

    ```
    #include <stdio.h>
    #define MAX_ARRAY_LENGTH 20

    int main() {
        printf("最大的长度是: %d\n", MAX_ARRAY_LENGTH);
    }
    ```

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
