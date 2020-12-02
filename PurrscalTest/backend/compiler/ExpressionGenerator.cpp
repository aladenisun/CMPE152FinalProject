#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "Compiler.h"

namespace backend { namespace compiler {

void ExpressionGenerator::emitExpression(PurrscalParser::DemandContext *ctx)
{
    PurrscalParser::ChonkDemandContext *simpleCtx1 =
                                            ctx->chonkDemand()[0];
    PurrscalParser::RelationalWhiskerContext *relOpCtx = ctx->relationalWhisker();
    Typespec *type1 = simpleCtx1->type;
    emitSimpleExpression(simpleCtx1);

    // More than one simple expression?
    if (relOpCtx != nullptr)
    {
        string op = relOpCtx->getText();
        PurrscalParser::ChonkDemandContext *simpleCtx2 =
                                            ctx->chonkDemand()[1];
        Typespec *type2 = simpleCtx2->type;

        bool integerMode   = false;
        bool realMode      = false;
        bool characterMode = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }
        else if (   (type1 == Predefined::charType)
                 && (type2 == Predefined::charType))
        {
            characterMode = true;
        }

        Label *trueLabel = new Label();
        Label *exitLabel = new Label();

        if (integerMode || characterMode)
        {
            emitSimpleExpression(simpleCtx2);

            if      (op == "=" ) emit(IF_ICMPEQ, trueLabel);
            else if (op == "<>") emit(IF_ICMPNE, trueLabel);
            else if (op == "<" ) emit(IF_ICMPLT, trueLabel);
            else if (op == "<=") emit(IF_ICMPLE, trueLabel);
            else if (op == ">" ) emit(IF_ICMPGT, trueLabel);
            else if (op == ">=") emit(IF_ICMPGE, trueLabel);
        }
        else if (realMode)
        {
            if (type1 == Predefined::integerType) emit(I2F);
            emitSimpleExpression(simpleCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            emit(FCMPG);

            if      (op == "=" ) emit(IFEQ, trueLabel);
            else if (op == "<>") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }
        else  // stringMode
        {
            emitSimpleExpression(simpleCtx2);
            emit(INVOKEVIRTUAL,
                 "java/lang/String.compareTo(Ljava/lang/String;)I");
            localStack->decrease(1);

            if      (op == "=" ) emit(IFEQ, trueLabel);
            else if (op == "<>") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }

        emit(ICONST_0); // false
        emit(GOTO, exitLabel);
        emitLabel(trueLabel);
        emit(ICONST_1); // true
        emitLabel(exitLabel);

        localStack->decrease(1);  // only one branch will be taken
    }
}

void ExpressionGenerator::emitSimpleExpression(PurrscalParser::ChonkDemandContext *ctx)
{
    int count = ctx->trill().size();
    bool negate =    (ctx->fur() != nullptr)
                  && (ctx->fur()->getText() == "-");

    // First term.
    PurrscalParser::TrillContext *termCtx1 = ctx->trill()[0];
    Typespec *type1 = termCtx1->type;
    emitTerm(termCtx1);

    if (negate) emit(type1 == Predefined::integerType ? INEG : FNEG);

    // Loop over the subsequent terms.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->additiveWhisker()[i-1]->getText());
        PurrscalParser::TrillContext *termCtx2 = ctx->trill()[i];
        Typespec *type2 = termCtx2->type;

        bool integerMode = false;
        bool realMode    = false;
        bool booleanMode = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }
        else if (   (type1 == Predefined::booleanType)
                 && (type2 == Predefined::booleanType))
        {
            booleanMode = true;
        }

        if (integerMode)
        {
            emitTerm(termCtx2);

            if (op == "+") emit(IADD);
            else           emit(ISUB);
//            localStack->decrease(1);
        }
        else if (realMode)
        {
            if (type1 == Predefined::integerType) emit(I2F);
            emitTerm(termCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if (op == "+") emit(FADD);
            else           emit(FSUB);
        }
        else if (booleanMode)
        {
            emitTerm(termCtx2);
            emit(IOR);
        }
        else  // stringMode
        {
            emit(NEW, "java/lang/StringBuilder");
            emit(DUP_X1);
            emit(SWAP);
            emit(INVOKESTATIC,
                 string("java/lang/String/valueOf(Ljava/lang/Object;)") +
                 string("Ljava/lang/String;"));
            emit(INVOKESPECIAL,
                 string("java/lang/StringBuilder/<init>") +
                 string("(Ljava/lang/String;)V"));
            localStack->decrease(1);

            emitTerm(termCtx2);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/append(Ljava/lang/String;)") +
                 string("Ljava/lang/StringBuilder;"));
            localStack->decrease(1);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/toString()") +
                 string("Ljava/lang/String;"));
            localStack->decrease(1);
        }
    }
}

void ExpressionGenerator::emitTerm(PurrscalParser::TrillContext *ctx)
{
    int count = ctx->expectation().size();

    // First factor.
    PurrscalParser::ExpectationContext *factorCtx1 = ctx->expectation()[0];
    Typespec *type1 = factorCtx1->type;
    compiler->visit(factorCtx1);

    // Loop over the subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->multiplicativeWhisker()[i-1]->getText());
        PurrscalParser::ExpectationContext *factorCtx2 = ctx->expectation()[i];
        Typespec *type2 = factorCtx2->type;

        bool integerMode = false;
        bool realMode    = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }

        if (integerMode)
        {
            compiler->visit(factorCtx2);

            if      (op == "*")   emit(IMUL);
            else if (op == "/")   emit(FDIV);
        }
        else if (realMode)
        {
            if (type1 == Predefined::integerType) emit(I2F);
            compiler->visit(factorCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if      (op == "*") emit(FMUL);
            else if (op == "/") emit(FDIV);
        }
        else  // booleanMode
        {
            compiler->visit(factorCtx2);
            emit(IAND);
        }
    }
}

void ExpressionGenerator::emitNotFactor(PurrscalParser::RollExpectationContext *ctx)
{
    compiler->visit(ctx->expectation());
    emit(ICONST_1);
    emit(IXOR);
}

void ExpressionGenerator::emitLoadValue(PurrscalParser::KittenContext *varCtx)
{
    // Load the scalar value or structure address.
    Typespec *variableType = emitLoadVariable(varCtx);

    // Load an array element's value.
    int modifierCount = varCtx->modifier().size();
    if (modifierCount > 0)
    {
        PurrscalParser::ModifierContext *lastModCtx =
                                        varCtx->modifier()[modifierCount - 1];

        if (lastModCtx->indices() != nullptr)
        {
            emitLoadArrayElementValue(variableType);
        }

    }
}

Typespec *ExpressionGenerator::emitLoadVariable(
                                        PurrscalParser::KittenContext *varCtx)
{
    SymtabEntry *variableId = varCtx->entry;
    Typespec *variableType = variableId->getType();
    int modifierCount = varCtx->modifier().size();

    // Scalar value or structure address.
    CodeGenerator::emitLoadValue(variableId);  // why need CodeGenerator::?

    // Loop over subscript and field modifiers.
    for (int i = 0; i < modifierCount; ++i)
    {
        PurrscalParser::ModifierContext *modCtx = varCtx->modifier()[i];
        bool lastModifier = i == modifierCount - 1;

        // Subscript
        if (modCtx->indices() != nullptr)
        {
            variableType = emitLoadArrayElementAccess(
                            modCtx->indices(), variableType, lastModifier);
        }

    }

    return variableType;
}

Typespec *ExpressionGenerator::emitLoadArrayElementAccess(
                                PurrscalParser::IndicesContext *indexListCtx,
                                Typespec *elmtType, bool lastModifier)
{
    int indexCount = indexListCtx->index().size();

    // Loop over the subscripts.
    for (int i = 0; i < indexCount; i++)
    {
        PurrscalParser::IndexContext *indexCtx = indexListCtx->index()[i];
        emitExpression(indexCtx->demand());

        Typespec *indexType = elmtType->getArrayIndexType();

        if (indexType->getForm() == SUBRANGE)
        {
            int min = indexType->getSubrangeMinValue();
            if (min != 0)
            {
                emitLoadConstant(min);
                emit(ISUB);
            }
        }

        if (!lastModifier || (i < indexCount - 1)) emit(AALOAD);
        elmtType = elmtType->getArrayElementType();
    }

    return elmtType;
}

void ExpressionGenerator::emitLoadArrayElementValue(Typespec *elmtType)
{
    Form form = SCALAR;

    if (elmtType != nullptr)
    {
        elmtType = elmtType->baseType();
        form = elmtType->getForm();
    }

    // Load a character from a string.
    if (elmtType == Predefined::charType)
    {
        emit(INVOKEVIRTUAL, "java/lang/StringBuilder.charAt(I)C");
    }

    // Load an array element.
    else
    {
        emit(  elmtType == Predefined::integerType ? IALOAD
             : elmtType == Predefined::realType    ? FALOAD
             : elmtType == Predefined::booleanType ? BALOAD
             : elmtType == Predefined::charType    ? CALOAD
             : form == ENUMERATION                 ? IALOAD
             :                                       AALOAD);
    }
}

void ExpressionGenerator::emitLoadIntegerConstant(PurrscalParser::FelineContext *intCtx)
{
    int value = stoi(intCtx->getText());
    emitLoadConstant(value);
}

void ExpressionGenerator::emitLoadRealConstant(PurrscalParser::FelineContext *realCtx)
{
    float value = stof(realCtx->getText());
    emitLoadConstant(value);
}

}} // namespace backend::compiler
