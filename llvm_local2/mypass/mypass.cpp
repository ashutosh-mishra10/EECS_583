#include "llvm/Analysis/LoopPass.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
#include "polly/ScopInfo.h"
#include "llvm/Analysis/LoopInfo.h"
// #include "polly/isl/ast.h"
#include "polly/ScopPass.h"
#include "llvm/Transforms/Scalar/LoopPassManager.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopIterator.h"
#include "polly/Support/ISLOStream.h"
#include <vector>
#include <array>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <type_traits>
#include <vector>
#include <polly/PolyhedralInfo.h>
#include <iostream>
//#include ""
using namespace llvm;
using namespace std;
namespace 
{
  struct GetStride : public FunctionPass
  {
    static char ID;

    GetStride() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override
    {
      for(Function :: iterator b = F.begin(); b != F.end(); b++)
      {
        BasicBlock* BB = &*b;
        LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
        auto Inner_loop = LI.getLoopFor(BB);// getLoopFor(BB);
        auto *PHInfo    = &getAnalysis<polly :: PolyhedralInfo>();
        auto IsParallel = PHInfo->isParallel(Inner_loop);
        errs() << IsParallel << "\n";
        unsigned int VF = 0;
        auto isvectorizable = PHInfo->
        //errs() << Inner_loop->getName();
        //PHINode* ind_var = Inner_loop->getCanonicalInductionVariable();
        //errs() << loop_name << "\n";
        //errs() << BB;

      }
      
      //auto *PHIInfo = &getAnalysis<polly :: PolyhedralInfo>();
      
      return false;
    }
   //void getAnalysisUsage(AnalysisUsage &AU) const  {
     //AU.addRequired<polly::ScopInfoRegionPass();
     //AU.addRequired<polly :: ScopDetectionWrapperPass>();
   //}
   void getAnalysisUsage(AnalysisUsage &AU) const {
    AU.addRequired<polly :: PolyhedralInfo>();
    AU.addRequired<LoopInfoWrapperPass>();
   }

  };
} // namespace
char GetStride::ID = 0;
static RegisterPass<GetStride> X("getstride", "GetStride pass", false /* Only looks at CFG */,
                                 false /* Analysis Pass */);



