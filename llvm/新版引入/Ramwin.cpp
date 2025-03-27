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
//      opt -load libDeleteInstruction.dylib -legacy-delete-instruction -disable-output `\`
//        <input-llvm-file>
//    2. New PM
//      opt -load-pass-plugin=libDeleteInstruction.dylib -passes="delete-instruction" `\`
//        -disable-output <input-llvm-file>
//
//
// License: MIT
//=============================================================================
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

//-----------------------------------------------------------------------------
// DeleteInstruction implementation
//-----------------------------------------------------------------------------
// No need to expose the internals of the pass to the outside world - keep
// everything in an anonymous namespace.
namespace {

  // This method implements what the pass does
  bool visitor(Function &F) {
    bool Changed = false;
    int index = 0;

    errs() << "处理函数: "<< F.getName() << "\n";

    for (auto &BB: F) {
      errs() << index << "  处理BB块" << "\n";
      // errs() << BB << "\n";
      int instruction_index = 0;
      for (auto &Inst: BB) {
        errs() << index << "." << instruction_index << ": ";
        errs() << Inst << "\n";
        if (index == 3 && instruction_index == 3) {
          errs() << "我是循环" <<": " << Inst << "\n";

        }
        instruction_index += 1;
      }
      index += 1;
    }

    return Changed;
  }

  // New PM implementation
  struct DeleteInstruction : PassInfoMixin<DeleteInstruction> {
    // Main entry point, takes IR unit to run the pass on (&F) and the
    // corresponding pass manager (to be queried if need be)
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
      bool Changed = visitor(F);
      return (Changed ? PreservedAnalyses::none()
                      : PreservedAnalyses::all());
    }
  };

} // namespace

//-----------------------------------------------------------------------------
// New PM Registration
//-----------------------------------------------------------------------------
llvm::PassPluginLibraryInfo registerRamwin() {
  errs() << "getDeleteInstructionPluginInfo" << "\n";
  return {
    LLVM_PLUGIN_API_VERSION,
    "DeleteInstruction",
    LLVM_VERSION_STRING,
    [](PassBuilder &PB) {
      errs() << "回调" << "\n";
      PB.registerPipelineParsingCallback(
          [](StringRef Name,
             FunctionPassManager &FPM,
             ArrayRef<PassBuilder::PipelineElement>) {
                errs() << "参数是我,是" << Name << "\n";
                FPM.addPass(DeleteInstruction());
                return true;
          }
      );
    }};
}

// This is the core interface for pass plugins. It guarantees that 'opt' will
// be able to recognize DeleteInstruction when added to the pass pipeline on the
// command line, i.e. via '-passes=delete-instruction'
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return registerRamwin();
}
