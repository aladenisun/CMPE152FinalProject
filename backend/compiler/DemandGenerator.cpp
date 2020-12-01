#include <backend/compiler/DemandGenerator.h>
#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "Compiler.h"

namespace backend { namespace compiler {


void DemandGenerator::emitDemand(PurrscalParser::DemandContext *ctx){


}


void DemandGenerator::emitChonkDemand(PurrscalParser::ChonkDemandContext*ctx){


}

void DemandGenerator::emitTrill(PurrscalParser::TrillContext*ctx){


}


void DemandGenerator::emitRollExpectation(PurrscalParser::RollExpectationContext *ctx){


}


void DemandGenerator::emitLoadValue(PurrscalParser::KittenContext*varCtx){


}


Typespec *DemandGenerator::emitLoadKitten(PurrscalParser::KittenContext*varCtx){

	return nullptr;
}


void DemandGenerator::emitLoadIntegerDomestic(PurrscalParser::FelineContext *intCtx){

}


void DemandGenerator::emitLoadRealDomestic(PurrscalParser::FelineContext *realCtx){


}

Typespec *DemandGenerator::emitLoadArrayElementAccess(PurrscalParser::IndicesContext *indexListCtx, Typespec *elmtType, bool lastModifier){

	return nullptr;
}


void DemandGenerator::emitLoadArrayElementValue(Typespec *elmtType){


}


}} // namespace backend::compiler
