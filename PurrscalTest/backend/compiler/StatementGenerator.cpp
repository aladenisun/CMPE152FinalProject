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

void StatementGenerator::emitAssignment(PurrscalParser::HungryMewContext *ctx)
{
    PurrscalParser::KittenContext *varCtx  = ctx->lps()->kitten();
    PurrscalParser::DemandContext *exprCtx = ctx->rps()->demand();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the kitten's last subscript or chungus.
    int modifierCount = varCtx->modifier().size();
    PurrscalParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target kitten has subscripts and/or chunguss.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float kitten := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target kitten.
    // The target kitten has no subscripts or chunguss.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

    // The target kitten is a chungus.
    else if (lastModCtx->chungus() != nullptr)
    {
        emitStoreValue(lastModCtx->chungus()->entry, lastModCtx->chungus()->type);
    }

    // The target kitten is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(PurrscalParser::SniffMewContext *ctx)
{
    /***** Angelica's code *****/
	Label *ifExitLabel = new Label();

	compiler->visit(ctx->demand());

	if (ctx->IGNORE() != nullptr)
	{
		Label *ifFalseLabel = new Label();
		emit(IFEQ, ifFalseLabel);
		compiler->visit(ctx->pawMew());
		emit(GOTO, ifExitLabel);
		emitLabel(ifFalseLabel);
		compiler->visit(ctx->ignoreMew());
		emitLabel(ifExitLabel);
	}
	else
	{
		emit(IFEQ, ifExitLabel);
		compiler->visit(ctx->pawMew());
		emitLabel(ifExitLabel);
	}
}


void StatementGenerator::emitRepeat(PurrscalParser::HowlMewContext *ctx)
{
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->mews());
    compiler->visit(ctx->demand());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(PurrscalParser::PurrMewContext *ctx)
{
    /***** Angelica's code *****/
	Label *loopTopLabel = new Label();
	Label *loopExitLabel = new Label();

	emitLabel(loopTopLabel);
	compiler->visit(ctx->demand());
	emit(IFEQ, loopExitLabel);
	compiler->visit(ctx->mew());
	emit(GOTO, loopTopLabel);
	emitLabel(loopExitLabel);
}

void StatementGenerator::emitProcedureCall(PurrscalParser::YowlCallMewContext *ctx)
{
    /***** Angelica's code *****/
	SymtabEntry *routineId = ctx->yowlName()->entry;
	PurrscalParser::ChirpsContext *argListCtx = ctx->chirps();

	emitCall(routineId, argListCtx);
}

void StatementGenerator::emitFunctionCall(PurrscalParser::BlepCallContext *ctx)
{
    /***** Angelica's code *****/
	SymtabEntry *routineId = ctx->blepName()->entry;
	PurrscalParser::ChirpsContext *argListCtx = ctx->chirps();

	emitCall(routineId, argListCtx);
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PurrscalParser::ChirpsContext *argListCtx)
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

		for (PurrscalParser::ChirpContext *argCtx : argListCtx->chirp())
		{
			compiler->visit(argCtx->demand());

			if (routineArgumentsDescriptor[i] == 'F' && typeDescriptor(argCtx->demand()->type) == "I")
			{
				emit(I2F);
			}
			i++;
		}
	}
	emit(INVOKESTATIC, purrgramName + "/" + routineId->getName() +
				"(" + routineArgumentsDescriptor + ")" + typeDescriptor(routineId));
}

void StatementGenerator::emitMeow(PurrscalParser::MeowMewContext *ctx)
{
    emitMeow(ctx->meows(), false);
}

void StatementGenerator::emitMrrow(PurrscalParser::MrrrMewContext *ctx)
{
    emitMeow(ctx->meows(), true);
}

void StatementGenerator::emitMeow(PurrscalParser::MeowsContext *argsCtx,
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
                                PurrscalParser::MeowsContext *argsCtx,
                                string& format, bool needLF)
{
    int exprCount = 0;
    format += "\"";

    // Loop over the meow arguments.
    for (PurrscalParser::MeowContext *argCtx : argsCtx->meow())
    {
        Typespec *type = argCtx->demand()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a Chungus specifier.
        else
        {
            exprCount++;
            format.append("%");

            PurrscalParser::ChungusWidthContext *fwCtx = argCtx->chungusWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->fur() != nullptr)
                               && (fwCtx->fur()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->sphynxDomestic()->getText();

                PurrscalParser::ToeBeanPlacesContext *dpCtx =
                                                        fwCtx->toeBeanPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->sphynxDomestic()->getText();
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
                    PurrscalParser::MeowsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the meow arguments to fill the arguments array.
    for (PurrscalParser::MeowContext *argCtx :
                                                argsCtx->meow())
    {
        string argText = argCtx->getText();
        PurrscalParser::DemandContext *exprCtx = argCtx->demand();
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

void StatementGenerator::emitRead(PurrscalParser::StalkMewContext *ctx)
{
    emitRead(ctx->mrowus(), false);
}

void StatementGenerator::emitReadln(PurrscalParser::PounceMewContext *ctx)
{
    emitRead(ctx->mrowus(), true);
}

void StatementGenerator::emitRead(PurrscalParser::MrowusContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->kitten().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        PurrscalParser::KittenContext *varCtx = argsCtx->kitten()[i];
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
