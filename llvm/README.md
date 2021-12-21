# ByteCode

* %2 2号虚拟寄存器

    @square(i32 %0) {
        %2 = mul nsw i32 %0, 7
        ret i32 %2
    }


* alloca, store, load

    %1 = alloca i32, align 4  // 申请4字节内存，地址存入1号寄存器
    store i32 0, i32* %1, align 4  // 把数字0存入1号寄存器指向的地址
    %4 = load i32, i32* %2, align 4  // 把2号寄存器指向的地址的数字， 存入4号寄存器
    %5 = add nsw i32 %4, 1  // 把4号寄存器的数字+1, 存入5号寄存器
    store i3 %5, i32* %3, align 4  // 把5好寄存器的数字，存入3号寄存器保存的地址
    %6 = load i 32, i32* %3, align 4  // 把3号寄存器的地址的数字，保存到6号寄存器
    ret i32 %6  // 返回6号寄存器数字

* 乘法

    %2 = mul nsw i32 %0, 7  // nsw, No Signed Wrap
    %3 = mul i32 %2, 7

# 指令

llvm:Instruction
[参考链接](https://llvm.org/doxygen/classllvm_1_1Instruction.html)

    if (auto *AI = dyn_cast<llvm:CallBase>Inst) {
        errs() << "这条指令是调用函数指令";
    }

* llmv::CallBase
* llvm::BinaryOperator
* llvm::UnaryInstruction
包括load指令