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


Object Semantics::visitPurrgram(PurrscalParser::PurrgramContext *ctx){

	visit(ctx->purrgramSnoot());
	visit(ctx->cat()->catQualities());
	visit(ctx->cat()->theBigMew());

	// Print the cross-reference table.
	CrossReferencer crossReferencer;
	crossReferencer.print(symtabStack);

	return nullptr;

}

Object Semantics::visitPurrgramSnoot(PurrscalParser::PurrgramSnootContext *ctx) {

	PurrscalParser::PurrgramKittyContext *idCtx = ctx->purrgramKitty();
	string purrgramName = idCtx->KITTY()->getText();  // don't shift case

	purrgramId = symtabStack->enterLocal(purrgramName, PURRGRAM);
	purrgramId->setRoutineSymtab(symtabStack->push());

	symtabStack->setPurrgramId(purrgramId);
	symtabStack->getLocalSymtab()->setOwner(purrgramId);

	idCtx->entry = purrgramId;
	return nullptr;


}


Object Semantics::visitDomesticBody(PurrscalParser::DomesticBodyContext *ctx){

	PurrscalParser::DomesticKittyContext *idCtx = ctx->domesticKitty();
	string domesticName = toLowerCase(idCtx->KITTY()->getText());
	SymtabEntry *domesticId = symtabStack->lookupLocal(domesticName);

	if (domesticId == nullptr)
	{
		PurrscalParser::DomesticContext *constCtx = ctx->domestic();
		Object constValue = visit(constCtx);

		domesticId = symtabStack->enterLocal(domesticName, DOMESTIC);
		domesticId->setValue(constValue);
		domesticId->setType(constCtx->type);

		idCtx->entry = domesticId;
		idCtx->type  = constCtx->type;
	}
	else
	{
		error.flag(REDECLARED_KITTY, ctx);

		idCtx->entry = domesticId;
		idCtx->type  = Predefined::integerType;
	}

	domesticId->appendLineNumber(ctx->getStart()->getLine());
	return nullptr;

}

Object Semantics::visitDomestic(PurrscalParser::DomesticContext *ctx) {

	if (ctx->KITTY() != nullptr)
	{
		string domesticName = toLowerCase(ctx->KITTY()->getText());
		SymtabEntry *constantId = symtabStack->lookup(domesticName);

		if (constantId != nullptr)
		{
			Kind kind = constantId->getKind();
			if ((kind != DOMESTIC) && (kind != ENUMERATION_CONSTANT))
			{
				error.flag(INVALID_DOMESTIC, ctx);
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

Object Semantics::visitBreedBody(PurrscalParser::BreedBodyContext *ctx) {

	PurrscalParser::KittyBreedContext *idCtx = ctx->kittyBreed();
	string breedName = toLowerCase(idCtx->KITTY()->getText());
	SymtabEntry *typeId = symtabStack->lookupLocal(breedName);

	PurrscalParser::BreedContext *typespecCtx =ctx->breed();


	// Enter the type name of any other type into the symbol table.
	if (typeId == nullptr)
	{
		PurrscalParser::BreedContext *typeCtx = ctx->breed();
		visit(typeCtx);

		typeId = symtabStack->enterLocal(breedName, BREED);
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
Object Semantics::visitChonkTypespec(PurrscalParser::ChonkTypespecContext *ctx) {

	visit(ctx->chonk());
	ctx->type = ctx->chonk()->type;

	return nullptr;
}

Object Semantics::visitKittyBreedTypsec(PurrscalParser::KittyBreedTypsecContext *ctx) {
	visit(ctx->kittyBreed());
	ctx->type = ctx->kittyBreed()->type;

	return nullptr;
}

Object Semantics::visitKittyBreed(PurrscalParser::KittyBreedContext *ctx) {

	string breedName = toLowerCase(ctx->KITTY()->getText());
	SymtabEntry *typeId = symtabStack->lookup(breedName);

	if (typeId != nullptr)
	{
		if (typeId->getKind() != BREED)
		{
			error.flag(INVALID_BREED, ctx);
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
Object Semantics::visitFluffballTypespec(PurrscalParser::FluffballTypespecContext *ctx) {

	Typespec *enumType = new Typespec(ENUMERATION);
	vector<SymtabEntry *> *constants = new vector<SymtabEntry *>();
	int value = -1;

	// Loop over the enumeration constants.
	for (PurrscalParser::FluffballDomesticContext *constCtx :
			ctx->fluffball()->fluffballDomestic())
	{
		PurrscalParser::DomesticKittyContext *constIdCtx =
				constCtx->domesticKitty();
		string domesticName = toLowerCase(constIdCtx->KITTY()->getText());

		SymtabEntry *constantId = symtabStack->lookupLocal(domesticName);

		if (constantId == nullptr)
		{
			constantId = symtabStack->enterLocal(domesticName,
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

Object Semantics::visitKittenKaboodleTypespec(PurrscalParser::KittenKaboodleTypespecContext *ctx){

	Typespec *type = new Typespec(SUBRANGE);

	PurrscalParser::KittenKaboodleContext *subCtx = ctx->kittenKaboodle();
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
		error.flag(INVALID_DOMESTIC, minCtx);
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
		error.flag(INVALID_DOMESTIC, maxCtx);
		maxType = minType;
		maxObj  = minObj;
	}

	type->setSubrangeBaseType(minType);
	type->setSubrangeMinValue(minValue);
	type->setSubrangeMaxValue(maxValue);

	ctx->type = type;
	return nullptr;
}

Object Semantics::visitKittenBody(PurrscalParser::KittenBodyContext *ctx) {

	PurrscalParser::BreedContext *typeCtx = ctx->breed();

	visit(typeCtx);

	PurrscalParser::KittenKittiesContext *listCtx = ctx->kittenKitties();

	// Loop over the variables being declared.
	for (PurrscalParser::KittenKittyContext *idCtx : listCtx->kittenKitty())
	{
		int lineNumber = idCtx->getStart()->getLine();
		string kittenName = toLowerCase(idCtx->KITTY()->getText());
		SymtabEntry *variableId = symtabStack->lookupLocal(kittenName);

		if (variableId == nullptr)
		{
			variableId = symtabStack->enterLocal(kittenName, KITTEN);
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

Object Semantics::visitCallBody(PurrscalParser::CallBodyContext *ctx) {

	PurrscalParser::BlepSnootContext *funcCtx = ctx->blepSnoot();
	PurrscalParser::YowlSnootContext *procCtx = ctx->yowlSnoot();
	PurrscalParser::CallKittyContext *idCtx = nullptr;
	PurrscalParser::PurrametersContext *purrameters = nullptr;
	bool functionDefinition = funcCtx != nullptr;
	Typespec *returnType = nullptr;
	string routineName;

	if (functionDefinition)
	{
		idCtx = funcCtx->callKitty();
		purrameters = funcCtx->purrameters();
	}
	else
	{
		idCtx = procCtx->callKitty();
		purrameters = procCtx->purrameters();
	}

	routineName = toLowerCase(idCtx->KITTY()->getText());
	SymtabEntry *callId = symtabStack->lookupLocal(routineName);

	if (callId != nullptr)
	{
		error.flag(REDECLARED_KITTY,
				ctx->getStart()->getLine(), routineName);
		return nullptr;
	}

	callId = symtabStack->enterLocal(
			routineName, functionDefinition ? BLEP : YOWL);
	callId->setRoutineCode(DECLARED);
	idCtx->entry = callId;

	// Append to the parent routine's list of subroutines.
	SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
	parentId->appendSubroutine(callId);

	callId->setRoutineSymtab(symtabStack->push());
	idCtx->entry = callId;

	Symtab *symtab = symtabStack->getLocalSymtab();
	symtab->setOwner(callId);

	if (purrameters != nullptr)
	{
		vector<SymtabEntry *> *parameterIds =
				visit(purrameters->purrameterPurrs())
				.as<vector<SymtabEntry *>*>();
		callId->setRoutineParameters(parameterIds);

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

		callId->setType(returnType);
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
				symtabStack->enterLocal(routineName, KITTEN);
		assocVarId->setSlotNumber(symtab->nextSlotNumber());
		assocVarId->setType(returnType);
	}

	visit(ctx->cat()->theBigMew());
	callId->setExecutable(ctx->cat()->theBigMew());

	symtabStack->pop();
	return nullptr;
}



Object Semantics::visitPurrameterPurrs(PurrscalParser::PurrameterPurrsContext *ctx) {

	vector<SymtabEntry *> *purrameterList = new vector<SymtabEntry *>();

	// Loop over the parameter declarations.
	for (PurrscalParser::PurrameterPurrContext *dclCtx :
			ctx->purrameterPurr())
	{
		vector<SymtabEntry *> purrameterSublist =
				visit(dclCtx).as<vector<SymtabEntry *>>();
		for (SymtabEntry *id : purrameterSublist) purrameterList->push_back(id);
	}

	return purrameterList;

}

Object Semantics::visitPurrameterPurr(PurrscalParser::PurrameterPurrContext *ctx) {
	//check the kitten for VAR()
	Kind kind = ctx->KITTEN() != nullptr ? REFERENCE_PARAMETER : VALUE_PARAMETER;

	PurrscalParser::KittyBreedContext *typeCtx = ctx->kittyBreed();

	visit(typeCtx);
	Typespec *parmType = typeCtx->type;

	vector<SymtabEntry *> purrrameterSublist;

	// Loop over the parameter identifiers.
	PurrscalParser::PurrameterKittiesContext*listCtx = ctx->purrameterKitties();

	for (PurrscalParser::PurrameterKittyContext *idCtx : listCtx->purrameterKitty())
	{

		int lineNumber = idCtx->getStart()->getLine();
		string purrmName = toLowerCase(idCtx->KITTY()->getText());
		SymtabEntry *parmId = symtabStack->lookupLocal(purrmName);

		if (parmId == nullptr)
		{
			parmId = symtabStack->enterLocal(purrmName, kind);
			parmId->setType(parmType);
		}
		else
		{
			error.flag(REDECLARED_KITTY, idCtx);
		}

		idCtx->entry = parmId;
		idCtx->type  = parmType;

		purrrameterSublist.push_back(parmId);
		parmId->appendLineNumber(lineNumber);
	}

	return purrrameterSublist;
}

Object Semantics::visitHungryMew(PurrscalParser::HungryMewContext *ctx) {

	PurrscalParser::LpsContext *lpsCtx = ctx->lps();
	PurrscalParser::RpsContext *rpsCtx = ctx->rps();

	visitChildren(ctx);

	Typespec *lhsType = lpsCtx->type;
	Typespec *rhsType = rpsCtx->demand()->type;

	if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType))
	{
		error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
	}

	return nullptr;

}

Object Semantics::visitLps(PurrscalParser::LpsContext*ctx) {
	PurrscalParser::KittenContext *varCtx = ctx->kitten();
	visit(varCtx);
	ctx->type = varCtx->type;

	return nullptr;

}

Object Semantics::visitSniffMew(PurrscalParser::SniffMewContext *ctx) {

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

Object Semantics::visitHowlMew(PurrscalParser::HowlMewContext*ctx) {

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

Object Semantics::visitPurrMew(PurrscalParser::PurrMewContext*ctx) {

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

Object Semantics::visitYowlCallMew(PurrscalParser::YowlCallMewContext*ctx) {

	PurrscalParser::YowlNameContext *nameCtx = ctx->yowlName();
	PurrscalParser::ChirpsContext *listCtx = ctx->chirps();
	string name = toLowerCase(ctx->yowlName()->getText());
	SymtabEntry *purrcedureId = symtabStack->lookup(name);
	bool badName = false;

	if (purrcedureId == nullptr)
	{
		error.flag(UNDECLARED_KITTY, nameCtx);
		badName = true;
	}
	else if (purrcedureId->getKind() != YOWL)
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
		vector<SymtabEntry *> *parms = purrcedureId->getRoutineParameters();
		checkCallChirps(listCtx, parms);
	}

	nameCtx->entry = purrcedureId;
	return nullptr;

}

Object Semantics::visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *ctx) {

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
		error.flag(NAME_MUST_BE_BLEP, nameCtx);
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
		checkCallChirps(listCtx, parms);
		ctx->type = functionId->getType();
	}

	nameCtx->entry = functionId;
	nameCtx->type  = ctx->type;

	return nullptr;

}

void checkCallChirps(PurrscalParser::ChirpsContext *listCtx, vector<SymtabEntry *> *parms){

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
			if (demandIsVariable(exprCtx))
			{
				if (parmType != argType)
				{
					error.flag(TYPE_MISMATCH, exprCtx);
				}
			}
			else
			{
				error.flag(ARGUMENT_MUST_BE_KITTEN, exprCtx);
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


//int typeCount(Typespec *type);

bool Semantics::demandIsVariable(PurrscalParser::DemandContext *exprCtx){

	if (exprCtx->chonkDemand().size() == 1)
	{
		PurrscalParser::ChonkDemandContext *simpleCtx =
				exprCtx->chonkDemand()[0];
		// Only a single term?
				if (simpleCtx->trill().size() == 1)
				{
					PurrscalParser::TrillContext *trillCtx = simpleCtx->trill()[0];

					// Only a single factor?
					if (trillCtx->expectation().size() == 1)
					{
						return dynamic_cast<PurrscalParser::KittenExpectationContext *>(
								trillCtx->expectation()[0]) != nullptr;
					}
				}
	}

	return false;
}


Object Semantics::visitDemand(PurrscalParser::DemandContext *ctx) {

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



Object Semantics::visitChonkDemand(PurrscalParser::ChonkDemandContext *ctx) {

	int count = ctx->trill().size();
	PurrscalParser::FurContext *signCtx = ctx->fur();
	bool hasSign = signCtx != nullptr;
	PurrscalParser::TrillContext *termCtx1 = ctx->trill()[0];

	if (hasSign)
	{
		string sign = signCtx->getText();
		if ((sign== "+") && (sign == "-"))
		{
			error.flag(INVALID_FUR, signCtx);
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

		// Both operands bool ==> bool result. Else type mismatch.
		if (op == "or")
		{
			if (!TypeChecker::isBoolean(termType1))
			{
				error.flag(TYPE_MUST_BE_BOOLEAN, termCtx1);
			}
			if (!TypeChecker::isBoolean(termType2))
			{
				error.flag(TYPE_MUST_BE_BOOLEAN, termCtx2);
			}
			if (hasSign)
			{
				error.flag(INVALID_FUR, signCtx);
			}

			termType2 = Predefined::booleanType;
		}
		else if (op == "+")
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
				if (hasSign) error.flag(INVALID_FUR, signCtx);
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

Object Semantics::visitTrill(PurrscalParser::TrillContext *ctx) {

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
		else if ((op == "div") ||(op == "mod"))
		{
			// Both operands integer ==> integer result. Else type mismatch.
			if (!TypeChecker::isInteger(factorType1))
			{
				error.flag(TYPE_MUST_BE_SPHYNX, factorCtx1);
				factorType2 = Predefined::integerType;
			}
			if (!TypeChecker::isInteger(factorType2))
			{
				error.flag(TYPE_MUST_BE_SPHYNX, factorCtx2);
				factorType2 = Predefined::integerType;
			}

			ctx->type = Predefined::integerType;
		}
		else if (op == "and")
		{
			// Both operands bool ==> bool result. Else type mismatch.
			if (!TypeChecker::isBoolean(factorType1))
			{
				error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx1);
				factorType2 = Predefined::booleanType;
			}
			if (!TypeChecker::isBoolean(factorType2))
			{
				error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx2);
				factorType2 = Predefined::booleanType;
			}
		}

		factorType1 = factorType2;
	}

	ctx->type = factorType1;
	return nullptr;
}

Object Semantics::visitKittenExpectation(PurrscalParser::KittenExpectationContext*ctx){

	PurrscalParser::KittenContext *varCtx = ctx->kitten();
	visit(varCtx);
	ctx->type = varCtx->type;

	return nullptr;
}

Object Semantics::visitKitten(PurrscalParser::KittenContext *ctx) {

	PurrscalParser::KittenKittyContext *varIdCtx = ctx->kittenKitty();

	visit(varIdCtx);
	ctx->entry = varIdCtx->entry;
	ctx->type  = kittenDatatype(ctx, varIdCtx->type);

	return nullptr;
}

Object Semantics::visitKittenKitty(PurrscalParser::KittenKittyContext*ctx) {

	string kittenName = toLowerCase(ctx->KITTY()->getText());
	SymtabEntry *variableId = symtabStack->lookup(kittenName);

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
		case PURRGRAM_PURRAMETER:
		case YOWL:
		case UNDEFINED:
			error.flag(INVALID_KITTEN, ctx);
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



Typespec* Semantics::kittenDatatype(PurrscalParser::KittenContext *varCtx, Typespec *varType){

	Typespec *type = varType;

	for (PurrscalParser::ModifierContext *modCtx : varCtx->modifier())
	{
		// Subscripts.
		if (modCtx->indices() != nullptr)
		{
			PurrscalParser::IndicesContext *indicesCtx = modCtx->indices();

			// Loop over the subscripts.
			for (PurrscalParser::IndexContext *indexCtx : indicesCtx->index())
			{
				if (type->getForm() == ARRAY)
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
	}
	return type;
}

Object Semantics::visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx) {

	PurrscalParser::FelineContext          *felineCtx   = ctx->feline();
	PurrscalParser::HairlessFelineContext  *hairlessFelineCtx = felineCtx->hairlessFeline();
	PurrscalParser::SphynxDomesticContext 	*sphynxCtx  = hairlessFelineCtx->sphynxDomestic();

	ctx->type = (sphynxCtx != nullptr) ? Predefined::integerType
			: Predefined::realType;

	return nullptr;
}

Object Semantics::visitThreadExpectation(PurrscalParser::ThreadExpectationContext *ctx) {

	  ctx->type = Predefined::charType;
	    return nullptr;
}

Object Semantics::visitYarnExpectation(PurrscalParser::YarnExpectationContext *ctx) {

    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitRollExpectation(PurrscalParser::RollExpectationContext*ctx) {

	PurrscalParser::ExpectationContext *expectationCtx = ctx->expectation();
	visit(expectationCtx);

	if (expectationCtx->type != Predefined::booleanType)
	{
		error.flag(TYPE_MUST_BE_BOOLEAN, expectationCtx);
	}

	ctx->type = Predefined::booleanType;
	return nullptr;
}

Object Semantics::visitParenthesizedExpectation(PurrscalParser::ParenthesizedExpectationContext *ctx) {

    PurrscalParser::DemandContext *exprCtx = ctx->demand();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}

} // namespace frontend
