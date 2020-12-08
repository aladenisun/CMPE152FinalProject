#include <vector>
#include <set>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/util/CrossReferencer.h"
#include "SemanticErrorHandler.h"
#include "Semantics.h"

namespace intermediate { namespace symtab {
    int Symtab::unnamedIndex = 0;
}}

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;
using namespace intermediate::util;

Object Semantics::visitPurrgram(PurrscalParser::PurrgramContext *ctx)
{
    visit(ctx->purrgramSnoot());
    visit(ctx->cat()->catQualities());
    visit(ctx->cat()->theBigMew());

    // Print the cross-reference table.
    CrossReferencer crossReferencer;
    crossReferencer.print(symtabStack);

    return nullptr;
}

Object Semantics::visitPurrgramSnoot(PurrscalParser::PurrgramSnootContext *ctx)
{
    PurrscalParser::PurrgramKittyContext *idCtx = ctx->purrgramKitty();
    string purrgramName = idCtx->KITTY()->getText();  // don't shift case

    purrgramId = symtabStack->enterLocal(purrgramName, PURRGRAM);
    purrgramId->setRoutineSymtab(symtabStack->push());

    symtabStack->setPurrgramId(purrgramId);
    symtabStack->getLocalSymtab()->setOwner(purrgramId);

    idCtx->entry = purrgramId;
    return nullptr;
}

Object Semantics::visitDomesticBody(
                                PurrscalParser::DomesticBodyContext *ctx)
{
    PurrscalParser::DomesticKittyContext *idCtx = ctx->domesticKitty();
    string constantName = toLowerCase(idCtx->KITTY()->getText());
    SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

    if (constantId == nullptr)
    {
        PurrscalParser::DomesticContext *constCtx = ctx->domestic();
        Object constValue = visit(constCtx);

        constantId = symtabStack->enterLocal(constantName, CONSTANT);
        constantId->setValue(constValue);
        constantId->setType(constCtx->type);

        idCtx->entry = constantId;
        idCtx->type  = constCtx->type;
    }
    else
    {
        error.flag(REDECLARED_KITTY, ctx);

        idCtx->entry = constantId;
        idCtx->type  = Predefined::integerType;
    }

    constantId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitDomestic(PurrscalParser::DomesticContext *ctx)
{
    if (ctx->KITTY() != nullptr)
    {
        string constantName = toLowerCase(ctx->KITTY()->getText());
        SymtabEntry *constantId = symtabStack->lookup(constantName);

        if (constantId != nullptr)
        {
            Kind kind = constantId->getKind();
            if ((kind != CONSTANT) && (kind != ENUMERATION_CONSTANT))
            {
                error.flag(INVALID_CONSTANT, ctx);
            }

            ctx->type  = constantId->getType();
            ctx->value = constantId->getValue();

            constantId->appendLineNumber(ctx->getStart()->getLine());
        }
        else
        {
            error.flag(UNDECLARED_KITTY, ctx);
            ctx->type = Predefined::integerType;
            ctx->value = 0;
        }
    }
    else if (ctx->threadBall() != nullptr)
    {
        ctx->type = Predefined::charType;
        ctx->value = ctx->getText()[1];
    }
    else if (ctx->yarnBall() != nullptr)
    {
        string purrscalString = ctx->yarnBall()->YARN()->getText();
        string unquoted = purrscalString.substr(1, purrscalString.length()-2);

        size_t pos = 0;
        while ((pos = unquoted.find("''", pos)) != string::npos)
        {
            unquoted.replace(pos++, 2, "'");
        }

        pos = 0;
        while ((pos = unquoted.find("\"", pos)) != string::npos)
        {
            unquoted.replace(pos++, 2, "\\\"");
        }

        ctx->type = Predefined::stringType;
        ctx->value = new string(unquoted);
    }
    else  // number
    {
        PurrscalParser::HairlessFelineContext *unsignedCtx = ctx->hairlessFeline();

        if (unsignedCtx->sphynxDomestic() != nullptr)
        {
            ctx->type = Predefined::integerType;
            ctx->value = stoi(ctx->getText());
        }
        else
        {
            ctx->type = Predefined::realType;
            ctx->value = stod(ctx->getText());
        }
    }

    return ctx->value;
}

Object Semantics::visitBreedBody(PurrscalParser::BreedBodyContext *ctx)
{
    PurrscalParser::KittyBreedContext *idCtx = ctx->kittyBreed();
    string typeName = toLowerCase(idCtx->KITTY()->getText());
    SymtabEntry *typeId = symtabStack->lookupLocal(typeName);

    PurrscalParser::BreedContext *typespecCtx =
                                                    ctx->breed();

    if (typeId == nullptr)
    {
        PurrscalParser::BreedContext *typeCtx =
                                                    ctx->breed();
        visit(typeCtx);

        typeId = symtabStack->enterLocal(typeName, BREED);
        typeId->setType(typeCtx->type);
        typeCtx->type->setIdentifier(typeId);
    }
    else
    {
        error.flag(REDECLARED_KITTY, ctx);
    }

    idCtx->entry = typeId;
    idCtx->type  = typespecCtx->type;

    typeId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitChonkspec(PurrscalParser::ChonkspecContext *ctx)
{
    visit(ctx->chonk());
    ctx->type = ctx->chonk()->type;

    return nullptr;
}

Object Semantics::visitKittyBreedspec(
                            PurrscalParser::KittyBreedspecContext *ctx)
{
    visit(ctx->kittyBreed());
    ctx->type = ctx->kittyBreed()->type;

    return nullptr;
}

Object Semantics::visitKittyBreed(PurrscalParser::KittyBreedContext *ctx)
{
    string typeName = toLowerCase(ctx->KITTY()->getText());
    SymtabEntry *typeId = symtabStack->lookup(typeName);

    if (typeId != nullptr)
    {
        if (typeId->getKind() != BREED)
        {
            error.flag(INVALID_TYPE, ctx);
            ctx->type = Predefined::integerType;
        }
        else
        {
            ctx->type = typeId->getType();
        }

        typeId->appendLineNumber(ctx->start->getLine());
    }
    else
    {
        error.flag(UNDECLARED_KITTY, ctx);
        ctx->type = Predefined::integerType;
    }

    ctx->entry = typeId;
    return nullptr;
}

Object Semantics::visitFluffballspec(
                                PurrscalParser::FluffballspecContext *ctx)
{
    Typespec *enumType = new Typespec(ENUMERATION);
    vector<SymtabEntry *> *constants = new vector<SymtabEntry *>();
    int value = -1;

    // Loop over the enumeration constants.
    for (PurrscalParser::FluffballDomesticContext *constCtx :
                                ctx->fluffball()->fluffballDomestic())
    {
        PurrscalParser::DomesticKittyContext *constIdCtx =
                                                constCtx->domesticKitty();
        string constantName = toLowerCase(constIdCtx->KITTY()->getText());
        SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

        if (constantId == nullptr)
        {
            constantId = symtabStack->enterLocal(constantName,
                                                 ENUMERATION_CONSTANT);
            constantId->setType(enumType);
            constantId->setValue(++value);

            constants->push_back(constantId);
        }
        else
        {
            error.flag(REDECLARED_KITTY, constCtx);
        }

        constIdCtx->entry = constantId;
        constIdCtx->type  = enumType;

        constantId->appendLineNumber(ctx->getStart()->getLine());
    }

    enumType->setEnumerationConstants(constants);
    ctx->type = enumType;

    return nullptr;
}

Object Semantics::visitKittenKaboodleBasketspec(
                                    PurrscalParser::KittenKaboodleBasketspecContext *ctx)
{
    Typespec *type = new Typespec(SUBRANGE);
    PurrscalParser::KittenKaboodleBasketContext *subCtx = ctx->kittenKaboodleBasket();
    PurrscalParser::DomesticContext *minCtx = subCtx->domestic()[0];
    PurrscalParser::DomesticContext *maxCtx = subCtx->domestic()[1];

    Object minObj = visit(minCtx);
    Object maxObj = visit(maxCtx);

    Typespec *minType = minCtx->type;
    Typespec *maxType = maxCtx->type;

    if (   (   (minType->getForm() != SCALAR)
    		&& (minType->getForm() != ENUMERATION))
        || (minType == Predefined::realType)
        || (minType == Predefined::stringType))
    {
        error.flag(INVALID_CONSTANT, minCtx);
        minType = Predefined::integerType;
        minObj  = 0;
    }

    int minValue;
    int maxValue;

    if (minType == Predefined::integerType)
    {
    	minValue = minObj.as<int>();
    	maxValue = maxObj.as<int>();
    }
    else if (minType == Predefined::charType)
    {
    	minValue = minObj.as<char>();
    	maxValue = maxObj.as<char>();
    }
    else  // enumeration constants
    {
    	minValue = minCtx->value.as<int>();
    	maxValue = maxCtx->value.as<int>();
    }

    if ((maxType != minType) || (minValue > maxValue))
    {
        error.flag(INVALID_CONSTANT, maxCtx);
        maxType = minType;
        maxObj  = minObj;
    }

    type->setSubrangeBaseType(minType);
    type->setSubrangeMinValue(minValue);
    type->setSubrangeMaxValue(maxValue);

    ctx->type = type;
    return nullptr;
}

Object Semantics::visitKaboodlespec(PurrscalParser::KaboodlespecContext *ctx)
{
    Typespec *arrayType = new Typespec(KABOODLE);
    PurrscalParser::KaboodleContext *arrayCtx = ctx->kaboodle();
    PurrscalParser::KittenKaboodleContext *listCtx =
                                                arrayCtx->kittenKaboodle();

    ctx->type = arrayType;

    // Loop over the array dimensions.
    int count = listCtx->chonk().size();
    for (int i = 0; i < count; i++)
    {
        PurrscalParser::ChonkContext *simpleCtx = listCtx->chonk()[i];
        visit(simpleCtx);
        arrayType->setArrayIndexType(simpleCtx->type);
        arrayType->setArrayElementCount(typeCount(simpleCtx->type));

        if (i < count-1)
        {
            Typespec *elmtType = new Typespec(KABOODLE);
            arrayType->setArrayElementType(elmtType);
            arrayType = elmtType;
        }
    }

    visit(arrayCtx->breed());
    Typespec *elmtType = arrayCtx->breed()->type;
    arrayType->setArrayElementType(elmtType);

    return nullptr;
}

int Semantics::typeCount(Typespec *type)
{
    int count = 0;

    if (type->getForm() == ENUMERATION)
    {
        vector<SymtabEntry *> *constants = type->getEnumerationConstants();
        count = constants->size();
    }
    else  // subrange
    {
        int minValue = type->getSubrangeMinValue();
        int maxValue = type->getSubrangeMaxValue();
        count = maxValue - minValue + 1;
    }

    return count;
}

Object Semantics::visitKittenBody(
                                PurrscalParser::KittenBodyContext *ctx)
{
    PurrscalParser::BreedContext *typeCtx = ctx->breed();
    visit(typeCtx);

    PurrscalParser::KittenKittiesContext *listCtx =
                                                ctx->kittenKitties();

    // Loop over the variables being declared.
    for (PurrscalParser::KittenKittyContext *idCtx :
                                                listCtx->kittenKitty())
    {
        int lineNumber = idCtx->getStart()->getLine();
        string variableName = toLowerCase(idCtx->KITTY()->getText());
        SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

        if (variableId == nullptr)
        {
            variableId = symtabStack->enterLocal(variableName, VARIABLE);
            variableId->setType(typeCtx->type);

            // Assign slot numbers to local variables.
            Symtab *symtab = variableId->getSymtab();
            if (symtab->getNestingLevel() > 1)
            {
                variableId->setSlotNumber(symtab->nextSlotNumber());
            }

            idCtx->entry = variableId;
        }
        else
        {
            error.flag(REDECLARED_KITTY, ctx);
        }

        variableId->appendLineNumber(lineNumber);
    }

    return nullptr;
}

Object Semantics::visitCallBody(
                                    PurrscalParser::CallBodyContext *ctx)
{
    PurrscalParser::BlepSnootContext  *funcCtx = ctx->blepSnoot();
    PurrscalParser::YowlSnootContext *procCtx = ctx->yowlSnoot();
    PurrscalParser::CallKittyContext *idCtx = nullptr;
    PurrscalParser::PurrametersContext *parameters = nullptr;
    bool functionDefinition = funcCtx != nullptr;
    Typespec *returnType = nullptr;
    string routineName;

    if (functionDefinition)
    {
        idCtx = funcCtx->callKitty();
        parameters = funcCtx->purrameters();
    }
    else
    {
        idCtx = procCtx->callKitty();
        parameters = procCtx->purrameters();
    }

    routineName = toLowerCase(idCtx->KITTY()->getText());
    SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

    if (routineId != nullptr)
    {
        error.flag(REDECLARED_KITTY,
                   ctx->getStart()->getLine(), routineName);
        return nullptr;
    }

    routineId = symtabStack->enterLocal(
                    routineName, functionDefinition ? BLEP : YOWL);
    routineId->setRoutineCode(DECLARED);
    idCtx->entry = routineId;

    // Append to the parent routine's list of subroutines.
    SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
    parentId->appendSubroutine(routineId);

    routineId->setRoutineSymtab(symtabStack->push());
    idCtx->entry = routineId;

    Symtab *symtab = symtabStack->getLocalSymtab();
    symtab->setOwner(routineId);

    if (parameters != nullptr)
    {
        vector<SymtabEntry *> *parameterIds =
                                visit(parameters->purrameterPurrs())
                                                .as<vector<SymtabEntry *>*>();
        routineId->setRoutineParameters(parameterIds);

        for (SymtabEntry *parmId : *parameterIds)
        {
            parmId->setSlotNumber(symtab->nextSlotNumber());
        }
    }

    if (functionDefinition)
    {
        PurrscalParser::KittyBreedContext *typeIdCtx =
                                                funcCtx->kittyBreed();
        visit(typeIdCtx);
        returnType = typeIdCtx->type;

        if (returnType->getForm() != SCALAR)
        {
            error.flag(INVALID_RETURN_TYPE, typeIdCtx);
            returnType = Predefined::integerType;
        }

        routineId->setType(returnType);
        idCtx->type = returnType;
    }
    else
    {
        idCtx->type = nullptr;
    }

    visit(ctx->cat()->catQualities());

    // Enter the function's associated variable into its symbol table.
    if (functionDefinition)
    {
        SymtabEntry *assocVarId =
                            symtabStack->enterLocal(routineName, VARIABLE);
        assocVarId->setSlotNumber(symtab->nextSlotNumber());
        assocVarId->setType(returnType);
    }

    visit(ctx->cat()->theBigMew());
    routineId->setExecutable(ctx->cat()->theBigMew());

    symtabStack->pop();
    return nullptr;
}

Object Semantics::visitPurrameterPurrs(
                            PurrscalParser::PurrameterPurrsContext *ctx)
{
    vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

    // Loop over the parameter declarations.
    for (PurrscalParser::PurrameterPurrContext *dclCtx :
                                                ctx->purrameterPurr())
    {
        vector<SymtabEntry *> parameterSublist =
                                    visit(dclCtx).as<vector<SymtabEntry *>>();
        for (SymtabEntry *id : parameterSublist) parameterList->push_back(id);
    }

    return parameterList;
}

Object Semantics::visitPurrameterPurr(
                                PurrscalParser::PurrameterPurrContext *ctx)
{
    Kind kind = ctx->KITTEN() != nullptr ? REFERENCE_PARAMETER : VALUE_PARAMETER;
    PurrscalParser::KittyBreedContext *typeCtx = ctx->kittyBreed();

    visit(typeCtx);
    Typespec *parmType = typeCtx->type;

    vector<SymtabEntry *> parameterSublist;

    // Loop over the parameter identifiers.
    PurrscalParser::PurrameterKittiesContext *listCtx =
                                                ctx->purrameterKitties();
    for (PurrscalParser::PurrameterKittyContext *idCtx :
                                                listCtx->purrameterKitty())
    {
        int lineNumber = idCtx->getStart()->getLine();
        string parmName = toLowerCase(idCtx->KITTY()->getText());
        SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

        if (parmId == nullptr)
        {
            parmId = symtabStack->enterLocal(parmName, kind);
            parmId->setType(parmType);
        }
        else
        {
            error.flag(REDECLARED_KITTY, idCtx);
        }

        idCtx->entry = parmId;
        idCtx->type  = parmType;

        parameterSublist.push_back(parmId);
        parmId->appendLineNumber(lineNumber);
    }

    return parameterSublist;
}

Object Semantics::visitHungryMew(
                                PurrscalParser::HungryMewContext *ctx)
{
    PurrscalParser::LpsContext *lhsCtx = ctx->lps();
    PurrscalParser::RpsContext *rhsCtx = ctx->rps();

    visitChildren(ctx);

    Typespec *lhsType = lhsCtx->type;
    Typespec *rhsType = rhsCtx->demand()->type;

    if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType))
    {
        error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
    }

    return nullptr;
}

Object Semantics::visitLps(PurrscalParser::LpsContext *ctx)
{
    PurrscalParser::KittenContext *varCtx = ctx->kitten();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitSniffMew(PurrscalParser::SniffMewContext *ctx)
{
    PurrscalParser::DemandContext     *exprCtx  = ctx->demand();
    PurrscalParser::PawMewContext  *trueCtx  = ctx->pawMew();
    PurrscalParser::IgnoreMewContext *falseCtx = ctx->ignoreMew();

    visit(exprCtx);
    Typespec *expr_type = exprCtx->type;
    
    if (!TypeChecker::isBoolean(expr_type))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }
    
    visit(trueCtx);
    if (falseCtx != nullptr) visit(falseCtx);

    return nullptr;
}

Object Semantics::visitHowlMew(
                                    PurrscalParser::HowlMewContext *ctx)
{
    PurrscalParser::DemandContext *exprCtx = ctx->demand();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->mews());
    return nullptr;
}

Object Semantics::visitPurrMew(PurrscalParser::PurrMewContext *ctx)
{
    PurrscalParser::DemandContext *exprCtx = ctx->demand();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->mew());
    return nullptr;
}

Object Semantics::visitYowlCallMew(
                            PurrscalParser::YowlCallMewContext *ctx)
{
    PurrscalParser::YowlNameContext *nameCtx = ctx->yowlName();
    PurrscalParser::ChirpsContext *listCtx = ctx->chirps();
    string name = toLowerCase(ctx->yowlName()->getText());
    SymtabEntry *procedureId = symtabStack->lookup(name);
    bool badName = false;

    if (procedureId == nullptr)
    {
        error.flag(UNDECLARED_KITTY, nameCtx);
        badName = true;
    }
    else if (procedureId->getKind() != YOWL)
    {
        error.flag(NAME_MUST_BE_YOWL, nameCtx);
        badName = true;
    }

    // Bad procedure name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (PurrscalParser::ChirpContext *exprCtx : listCtx->chirp())
        {
            visit(exprCtx);
        }
    }

    // Good procedure name.
    else
    {
        vector<SymtabEntry *> *parms = procedureId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
    }

    nameCtx->entry = procedureId;
    return nullptr;
}

Object Semantics::visitBlepCallExpectation(
                                PurrscalParser::BlepCallExpectationContext *ctx)
{
    PurrscalParser::BlepCallContext *callCtx = ctx->blepCall();
    PurrscalParser::BlepNameContext *nameCtx = callCtx->blepName();
    PurrscalParser::ChirpsContext *listCtx = callCtx->chirps();
    string name = toLowerCase(callCtx->blepName()->getText());
    SymtabEntry *functionId = symtabStack->lookup(name);
    bool badName = false;

    ctx->type = Predefined::integerType;

    if (functionId == nullptr)
    {
        error.flag(UNDECLARED_KITTY, nameCtx);
        badName = true;
    }
    else if (functionId->getKind() != BLEP)
    {
        error.flag(NAME_MUST_BE_FUNCTION, nameCtx);
        badName = true;
    }

    // Bad function name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (PurrscalParser::ChirpContext *exprCtx : listCtx->chirp())
        {
            visit(exprCtx);
        }
    }

    // Good function name.
    else
    {
        vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
        ctx->type = functionId->getType();
    }

    nameCtx->entry = functionId;
    nameCtx->type  = ctx->type;

    return nullptr;
}

void Semantics::checkCallArguments(
        PurrscalParser::ChirpsContext *listCtx, vector<SymtabEntry *> *parms)
{
    int parmsCount = parms->size();
    int argsCount = listCtx != nullptr ? listCtx->chirp().size() : 0;

    if (parmsCount != argsCount)
    {
        error.flag(ARGUMENT_COUNT_MISMATCH, listCtx);
        return;
    }

    // Check each argument against the corresponding parameter.
    for (int i = 0; i < parmsCount; i++)
    {
        PurrscalParser::ChirpContext *argCtx = listCtx->chirp()[i];
        PurrscalParser::DemandContext *exprCtx = argCtx->demand();
        visit(exprCtx);

        SymtabEntry *parmId = (*parms)[i];
        Typespec *parmType = parmId->getType();
        Typespec *argType  = exprCtx->type;

        // For a VAR parameter, the argument must be a variable
        // with the same datatype.
        if (parmId->getKind() == REFERENCE_PARAMETER)
        {
            if (expressionIsVariable(exprCtx))
            {
                if (parmType != argType)
                {
                    error.flag(TYPE_MISMATCH, exprCtx);
                }
            }
            else
            {
                error.flag(ARGUMENT_MUST_BE_VARIABLE, exprCtx);
            }
        }

        // For a value parameter, the argument type must be
        // assignment compatible with the parameter type.
        else if (!TypeChecker::areAssignmentCompatible(parmType, argType))
        {
            error.flag(TYPE_MISMATCH, exprCtx);
        }
    }
}

bool Semantics::expressionIsVariable(PurrscalParser::DemandContext *exprCtx)
{
    // Only a single simple expression?
    if (exprCtx->chonkDemand().size() == 1)
    {
        PurrscalParser::ChonkDemandContext *simpleCtx =
                                                exprCtx->chonkDemand()[0];
        // Only a single term?
        if (simpleCtx->trill().size() == 1)
        {
            PurrscalParser::TrillContext *termCtx = simpleCtx->trill()[0];

            // Only a single factor?
            if (termCtx->expectation().size() == 1)
            {
                return dynamic_cast<PurrscalParser::KittenExpectationContext *>(
                                            termCtx->expectation()[0]) != nullptr;
            }
        }
    }

    return false;
}

Object Semantics::visitDemand(PurrscalParser::DemandContext *ctx)
{
    PurrscalParser::ChonkDemandContext *simpleCtx1 = ctx->chonkDemand()[0];

    // First simple expression.
    visit(simpleCtx1);

    Typespec *simpleType1 = simpleCtx1->type;
    ctx->type = simpleType1;

    PurrscalParser::RelationalWhiskerContext *relopCtx = ctx->relationalWhisker();

    // Second simple expression?
    if (relopCtx != nullptr)
    {
        PurrscalParser::ChonkDemandContext *simpleCtx2 =
                                                    ctx->chonkDemand()[1];
        visit(simpleCtx2);

        Typespec *simpleType2 = simpleCtx2->type;
        if (!TypeChecker::areComparisonCompatible(simpleType1, simpleType2))
        {
            error.flag(INCOMPATIBLE_COMPARISON, ctx);
        }

        ctx->type = Predefined::booleanType;
    }

    return nullptr;
}

Object Semantics::visitChonkDemand(
                                    PurrscalParser::ChonkDemandContext *ctx)
{
    int count = ctx->trill().size();
    PurrscalParser::FurContext *signCtx = ctx->fur();
    bool hasSign = signCtx != nullptr;
    PurrscalParser::TrillContext *termCtx1 = ctx->trill()[0];

    if (hasSign)
    {
        string sign = signCtx->getText();
        if ((sign== "+") && (sign == "-"))
        {
            error.flag(INVALID_SIGN, signCtx);
        }
    }

    // First term.
    visit(termCtx1);
    Typespec *termType1 = termCtx1->type;

    // Loop over any subsequent terms.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->additiveWhisker()[i-1]->getText());
        PurrscalParser::TrillContext *termCtx2 = ctx->trill()[i];
        visit(termCtx2);
        Typespec *termType2 = termCtx2->type;

        if (op == "+")
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

            // Both operands string ==> string result
            else if (TypeChecker::areBothString(termType1, termType2))
            {
                if (hasSign) error.flag(INVALID_SIGN, signCtx);
                termType2 = Predefined::stringType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }
        else  // -
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }

        termType1 = termType2;
    }

    ctx->type = termType1;
    return nullptr;
}

Object Semantics::visitTrill(PurrscalParser::TrillContext *ctx)
{
    int count = ctx->expectation().size();
    PurrscalParser::ExpectationContext *factorCtx1 = ctx->expectation()[0];

    // First factor.
    visit(factorCtx1);
    Typespec *factorType1 = factorCtx1->type;

    // Loop over any subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->multiplicativeWhisker()[i-1]->getText());
        PurrscalParser::ExpectationContext *factorCtx2 = ctx->expectation()[i];
        visit(factorCtx2);
        Typespec *factorType2 = factorCtx2->type;

        if (op == "*")
        {
            // Both operands integer  ==> integer result
            if (TypeChecker::areBothInteger(factorType1, factorType2))
            {
                factorType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if (op == "/")
        {
            // All integer and real operand combinations ==> real result
            if (   TypeChecker::areBothInteger(factorType1, factorType2)
                || TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }


        factorType1 = factorType2;
    }

    ctx->type = factorType1;
    return nullptr;
}

Object Semantics::visitKittenExpectation(PurrscalParser::KittenExpectationContext *ctx)
{
    PurrscalParser::KittenContext *varCtx = ctx->kitten();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitKitten(PurrscalParser::KittenContext *ctx)
{
    PurrscalParser::KittenKittyContext *varIdCtx =
                                                    ctx->kittenKitty();

    visit(varIdCtx);
    ctx->entry = varIdCtx->entry;
    ctx->type  = variableDatatype(ctx, varIdCtx->type);

    return nullptr;
}

Object Semantics::visitKittenKitty(
                                PurrscalParser::KittenKittyContext *ctx)
{

    string variableName = toLowerCase(ctx->KITTY()->getText());
    SymtabEntry *variableId = symtabStack->lookup(variableName);

    if (variableId != nullptr)
    {
        int lineNumber = ctx->getStart()->getLine();
        ctx->type = variableId->getType();
        ctx->entry = variableId;
        variableId->appendLineNumber(lineNumber);

        Kind kind = variableId->getKind();
        switch (kind)
        {
            case BREED:
            case PURRGRAM:
            case PURRGRAM_PARAMETER:
            case YOWL:
            case UNDEFINED:
                error.flag(INVALID_VARIABLE, ctx);
                break;

            default: break;
        }
    }
    else
    {
        error.flag(UNDECLARED_KITTY, ctx);
        ctx->type = Predefined::integerType;
    }

    return nullptr;
}

Typespec *Semantics::variableDatatype(PurrscalParser::KittenContext *varCtx,
                                      Typespec *varType)
{
    Typespec *type = varType;

    for (PurrscalParser::ModifierContext *modCtx : varCtx->modifier())
    {
        // Subscripts.
        if (modCtx->indices() != nullptr)
        {
            PurrscalParser::IndicesContext *indexListCtx = modCtx->indices();

            // Loop over the subscripts.
            for (PurrscalParser::IndexContext *indexCtx : indexListCtx->index())
            {
                if (type->getForm() == KABOODLE)
                {
                    Typespec *indexType = type->getArrayIndexType();
                    PurrscalParser::DemandContext *exprCtx =
                                                        indexCtx->demand();
                    visit(exprCtx);

                    if (indexType->baseType() != exprCtx->type->baseType())
                    {
                        error.flag(TYPE_MISMATCH, exprCtx);
                    }

                    // Datatype of the next dimension.
                    type = type->getArrayElementType();
                }
                else
                {
                    error.flag(TOO_MANY_SUBSCRIPTS, indexCtx);
                }
            }
        }
        else
        {
                            error.flag(INVALID_FIELD, modCtx);

        }
    }

    return type;
}

Object Semantics::visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx)
{
    PurrscalParser::FelineContext          *numberCtx   = ctx->feline();
    PurrscalParser::HairlessFelineContext  *unsignedCtx = numberCtx->hairlessFeline();
    PurrscalParser::SphynxDomesticContext *integerCtx  = unsignedCtx->sphynxDomestic();

    ctx->type = (integerCtx != nullptr) ? Predefined::integerType
                                        : Predefined::realType;

    return nullptr;
}

Object Semantics::visitThreadBallExpectation(PurrscalParser::ThreadBallExpectationContext *ctx)
{
    ctx->type = Predefined::charType;
    return nullptr;
}

Object Semantics::visitYarnBallExpectation(PurrscalParser::YarnBallExpectationContext *ctx)
{
    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitRollExpectation(PurrscalParser::RollExpectationContext *ctx)
{
    PurrscalParser::ExpectationContext *factorCtx = ctx->expectation();
    visit(factorCtx);

    if (factorCtx->type != Predefined::booleanType)
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx);
    }

    ctx->type = Predefined::booleanType;
    return nullptr;
}

Object Semantics::visitParenthesizedExpectation(
                                PurrscalParser::ParenthesizedExpectationContext *ctx)
{
    PurrscalParser::DemandContext *exprCtx = ctx->demand();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}

} // namespace frontend
