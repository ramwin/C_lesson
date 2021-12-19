# ByteCode

* %2 2号寄存器

    @square(i32 %0) {
        %2 = mul nsw i32 %0, 7
        ret i32 %2
    }

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
