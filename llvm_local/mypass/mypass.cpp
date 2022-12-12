#include "llvm/Analysis/LoopPass.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
#include "polly/ScopInfo.h"
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
#include <llvm/Analysis/LoopInfo.h>
#include "llvm/Analysis/ScalarEvolution.h"
//#include ""
using namespace llvm;
using namespace std;
namespace
{
  struct GetStride : public polly :: ScopPass
  {
    static char ID;

    GetStride() : polly::ScopPass(ID) {}

    bool runOnScop(Scop &S) override
    {
       //auto schedule = S.getSchedule();
       //auto m = schedule.extract_map(schedule.get_space());
       //get the scopinfo
      //ScopInfo *SI = getAnalysis<polly :: ScopInfoWrapperPass>().getSI();
      //polly :: ScopDetection &SD = getAnalysis<polly :: ScopDetectionWrapperPass>().getSD();     
      //errs() << S << "\n";
      //const std :: vector<llvm :: Instruction*>vect;
      //const std :: vector<llvm :: Instruction*>vect2;
      //Region &R = S.getRegion();
      //errs() << R << "\n";
      //errs() << "\nHello\n";
      //errs() << R << "\n";
      //Scop* scop = ScopInfoRegionPass :: getScop();
      //const Scop* scop = polly::ScopInfo::getScop(R);
      //LoopInfo* LI = S.getLI();
      //ScalarEvolution* SE = &getAnalysis<ScalarEvolutionWrapperPass>().getSE();
      //LI->
      //errs() << LI << "\n";
      errs() << "////////////////////////////\n";
      for(auto BB : S.blocks())
      {
        // for(auto &inst : *BB)
        //{
          for(auto stmt : S.getStmtListFor(BB))
          {
            errs() << "////////////////////////////\n";
            auto inst_list  = stmt->getInstructions();
            auto domain     = stmt->getDomainStr();
            auto sr_loop    = stmt->getSurroundingLoop();
            PHINode* ind_var    = sr_loop -> getCanonicalInductionVariable(); 
            errs() << "\nScopStatement: " << *stmt;
            errs() << "\nDomainOfStatement: " << domain;
            errs() << "\nSorroundingLoop: " << *sr_loop;
            errs() << "\nInstructions:\n";
            for(auto inst : inst_list)
            {
              // errs() << "\nScop Statement: " << *stmt << "\nInstruction: " << *inst << "\nDomain: " << domain << "\nSorrounding Loop: " << *sr_loop
              // << "\nInductionVariable" << *ind_var;
              errs() << *inst << "\n";
            }
            for (auto access : *stmt)
            {
              errs() << "IsRead: " << access->isRead() << "\n";
              errs() << "Element type: " << *(access->getElementType()) << "\n";
              errs() << "Value: " << *(access->getAccessValue()) << "\n";
              errs() << "Original Base Addr: " << *(access->getOriginalBaseAddr()) << "\n";
              errs() << "Array ID: " << (access->getArrayId()).name() << "\n";
              errs() << "Is Scalar: " << access->isScalarKind() << "\n";
            }
          }
          errs() << "////////////////////////////\n";
          //auto stmt = S.getStmtFor(&inst);
          //auto surrounding_loop = stmt->getSurroundingLoop();
          //errs() << "Instruction: " << inst << "\n";
          // if(!stmt)
          // {
          //   continue;
          // }

          // auto inst_list = stmt->getInstructions();
          // // //errs() << inst_list << "\n";
          // for(auto vect : inst_list)
          // {
          //   errs()  << "\nInstruction: " << *vect << "\n Statement: " << *stmt << "\n";
            
          // }

        //}
      //  //polly :: ScopStmt :: printInstructions(raw_ostream &OS);
        //errs() << i;
        //polly :: ScopStmt &Stmt = dyn_cast<polly :: ScopStmt>i;
        //vect2 = (i->getInstructions());
        //vect.insert(vect.end(), (i->getInstructions()).begin(), (i->getInstructions()).end());  
        //const std vector<Instruction*>vect;
        //polly::ScopStmt* stmt = &*i;
        //errs() << "\nHello\n";
        //errs() << stmt->getInstructions() <<"\n";
        //vect = i->getInstructions();
        //polly :: ScopStmt& Stmt = *i;
        //errs() << "hello";
        //errs() << i;
        //;
      }
      errs() << "////////////////////////////\n";
      return false;
    }
   //void getAnalysisUsage(AnalysisUsage &AU) const  {
     //AU.addRequired<polly::ScopInfoRegionPass();
     //AU.addRequired<polly :: ScopDetectionWrapperPass>();
   //}
  //  void getAnalysisUsage(AnalysisUsage &AU) const {
  //   AU.addRequired<ScalarEvolutionWrapperPass>();
  //   AU.addPreserved<ScalarEvolutionWrapperPass>();
  //  }

  };
} // namespace
char GetStride::ID = 0;
static RegisterPass<GetStride> X("getstride", "GetStride pass", false /* Only looks at CFG */,
                                 false /* Analysis Pass */);



