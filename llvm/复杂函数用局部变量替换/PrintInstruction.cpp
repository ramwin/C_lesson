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
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <llvm/IR/InstrTypes.h>

using namespace llvm;

//-----------------------------------------------------------------------------
// DeleteInstruction implementation
//-----------------------------------------------------------------------------
// No need to expose the internals of the pass to the outside world - keep
// everything in an anonymous namespace.
namespace {

// This method implements what the pass does

bool complicate_exist(Function &F) {
  Function *complicate = F.getParent()->getFunction("complicate");
  for (auto &BB: F) {
    for (auto &Inst : BB) {
      // for (auto Inst = BB.begin(), IE = BB.end(); Inst != IE; ++Inst) {
      if (auto *Call = dyn_cast<CallBase>(&Inst)) {
        errs() << "调用了函数" << Call->getCalledFunction()->getName() << "\n";
        if (Call->getCalledFunction() == complicate) {
          return true;
        }
      }
    }
  }
  return false;
}

bool runOnFunction(Function &F) {
  if (! complicate_exist(F)) {
    return false;
  }

  auto &CTX = F.getParent()->getContext();
  errs() << F.getName() << "存在复杂函数\n";
  SmallVector<Instruction *, 8> ToRemove;

  Function *complicate = F.getParent()->getFunction("complicate");
  IRBuilder<> Builder(&*F.getEntryBlock().getFirstInsertionPt());
  Value *cache = Builder.CreateCall(complicate);
  errs() << "cache的值已经创建\n";
  // LoadInst *Load = Builder.CreateLoad(
  //     IntegerType::getInt32Ty(CTX),
  //     cache
  // );
  errs() << "Load已经\n";
  errs() << "创建了先调用complicate的指令\n";
  errs() << "创建了载入的指令\n";
  // 1. 强制设定只调用1次
  // bool cached = false;
  for (auto &BB: F) {
    for (auto &Inst: BB) {
      if (auto *Call = dyn_cast<CallBase>(&Inst)) {
        // 2. 用指令指针
        if (Call == cache) {
          continue;
        }
        if (Call->getCalledFunction() == complicate) {
          // if (!cached) {
          //   cached = true;
          //   continue;
          // }
          errs() << "我要替换你\n";
          Inst.replaceAllUsesWith(cache);
          errs() << "替换成功\n";
          ToRemove.push_back(&Inst);
        }
      }
    }
  }
  errs() << "循环结束\n";
  for (auto *I: ToRemove) {
    // I->replaceAllUsesWith(cache);
    I->eraseFromParent();
  }
  return true;
}

// New PM implementation
struct DeleteInstruction : PassInfoMixin<DeleteInstruction> {
  // Main entry point, takes IR unit to run the pass on (&F) and the
  // corresponding pass manager (to be queried if need be)
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    bool Changed = false;
    Changed = runOnFunction(F);
    return (Changed ? PreservedAnalyses::none() : PreservedAnalyses::all());
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
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "print-instruction") {
                    FPM.addPass(DeleteInstruction());
                    return true;
                  }
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
