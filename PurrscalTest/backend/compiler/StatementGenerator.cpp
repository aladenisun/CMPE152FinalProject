#include <string>
#include <vector>
#include <map>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void StatementGenerator::emitAssignment(PurrscalParser::AssignmentStatementContext *ctx)
{
    PurrscalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PurrscalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
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
    else if (lastModCtx->field() != nullptr)
    {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    }

    // The target variable is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(PurrscalParser::IfStatementContext *ctx)
{
    /***** Angelica's code *****/
	Label *ifExitLabel = new Label();

	compiler->visit(ctx->expression());

	if (ctx->ELSE() != nullptr)
	{
		Label *ifFalseLabel = new Label();
		emit(IFEQ, ifFalseLabel);
		compiler->visit(ctx->trueStatement());
		emit(GOTO, ifExitLabel);
		emitLabel(ifFalseLabel);
		compiler->visit(ctx->falseStatement());
		emitLabel(ifExitLabel);
	}
	else
	{
		emit(IFEQ, ifExitLabel);
		compiler->visit(ctx->trueStatement());
		emitLabel(ifExitLabel);
	}
}

void StatementGenerator::emitCase(PurrscalParser::CaseStatementContext *ctx)
{
    /***** Angelica's code *****/
	compiler->visit(ctx->expression());

	map<int, Label*> labelMap;

	emit(LOOKUPSWITCH);
	for (PurrscalParser::CaseBranchContext *cbCtx : ctx->caseBranchList()->caseBranch())
	{
		if (cbCtx->getText() != "")
		{
			Label *caseLabel = new Label();

			for (PurrscalParser::CaseConstantContext *ccCtx : cbCtx->caseConstantList()->caseConstant())
			{
				labelMap[ccCtx->value] = caseLabel;
			}
		}
	}

	for (auto const& it : labelMap)
	{
		emitLabel(it.first, it.second);
	}

	Label *caseDefaultLabel = new Label();
	emitLabel("default", caseDefaultLabel);

	for (PurrscalParser::CaseBranchContext *cbCtx : ctx->caseBranchList()->caseBranch())
	{
		if (cbCtx->getText() != "")
		{
			Label *caseLabel = labelMap.find(cbCtx->caseConstantList()->caseConstant(0)->value)->second;
			emitLabel(caseLabel);
			compiler->visit(cbCtx->statement());
			emit(GOTO, caseDefaultLabel);
		}
	}
	emitLabel(caseDefaultLabel);
}

void StatementGenerator::emitRepeat(PurrscalParser::RepeatStatementContext *ctx)
{
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->statementList());
    compiler->visit(ctx->expression());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(PurrscalParser::WhileStatementContext *ctx)
{
    /***** Angelica's code *****/
	Label *loopTopLabel = new Label();
	Label *loopExitLabel = new Label();

	emitLabel(loopTopLabel);
	compiler->visit(ctx->expression());
	emit(IFEQ, loopExitLabel);
	compiler->visit(ctx->statement());
	emit(GOTO, loopTopLabel);
	emitLabel(loopExitLabel);
}

void StatementGenerator::emitFor(PurrscalParser::ForStatementContext *ctx)
{
    /*****Angelica's code *****/
	PurrscalParser::VariableContext *varCtx  = ctx->variable();
	PurrscalParser::ExpressionContext *exprStartCtx = ctx->expression(0);
	PurrscalParser::ExpressionContext *exprEndCtx = ctx->expression(1);

	SymtabEntry *varId = varCtx->entry;
	Typespec *varType  = varCtx->type;
	Typespec *exprStartType = exprStartCtx->type;
	Typespec *exprEndType = exprEndCtx->type;

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
	compiler->visit(exprStartCtx);

	// float variable := integer constant
	if (   (varType == Predefined::realType)
		&& (exprStartType->baseType() == Predefined::integerType)) emit(I2F);

	// Emit code to store the expression value into the target variable.
	// The target variable has no subscripts or fields.
	if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

	// The target variable is a field.
	else if (lastModCtx->field() != nullptr)
	{
		emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
	}

	// The target variable is an array element.
	else
	{
		emitStoreValue(nullptr, varType);
	}

	Label *forTopLabel = new Label();
	Label *forExitLabel = new Label();
	Label *forEndLabel = new Label();
	Label *forStatementLabel = new Label();

	emitLabel(forTopLabel);

	compiler->visit(varCtx);
	compiler->visit(exprEndCtx);

	if (ctx->TO() != nullptr)
	{
		emit(IF_ICMPGT, forEndLabel);
	}
	else
	{
		emit(IF_ICMPLT, forEndLabel);
	}

	emit(ICONST_0);
	emit(GOTO, forStatementLabel);
	emitLabel(forEndLabel);
	emit(ICONST_1);
	emitLabel(forStatementLabel);
	emit(IFNE, forExitLabel);
	compiler->visit(ctx->statement());
	compiler->visit(varCtx);
	emit(ICONST_1);

	if (ctx->TO() != nullptr)
	{
		emit(IADD);
	}
	else
	{
		emit(ISUB);
	}

	// float variable := integer constant
	if (   (varType == Predefined::realType)
		&& (exprEndType->baseType() == Predefined::integerType)) emit(I2F);

	// Emit code to store the expression value into the target variable.
	// The target variable has no subscripts or fields.
	if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

	// The target variable is a field.
	else if (lastModCtx->field() != nullptr)
	{
		emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
	}

	// The target variable is an array element.
	else
	{
		emitStoreValue(nullptr, varType);
	}

	emit(GOTO, forTopLabel);

	emitLabel(forExitLabel);
}

void StatementGenerator::emitProcedureCall(PurrscalParser::ProcedureCallStatementContext *ctx)
{
    /***** Angelica's code *****/
	SymtabEntry *routineId = ctx->procedureName()->entry;
	PurrscalParser::ArgumentListContext *argListCtx = ctx->argumentList();

	emitCall(routineId, argListCtx);
}

void StatementGenerator::emitFunctionCall(PurrscalParser::FunctionCallContext *ctx)
{
    /***** Angelica's code *****/
	SymtabEntry *routineId = ctx->functionName()->entry;
	PurrscalParser::ArgumentListContext *argListCtx = ctx->argumentList();

	emitCall(routineId, argListCtx);
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PurrscalParser::ArgumentListContext *argListCtx)
{
    /***** Angelica's code *****/
	string routineArgumentsDescriptor;

	if (argListCtx != nullptr)
	{
		int i = 0;
	    vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
	    for (SymtabEntry *parmId : *parmIds)
	    {
			routineArgumentsDescriptor += typeDescriptor(parmId);
		}

		for (PurrscalParser::ArgumentContext *argCtx : argListCtx->argument())
		{
			compiler->visit(argCtx->expression());

			if (routineArgumentsDescriptor[i] == 'F' && typeDescriptor(argCtx->expression()->type) == "I")
			{
				emit(I2F);
			}
			i++;
		}
	}
	emit(INVOKESTATIC, purrgramName + "/" + routineId->getName() +
				"(" + routineArgumentsDescriptor + ")" + typeDescriptor(routineId));
}

void StatementGenerator::emitMeow(PurrscalParser::MeowStatementContext *ctx)
{
    emitMeow(ctx->meowArguments(), false);
}

void StatementGenerator::emitMrrow(PurrscalParser::MrrowStatementContext *ctx)
{
    emitMeow(ctx->meowArguments(), true);
}

void StatementGenerator::emitMeow(PurrscalParser::MeowArgumentsContext *argsCtx,
                      bool needLF)
{
    emit(GETSTATIC, "java/lang/System/out", "Ljava/io/PrintStream;");

    // MRROW with no arguments.
    if (argsCtx == nullptr)
    {
        emit(INVOKEVIRTUAL, "java/io/PrintStream.println()V");
        localStack->decrease(1);
    }

    // Generate code for the arguments.
    else
    {
        string format;
        int exprCount = createMeowFormat(argsCtx, format, needLF);

        // Load the format string.
        emit(LDC, format);

        // Emit the arguments array.
       if (exprCount > 0)
        {
            emitArgumentsArray(argsCtx, exprCount);

            emit(INVOKEVIRTUAL,
                        string("java/io/PrintStream/printf(Ljava/lang/String;")
                      + string("[Ljava/lang/Object;)")
                      + string("Ljava/io/PrintStream;"));
            localStack->decrease(2);
            emit(POP);
        }
        else
        {
            emit(INVOKEVIRTUAL,
                 "java/io/PrintStream/print(Ljava/lang/String;)V");
            localStack->decrease(2);
        }
    }
}

int StatementGenerator::createMeowFormat(
                                PurrscalParser::MeowArgumentsContext *argsCtx,
                                string& format, bool needLF)
{
    int exprCount = 0;
    format += "\"";

    // Loop over the meow arguments.
    for (PurrscalParser::MeowArgumentContext *argCtx : argsCtx->meowArgument())
    {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            PurrscalParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                               && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                PurrscalParser::DecimalPlacesContext *dpCtx =
                                                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                            : type == Predefined::realType    ? "f"
                            : type == Predefined::booleanType ? "b"
                            : type == Predefined::charType    ? "c"
                            :                                  "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(
                    PurrscalParser::MeowArgumentsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the meow arguments to fill the arguments array.
    for (PurrscalParser::MeowArgumentContext *argCtx :
                                                argsCtx->meowArgument())
    {
        string argText = argCtx->getText();
        PurrscalParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\'')
        {
            emit(DUP);
            emitLoadConstant(index++);

            compiler->visit(exprCtx);

            Form form = type->getForm();
            if (    ((form == SCALAR) || (form == ENUMERATION))
                 && (type != Predefined::stringType))
            {
                emit(INVOKESTATIC, valueOfSignature(type));
            }

            // Store the value into the array.
            emit(AASTORE);
        }
    }
}

void StatementGenerator::emitRead(PurrscalParser::ReadStatementContext *ctx)
{
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(PurrscalParser::ReadlnStatementContext *ctx)
{
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(PurrscalParser::ReadArgumentsContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        PurrscalParser::VariableContext *varCtx = argsCtx->variable()[i];
        Typespec *varType = varCtx->type;

        if (varType == Predefined::integerType)
        {
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextInt()I");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::realType)
        {
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextFloat()F");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::booleanType)
        {
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextBoolean()Z");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::charType)
        {
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(LDC, "\"\"");
            emit(INVOKEVIRTUAL,
                 string("java/util/Scanner/useDelimiter(Ljava/lang/String;)") +
                 string("Ljava/util/Scanner;"));
            emit(POP);
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emit(ICONST_0);
            emit(INVOKEVIRTUAL, "java/lang/String/charAt(I)C");
            emitStoreValue(varCtx->entry, nullptr);

            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/reset()Ljava/util/Scanner;");

        }
        else  // string
        {
            emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emitStoreValue(varCtx->entry, nullptr);
        }
    }

    // READLN: Skip the rest of the input line.
    if (needSkip)
    {
        emit(GETSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
        emit(INVOKEVIRTUAL, "java/util/Scanner/nextLine()Ljava/lang/String;");
        emit(POP);
    }
}

}} // namespace backend::compiler
