#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

Object Compiler::visitPurrgram(PurrscalParser::PurrgramContext *ctx) {

	createNewGenerators(code);
	purrgramCode->emitPurrgram(ctx);
	return nullptr;

}


Object Compiler::visitCallBody(PurrscalParser::CallBodyContext *ctx){

	createNewGenerators(purrgramCode);
	purrgramCode->emitCall(ctx);
	return nullptr;

}

Object Compiler::visitMew(PurrscalParser::MewContext *ctx) {

	if (   (ctx->theBigMew() == nullptr)
			&& (ctx->blankStare() == nullptr))
	{
		mewCode->emitComment(ctx);
	}

	return visitChildren(ctx);
}


Object Compiler::visitHungryMew(PurrscalParser::HungryMewContext *ctx) {
	mewCode->emitHungryMew(ctx);
	return nullptr;
}


Object Compiler::visitSniffMew(PurrscalParser::SniffMewContext *ctx) {
	mewCode->emitSnif(ctx);
	return nullptr;
}

Object Compiler::visitHowlMew(PurrscalParser::HowlMewContext*ctx) {
	mewCode->emitHowl(ctx);
	return nullptr;
}

Object Compiler::visitPurrMew(PurrscalParser::PurrMewContext*ctx){
	mewCode->emitPurr(ctx);
	return nullptr;

}

Object Compiler::visitYowlCallMew(PurrscalParser::YowlCallMewContext*ctx) {
	mewCode->emitYowlCall(ctx);
	return nullptr;
}


Object Compiler::visitDemand(PurrscalParser::DemandContext *ctx) {
	demandCode->emitDemand(ctx);
	return nullptr;

}

Object Compiler::visitKittenExpectation(PurrscalParser::KittenExpectationContext*ctx) {
	demandCode->emitLoadValue(ctx->kitten());
	return nullptr;

}

Object Compiler::visitKitten(PurrscalParser::KittenContext*ctx) {

	demandCode->emitLoadKitten(ctx);
	return nullptr;

}

Object Compiler::visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx) {

	if (ctx->type == Predefined::integerType)
	{
		demandCode->emitLoadIntegerDomestic(ctx->feline());
	}
	else
	{
		demandCode->emitLoadRealDomestic(ctx->feline());
	}

	return nullptr;

}

Object Compiler::visitThreadExpectation(PurrscalParser::ThreadExpectationContext *ctx) {
	char ch = ctx->getText()[1];
	demandCode->emitLoadDomestic(ch);

	return nullptr;

}

Object Compiler::visitYarnExpectation(PurrscalParser::YarnExpectationContext *ctx) {

	string jasminString = convertString(ctx->getText(), true);
	demandCode->emitLoadDomestic(jasminString);

	return nullptr;

}

Object Compiler::visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *ctx) {

	mewCode->emitBlepCall(ctx->blepCall());
	return nullptr;

}

Object Compiler::visitRollExpectation(PurrscalParser::RollExpectationContext*ctx) {
	demandCode->emitRollExpectation(ctx);
	return nullptr;

}

Object Compiler::visitParenthesizedExpectation(PurrscalParser::ParenthesizedExpectationContext *ctx) {

	return visit(ctx->demand());
}

Object Compiler::visitMeowMew(PurrscalParser::MeowMewContext *ctx) {
	mewCode->emitMeow(ctx);
	return nullptr;

}

Object Compiler::visitMrrrMew(PurrscalParser::MrrrMewContext *ctx){
	mewCode->emitMrrr(ctx);
	return nullptr;

}
Object Compiler::visitStalkMew(PurrscalParser::StalkMewContext *ctx) {
	mewCode->emitStalk(ctx);
	return nullptr;

}

Object Compiler::visitPounceMew(PurrscalParser::PounceMewContext *ctx) {
	mewCode->emitPounce(ctx);
	return nullptr;

}

}}  // namespace backend::compiler
