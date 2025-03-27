//=============================================================================
// FILE:
//    DeleteInstruction.cpp
//
// DESCRIPTION:
//    Visits all functions in a module, prints their names and the number of
//    arguments via stderr. Strictly speaking, this is an analysis pass (i.e.
//    the functions are not modified). However, in order to keep things simple
//    there's no 'print' method here (every analysis pass should implement it).
//
// USAGE:
//    1. Legacy PM
//      opt -load libDeleteInstruction.dylib -legacy-delete-instruction
//      -disable-output `\`
//        <input-llvm-file>
//    2. New PM
//      opt -load-pass-plugin=libDeleteInstruction.dylib
//      -passes="delete-instruction" `\`
//        -disable-output <input-llvm-file>
//
//
// License: MIT
//=============================================================================
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/CFG.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <llvm/IR/InstrTypes.h>
#include "llvm/IR/ValueSymbolTable.h"

using namespace llvm;

//-----------------------------------------------------------------------------
// DeleteInstruction implementation
//-----------------------------------------------------------------------------
// No need to expose the internals of the pass to the outside world - keep
// everything in an anonymous namespace.
namespace {

// This method implements what the pass does

bool runOnFunction(Function &F) {
  errs() << "处理函数: " << F.getName() << "\n";
  Constant *GlobalCache = F.getParent()->getGlobalVariable("g");
  for (auto &BB:F) {
    for (auto &Inst:BB) {
      errs() << "  指令: \n";
      // errs() << Inst << "\n";
      if (isa<LoadInst>(Inst)) {
      // if (auto *Unary = dyn_cast<UnaryInstruction>(&Inst)) {
        auto load_inst = dyn_cast<LoadInst>(&Inst);
        errs() << *load_inst << "\n";
        errs() << load_inst->getOpcode() << "\n";  // 32
        auto load_addr = load_inst->getOperand(0);
        errs() << load_addr << "\n";
        if (load_addr == GlobalCache) {
          errs() << "竟然读取了全局变量\n";
        } else {
          errs() << "竟然读取了局部变量\n";
        }
        errs() << load_inst->getOperand(0) << "\n";
        errs() << "  是读取指令\n";
      }
    }
  }
  return false;
};

bool runOnModule(Module &M) {
  bool changed = false;
  for (auto &F: M) {
    errs() << "存在函数: " << F.getName() << "\n";
    changed = runOnFunction(F) || changed;
  };
  return changed;
};

// New PM implementation
struct DeleteInstruction : PassInfoMixin<DeleteInstruction> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
    errs() << "调用run\n";
    bool Changed = runOnModule(M);
    errs() << "迭代Module M\n";
    for (auto &alias : M.getIdentifiedStructTypes()) {
      errs() << "  " << alias->getName() << "\n";
      for (auto &attr : alias->elements()) {
        errs() << "    属性" << *attr << "\n";
      }
    };
    return (Changed ? PreservedAnalyses::none()
                    : PreservedAnalyses::all());
  }
};

} // namespace

//-----------------------------------------------------------------------------
// New PM Registration
//-----------------------------------------------------------------------------
llvm::PassPluginLibraryInfo getDeleteInstructionPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "DeleteInstruction", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  // if (Name == "print-instruction") {
                    MPM.addPass(DeleteInstruction());
                    return true;
                  // }
                  return false;
                });
          }};
}

// This is the core interface for pass plugins. It guarantees that 'opt' will
// be able to recognize DeleteInstruction when added to the pass pipeline on the
// command line, i.e. via '-passes=delete-instruction'
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getDeleteInstructionPluginInfo();
}
