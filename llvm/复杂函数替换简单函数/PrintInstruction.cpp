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

bool runOnBB(BasicBlock &BB) {
  bool Changed = false;
  Instruction *to_del=0;
  Function *complicate = BB.getParent()->getParent()->getFunction("complicate");
  Function *simple = BB.getParent()->getParent()->getFunction("simple");
  for (auto &Inst : BB) {
    // for (auto Inst = BB.begin(), IE = BB.end(); Inst != IE; ++Inst) {
    if (auto *Call = dyn_cast<CallBase>(&Inst)) {
      errs() << "调用了函数" << Call->getCalledFunction()->getName() << "\n";
      if (Call->getCalledFunction() == complicate) {
        errs() << "获取了simple的函数\n";
        IRBuilder<> Builder(&Inst);
        Instruction *NewValue = Builder.CreateCall(simple);
        Inst.replaceAllUsesWith(NewValue);
        to_del = Call;
        Changed = true;
      }
      // ReplaceInstWithInst(BB.getInstList(), Inst, NewValue);
      // Inst.replaceAllUsesWith(NewValue);
    }
  }
  if (to_del) {
    to_del->eraseFromParent();
  }
  return Changed;
}

// New PM implementation
struct DeleteInstruction : PassInfoMixin<DeleteInstruction> {
  // Main entry point, takes IR unit to run the pass on (&F) and the
  // corresponding pass manager (to be queried if need be)
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    bool Changed = false;
    for (auto &BB : F) {
      Changed = runOnBB(BB);
    }
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
