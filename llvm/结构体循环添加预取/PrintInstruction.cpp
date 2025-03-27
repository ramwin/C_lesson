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
#include "llvm/Analysis/LoopInfo.h"
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

bool runOnFunction(Function &M) {
  return false;
};

bool runOnModule(Module &M) {
  return false;
};

bool exist_loop(Function &F) {
  errs() << "  寻找F内的循环: " << F.getName() << "\n";
  errs() << "  FunctionType: " << F.getFunctionType() << "\n";
  auto loopInof = new llvm::LoopInfoBase<BasicBlock, llvm::Loop>();
  for (auto &BB: F) {
    for (auto &Inst: BB) {
      // errs() << BB.getOpcode() << "\n";
      // errs() << BB.getDeleteInstructionPluginInfo() << "\n";
      // errs() << Inst.getOpcode() << " " << Inst.getOpcodeName() << "\n";
      // errs() << "  " << Inst << "\n";
    };
  };
  return false;
};

// New PM implementation
struct DeleteInstruction : PassInfoMixin<DeleteInstruction> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
    errs() << "调用run\n";
    bool Changed = runOnModule(M);
    errs() << "迭代Module M\n";
    for (auto &F: M) {
      errs() << "  处理函数" << F.getName() << "\n";
      if (exist_loop(F)) {
        errs() << "  函数 " << F.getName() << "存在循环\n";
      };
    };
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
