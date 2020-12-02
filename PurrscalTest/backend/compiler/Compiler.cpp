#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

Object Compiler::visitPurrgram(PurrscalParser::PurrgramContext *ctx)
{
    createNewGenerators(code);
    purrgramCode->emitPurrgram(ctx);
    return nullptr;
}

Object Compiler::visitRoutineDefinition(
                                PurrscalParser::RoutineDefinitionContext *ctx)
{
    createNewGenerators(purrgramCode);
    purrgramCode->emitRoutine(ctx);
    return nullptr;
}

Object Compiler::visitStatement(PurrscalParser::StatementContext *ctx)
{
    if (   (ctx->theBigMew() == nullptr)
        && (ctx->emptyStatement() == nullptr))
    {
        statementCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitAssignmentStatement(
                                PurrscalParser::AssignmentStatementContext *ctx)
{
    statementCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitIfStatement(PurrscalParser::IfStatementContext *ctx)
{
    statementCode->emitIf(ctx);
    return nullptr;
}

Object Compiler::visitCaseStatement(PurrscalParser::CaseStatementContext *ctx)
{
    statementCode->emitCase(ctx);
    return nullptr;
}

Object Compiler::visitRepeatStatement(PurrscalParser::RepeatStatementContext *ctx)
{
    statementCode->emitRepeat(ctx);
    return nullptr;
}

Object Compiler::visitWhileStatement(PurrscalParser::WhileStatementContext *ctx)
{
    statementCode->emitWhile(ctx);
    return nullptr;
}

Object Compiler::visitForStatement(PurrscalParser::ForStatementContext *ctx)
{
    statementCode->emitFor(ctx);
    return nullptr;
}

Object Compiler::visitProcedureCallStatement(
                            PurrscalParser::ProcedureCallStatementContext *ctx)
{
    statementCode->emitProcedureCall(ctx);
    return nullptr;
}

Object Compiler::visitExpression(PurrscalParser::ExpressionContext *ctx)
{
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitVariableFactor(PurrscalParser::VariableFactorContext *ctx)
{
    expressionCode->emitLoadValue(ctx->variable());
    return nullptr;
}

Object Compiler::visitVariable(PurrscalParser::VariableContext *ctx)
{
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitNumberFactor(PurrscalParser::NumberFactorContext *ctx)
{
    if (ctx->type == Predefined::integerType)
    {
        expressionCode->emitLoadIntegerConstant(ctx->number());
    }
    else
    {
        expressionCode->emitLoadRealConstant(ctx->number());
    }

    return nullptr;
}

Object Compiler::visitCharacterFactor(PurrscalParser::CharacterFactorContext *ctx)
{
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitStringFactor(PurrscalParser::StringFactorContext *ctx)
{
    string jasminString = convertString(ctx->getText(), true);
    expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(
                                PurrscalParser::FunctionCallFactorContext *ctx)
{
    statementCode->emitFunctionCall(ctx->functionCall());
    return nullptr;
}

Object Compiler::visitNotFactor(PurrscalParser::NotFactorContext *ctx)
{
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedFactor(
                                PurrscalParser::ParenthesizedFactorContext *ctx)
{
    return visit(ctx->expression());
}

Object Compiler::visitMeowStatement(PurrscalParser::MeowStatementContext *ctx)
{
    statementCode->emitMeow(ctx);
    return nullptr;
}

Object Compiler::visitMrrowStatement(PurrscalParser::MrrowStatementContext *ctx)
{
    statementCode->emitMrrow(ctx);
    return nullptr;
}

Object Compiler::visitReadStatement(PurrscalParser::ReadStatementContext *ctx)
{
    statementCode->emitRead(ctx);
    return nullptr;
}

Object Compiler::visitReadlnStatement(PurrscalParser::ReadlnStatementContext *ctx)
{
    statementCode->emitReadln(ctx);
    return nullptr;
}

}}  // namespace backend::compiler
