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

using namespace llvm;

//-----------------------------------------------------------------------------
// DeleteInstruction implementation
//-----------------------------------------------------------------------------
// No need to expose the internals of the pass to the outside world - keep
// everything in an anonymous namespace.
namespace {

// This method implements what the pass does

bool complicate_exist(Function &F) {
  Function *complicate = F.getParent()->getFunction("GetPoint");
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
};

bool complicate_exist(BasicBlock &BB) {
  Function *complicate = BB.getParent()->getParent()->getFunction("GetPoint");
  for (auto &Inst : BB) {
    // for (auto Inst = BB.begin(), IE = BB.end(); Inst != IE; ++Inst) {
    if (auto *Call = dyn_cast<CallBase>(&Inst)) {
      errs() << "调用了函数" << Call->getCalledFunction()->getName() << "\n";
      if (Call->getCalledFunction() == complicate) {
        return true;
      }
    }
  }
  return false;
};

bool complicate_exist_deep(BasicBlock &BB) {
  // 深度优先判断block是否有complicate
  if (complicate_exist(BB)) {
    return true;
  }
  for (BasicBlock *Suc : successors(&BB)) {
    if (complicate_exist(*Suc)) {
      return true;
    }
  };
  return false;
};

bool must_call(BasicBlock &BB) {
  // 是否一定触发调用
  for (BasicBlock *Suc: successors(&BB)) {
    if (complicate_exist_deep(*Suc)) {
      continue;
    }
    return false;
  };
  return true;
}

BasicBlock & get_call_block(BasicBlock &BB) {
  // 返回需要调用的BB块
  if (complicate_exist(BB)) {
    return BB;
  }
  // 暂时只考虑只有2个分支
  bool both_exist = true;
  BasicBlock *exist_block = 0;
  for (BasicBlock *Suc: successors(&BB)) {
    if (!complicate_exist_deep(*Suc)) {
      both_exist = false;
    } else {
      exist_block = Suc;
    }
  }
  if (both_exist) {
    return BB;
  }
  return *exist_block;
}

bool runOnFunction(Function &F) {
  SmallVector<Instruction *, 8> ToRemove;
  if (! complicate_exist(F)) {
    return false;
  }
  for (auto &BB: F) {
    errs() << "---------BB块:开始---------"
           << BB ;
    for (BasicBlock *Suc: successors(&BB)) {
        errs() << "我有好多\n";
        errs() << Suc->getName() << "\n";
    }
    errs() << "---------BB块:结束---------\n\n";
  }

  bool cached = false;

  BasicBlock & entry_block = F.getEntryBlock();
  BasicBlock & BB = get_call_block(entry_block);
  IRBuilder<> Builder(&*BB.getFirstInsertionPt());
  errs() << "应该调用的地方" << BB;
  errs() << "循环结束\n";
  Function *complicate = F.getParent()->getFunction("GetPoint");
  Value *cache = Builder.CreateCall(complicate);
  for (auto &BB: F) {
    for (auto &Inst: BB) {
      if (auto *Call = dyn_cast<CallBase>(&Inst)) {
        if (Call->getCalledFunction() == complicate) {
          if (Call == cache) {
            continue;
          }
          Inst.replaceAllUsesWith(cache);
          ToRemove.push_back(&Inst);
        }
      }
    }
  }
  for (auto *I: ToRemove) {
    I->replaceAllUsesWith(cache);
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
                  // if (Name == "print-instruction") {
                    FPM.addPass(DeleteInstruction());
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
