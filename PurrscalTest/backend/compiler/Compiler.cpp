#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

Object Compiler::visitPurrgram(PurrscalParser::PurrgramContext *ctx)
{
    createNewGenerators(code);
    purrgramCode->emitPurrgram(ctx);
    return nullptr;
}

Object Compiler::visitCallBody(
                                PurrscalParser::CallBodyContext *ctx)
{
    createNewGenerators(purrgramCode);
    purrgramCode->emitRoutine(ctx);
    return nullptr;
}

Object Compiler::visitMew(PurrscalParser::MewContext *ctx)
{
    if (   (ctx->theBigMew() == nullptr)
        && (ctx->blankStare() == nullptr))
    {
        statementCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitHungryMew(
                                PurrscalParser::HungryMewContext *ctx)
{
    statementCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitSniffMew(PurrscalParser::SniffMewContext *ctx)
{
    statementCode->emitIf(ctx);
    return nullptr;
}


Object Compiler::visitHowlMew(PurrscalParser::HowlMewContext *ctx)
{
    statementCode->emitRepeat(ctx);
    return nullptr;
}

Object Compiler::visitPurrMew(PurrscalParser::PurrMewContext *ctx)
{
    statementCode->emitWhile(ctx);
    return nullptr;
}

Object Compiler::visitYowlCallMew(
                            PurrscalParser::YowlCallMewContext *ctx)
{
    statementCode->emitProcedureCall(ctx);
    return nullptr;
}

Object Compiler::visitDemand(PurrscalParser::DemandContext *ctx)
{
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitKittenExpectation(PurrscalParser::KittenExpectationContext *ctx)
{
    expressionCode->emitLoadValue(ctx->kitten());
    return nullptr;
}

Object Compiler::visitKitten(PurrscalParser::KittenContext *ctx)
{
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx)
{
    if (ctx->type == Predefined::integerType)
    {
        expressionCode->emitLoadIntegerConstant(ctx->feline());
    }
    else
    {
        expressionCode->emitLoadRealConstant(ctx->feline());
    }

    return nullptr;
}

Object Compiler::visitThreadBallExpectation(PurrscalParser::ThreadBallExpectationContext *ctx)
{
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitYarnBallExpectation(PurrscalParser::YarnBallExpectationContext *ctx)
{
    string jasminString = convertString(ctx->getText(), true);
    expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitBlepCallExpectation(
                                PurrscalParser::BlepCallExpectationContext *ctx)
{
    statementCode->emitFunctionCall(ctx->blepCall());
    return nullptr;
}

Object Compiler::visitRollExpectation(PurrscalParser::RollExpectationContext *ctx)
{
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedExpectation(
                                PurrscalParser::ParenthesizedExpectationContext *ctx)
{
    return visit(ctx->demand());
}

Object Compiler::visitMeowMew(PurrscalParser::MeowMewContext *ctx)
{
    statementCode->emitMeow(ctx);
    return nullptr;
}

Object Compiler::visitMrrrMew(PurrscalParser::MrrrMewContext *ctx)
{
    statementCode->emitMrrow(ctx);
    return nullptr;
}

Object Compiler::visitStalkMew(PurrscalParser::StalkMewContext *ctx)
{
    statementCode->emitRead(ctx);
    return nullptr;
}

Object Compiler::visitPounceMew(PurrscalParser::PounceMewContext *ctx)
{
    statementCode->emitReadln(ctx);
    return nullptr;
}

}}  // namespace backend::compiler
