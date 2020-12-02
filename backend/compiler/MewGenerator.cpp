#include <backend/compiler/MewGenerator.h>
#include <string>
#include <vector>
#include <map>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void MewGenerator::emitHungryMew(PurrscalParser::HungryMewContext *ctx){

	PurrscalParser::KittenContext *varCtx  = ctx->lps()->kitten();
	PurrscalParser::DemandContext *exprCtx = ctx->rps()->demand();
	SymtabEntry *varId = varCtx->entry;
	Typespec *varType  = varCtx->type;
	Typespec *exprType = exprCtx->type;

	// The last modifier, if any, is the variable's last subscript or field.
	int modifierCount = varCtx->modifier().size();
	PurrscalParser::ModifierContext *lastModCtx = modifierCount == 0
							? nullptr : varCtx->modifier()[modifierCount - 1];

	// The target variable has subscripts and/or fields.
	if (modifierCount > 0)
	{
		lastModCtx = varCtx->modifier()[modifierCount - 1];
		compiler->visit(varCtx);
	}

	// Emit code to evaluate the expression.
	compiler->visit(exprCtx);

	// float variable := integer constant
	if (   (varType == Predefined::realType)
		&& (exprType->baseType() == Predefined::integerType)) emit(I2F);

	// Emit code to store the expression value into the target variable.
	// The target variable has no subscripts or fields.
	if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

	// The target variable is a field.
	else if (lastModCtx->chungus()!= nullptr)
	{
		emitStoreValue(lastModCtx->chungus()->entry, lastModCtx->chungus()->type);
	}

	// The target variable is an array element.
	else
	{
		emitStoreValue(nullptr, varType);
	}
}

// emit code for an IF statement, param ctx is the IfStatementContext
// Yosef's code below, beware ye who enter
void MewGenerator::emitSniff(PurrscalParser::SniffMewContext*ctx) {


}

void MewGenerator::emitHowl(PurrscalParser::HowlMewContext *ctx){

}

void MewGenerator::emitPurr(PurrscalParser::PurrMewContext *ctx){

}

void MewGenerator::emitYowlCall(PurrscalParser::YowlCallMewContext*ctx){

}

void MewGenerator::emitBlepCall(PurrscalParser::BlepCallContext*ctx){

}

void MewGenerator::emitMeow(PurrscalParser::MeowMewContext *ctx){

}

void MewGenerator::emitMrrr(PurrscalParser::MrrrMewContext*ctx){

}

void MewGenerator::emitRead(PurrscalParser::StalkMewContext *ctx){

}


void MewGenerator::emitReadln(PurrscalParser::PounceMewContext*ctx){

}

void MewGenerator::emitCall(SymtabEntry *routineId, PurrscalParser::ChirpContext *argListCtx){

}

void MewGenerator::emitWrite(PurrscalParser::MeowsContext *argsCtx, bool needLF){

}


int MewGenerator::createWriteFormat(PurrscalParser::MeowsContext *argsCtx, string& format, bool needLF){


	return 0;
}

void MewGenerator::emitArgumentsArray(PurrscalParser::MeowsContext *argsCtx, int exprCount){

}

void MewGenerator::emitRead(PurrscalParser::MrowusContext *argsCtx, bool needSkip){

}

}} // namespace backend::compiler
