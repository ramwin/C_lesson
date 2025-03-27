# Loop
```{toctree}
./loop.md
```

# inline
```{toctree}
./inline/README.md
```

# 安装
[文档](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)
```
sudo apt install cmake  # 有cmake可以不执行
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
mkdir build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=release -DLLVM_ENABLE_PROJECTS="clang" ../llvm
cmake --build . -j
```

# 术语
内存编译器中的IR == 磁盘的bitcode == 可读的汇编码

# clang
```
clang -O1 source.c -S -emit-llvm -o source.ll  # inline了
```
* -E 预处理

    # 1 "global.point.c"
    # 1 "./figure.h" 1
    typedef struct {
    }
    # 2 "global.point.c" 2
    Point g_point;

* -fsyntax-only 预编译,解析,类型检查
* -S 生成llvm

     .text
    .file "global.point.c"
    GetPoint:
        .cfi_startproc
    # %bb.0
    SetPoint:
    ...

* -c 全部,并且组合


# LLVM使用
* C源码转化成LLVM IR汇编码

    clang -emit-llvm -S multiply.c -o multiply.ll

* IR代码转化成bitcode

    llvm-as test.ll -o test.bc  # 之后test.bc就能用来链接了
    gcc main.o test.bc -o output && ./output

* bitcode转回LLVM汇编码

    llvm-dis test.bc –o test.ll

* opt工具对IR进行优化

    clang -emit-llvm -S multiply.c -o multiply.ll -Xclang -disable-O0-optnone
    opt -mem2reg -S multiply.ll -o multiply1.ll

* 链接bitcode

    llvm-link test1.bc test2.bc -o output.bc

* 执行bitcode

    lli output.bc

# ByteCode
* %2 2号虚拟寄存器

```
@square(i32 %0) {
    %2 = mul nsw i32 %0, 7
    ret i32 %2
}
```


* alloca, store, load
```
%1 = alloca i32, align 4  // 申请4字节内存，地址存入1号寄存器
store i32 0, i32* %1, align 4  // 把数字0存入1号寄存器指向的地址
%4 = load i32, i32* %2, align 4  // 把2号寄存器指向的地址的数字， 存入4号寄存器
%5 = add nsw i32 %4, 1  // 把4号寄存器的数字+1, 存入5号寄存器
store i3 %5, i32* %3, align 4  // 把5好寄存器的数字，存入3号寄存器保存的地址
%6 = load i 32, i32* %3, align 4  // 把3号寄存器的地址的数字，保存到6号寄存器
ret i32 %6  // 返回6号寄存器数字
```

* 乘法
```
%2 = mul nsw i32 %0, 7  // nsw, No Signed Wrap
%3 = mul i32 %2, 7
```


# 指令

llvm:Instruction
[参考链接](https://llvm.org/doxygen/classllvm_1_1Instruction.html)

```
// 通过isa
if (isa<LoadInst>(Inst)) {
    errs() << "是在载入指令啊";
}
// 通过isa
if (isa<LoadInst>(Inst)) {
    errs() << "是在载入指令啊";
}
if (auto *AI = dyn_cast<llvm:CallBase>Inst) {
    errs() << "这条指令是调用函数指令";
}
```

## llvm::LoadInst(llvm::UnaryInstruction)
* 获取load对象 `inst->getOperand(0)`


## 其他
* llmv::CallBase
* llvm::BinaryOperator
* llvm::UnaryInstruction
包括load指令

# AST
## BasicBlock

```
for (auto &Inst: BB) {
}...
```

## IRBuilder
* 生成builder
```
IRBuilder<> Builder(&Inst);
```

* 创建函数调用
注意，插入的指令会放在Inst的前面, 所以注意遇到函数插入的时候，要排除插入的函数, 不然死循环了
```
Builder.CreateCall(<*Function>)
```

### IRBuilderBase
* CreateCall

## MapVector
```
class MapVector {
    MapType Map;  // 保存数据类型
    VectorType Vector;  // std::vector 保存数据
    std::pari<iterator, bool> insert(std::pair) {
    }
}
```

## Function

* 获取某个函数的指针用于后期调用
```
Function *simple = <Module>.getFunction("函数名")
```

## 注册

```cpp
llvm::PassPluginLibraryInfo function() {
    a, b, c, lambda function
    [](PassBuilder &PB) {
        PB.registerPipelineParsingCalback(  # 重载运算符, 会根据参数返回对应函数
            (StringRef Name, ModulePassManager &MPM,kj
        )
    }
}
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    return function    
}
```

## 对每个函数操作
```
PreservedAnalyses <Module>::run(Function &Func, FunctionAnalysisManager &FAM) {
    return PreservedAnalyses::all();
}
```
