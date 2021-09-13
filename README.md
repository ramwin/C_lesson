# C_lession
[官网](https://www.runoob.com/cprogramming/c-tutorial.html)

## 程序结构 [hello world](./hello_world.c)
[教程](https://www.runoob.com/cprogramming/c-program-structure.html)

    # include <stdio.h>

    int main()
    {
        /* 我的第一个 C 程序 */
        printf("Hello, World! \n");
        return 0;
    }

## 注释
[链接](https://www.runoob.com/cprogramming/c-basic-syntax.html)

    // 单行
    /* 多行
    */

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

## 数据类型

    ```
    printf("int 存储大小: %lu \n", sizeof(int));
    ```


### 字符串
* 赋值

    ```
    #include <string.h>
    strcpy( Student.name, "ramwin");
    ```

* [格式化](https://www.runoob.com/cprogramming/c-function-printf.html)

    ```
    printf("%lu", <32位无符号整数>)
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
[例子](./pointer_struct.c)

    ```
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
