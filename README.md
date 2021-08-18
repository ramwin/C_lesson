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

## 数据类型

    ```
    printf("int 存储大小: %lu \n", sizeof(int));
    ```


### 字符串
* [格式化](https://www.runoob.com/cprogramming/c-function-printf.html)

    ```
    printf("%lu", <32位无符号整数>)
    ```


### 包;多文件
1. gcc lib.c test.c
这样test.c里面可以直接用lib.c里面的函数，但是有warning, 因为编译test.c时不知道函数从哪来

2. 使用头文件引入
    ```
    #include "lib.c"  // 引入当前目录下
    #include <stdio.h>  // 引入系统目录
    ```
