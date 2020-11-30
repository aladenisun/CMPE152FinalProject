/**
 * <h1>Predefined</h1>
 *
 * <p>Enter the predefined Purrscal types, identifiers, and constants
 * into the symbol table.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "Predefined.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

// Predefined types.
intermediate::type::Typespec *Predefined::integerType;
intermediate::type::Typespec *Predefined::realType;
intermediate::type::Typespec *Predefined::booleanType;
intermediate::type::Typespec *Predefined::charType;
intermediate::type::Typespec *Predefined::stringType;
intermediate::type::Typespec *Predefined::undefinedType;

// Predefined identifiers.
SymtabEntry *Predefined::integerId;
SymtabEntry *Predefined::realId;
SymtabEntry *Predefined::booleanId;
SymtabEntry *Predefined::charId;
SymtabEntry *Predefined::stringId;
SymtabEntry *Predefined::falseId;
SymtabEntry *Predefined::trueId;
SymtabEntry *Predefined::readId;
SymtabEntry *Predefined::readlnId;
SymtabEntry *Predefined::meowId;
SymtabEntry *Predefined::mrrowId;
SymtabEntry *Predefined::absId;
SymtabEntry *Predefined::arctanId;
SymtabEntry *Predefined::chrId;
SymtabEntry *Predefined::cosId;
SymtabEntry *Predefined::eofId;
SymtabEntry *Predefined::eolnId;
SymtabEntry *Predefined::expId;
SymtabEntry *Predefined::lnId;
SymtabEntry *Predefined::oddId;
SymtabEntry *Predefined::ordId;
SymtabEntry *Predefined::predId;
SymtabEntry *Predefined::roundId;
SymtabEntry *Predefined::sinId;
SymtabEntry *Predefined::sqrId;
SymtabEntry *Predefined::sqrtId;
SymtabEntry *Predefined::succId;
SymtabEntry *Predefined::truncId;

void Predefined::initialize(SymtabStack *symtabStack)
{
    initializeTypes(symtabStack);
    initializeConstants(symtabStack);
    initializeStandardRoutines(symtabStack);
}

void Predefined::initializeTypes(SymtabStack *symtabStack)
{
    // Type integer.
    integerId = symtabStack->enterLocal("integer", BREED);
    integerType = new Typespec(SCALAR);
    integerType->setIdentifier(integerId);
    integerId->setType(integerType);

    // Type real.
    realId = symtabStack->enterLocal("real", BREED);
    realType = new Typespec(SCALAR);
    realType->setIdentifier(realId);
    realId->setType(realType);

    // Type boolean.
    booleanId = symtabStack->enterLocal("boolean", BREED);
    booleanType = new Typespec(ENUMERATION);
    booleanType->setIdentifier(booleanId);
    booleanId->setType(booleanType);

    // Type char.
    charId = symtabStack->enterLocal("char", BREED);
    charType = new Typespec(SCALAR);
    charType->setIdentifier(charId);
    charId->setType(charType);

    // Type string.
    stringId = symtabStack->enterLocal("string", BREED);
    stringType = new Typespec(SCALAR);
    stringType->setIdentifier(stringId);
    stringId->setType(stringType);

    // Undefined type.
    undefinedType = new Typespec(SCALAR);
}

void Predefined::initializeConstants(SymtabStack *symtabStack)
{
    // Boolean enumeration constant false.
    falseId = symtabStack->enterLocal("false", ENUMERATION_CONSTANT);
    falseId->setType(booleanType);
    falseId->setValue(0);

    // Boolean enumeration constant true.
    trueId = symtabStack->enterLocal("true", ENUMERATION_CONSTANT);
    trueId->setType(booleanType);
    trueId->setValue(1);

    // Add false and true to the boolean enumeration type.
    vector<SymtabEntry *> *constants = new vector<SymtabEntry *>;
    constants->push_back(falseId);
    constants->push_back(trueId);
    booleanType->setEnumerationConstants(constants);
}

void Predefined::initializeStandardRoutines(SymtabStack *symtabStack)
{
    readId    = enterStandard(symtabStack, YOWL, "read",    READ);
    readlnId  = enterStandard(symtabStack, YOWL, "readln",  READLN);
    meowId   = enterStandard(symtabStack, YOWL, "meow",   MEOW);
    mrrowId = enterStandard(symtabStack, YOWL, "mrrow", MRROW);

    absId    = enterStandard(symtabStack, BLEP,  "abs",     ABS);
    arctanId = enterStandard(symtabStack, BLEP,  "arctan",  ARCTAN);
    chrId    = enterStandard(symtabStack, BLEP,  "chr",     CHR);
    cosId    = enterStandard(symtabStack, BLEP,  "cos",     COS);
    eofId    = enterStandard(symtabStack, BLEP,  "eof",     EOF_FUNCTION);
    eolnId   = enterStandard(symtabStack, BLEP,  "eoln",    EOLN_FUNCTION);
    expId    = enterStandard(symtabStack, BLEP,  "exp",     EXP);
    lnId     = enterStandard(symtabStack, BLEP,  "ln",      LN);
    oddId    = enterStandard(symtabStack, BLEP,  "odd",     ODD);
    ordId    = enterStandard(symtabStack, BLEP,  "ord",     ORD);
    predId   = enterStandard(symtabStack, BLEP,  "pred",    PRED);
    roundId  = enterStandard(symtabStack, BLEP,  "round",   ROUND);
    sinId    = enterStandard(symtabStack, BLEP,  "sin",     SIN);
    sqrId    = enterStandard(symtabStack, BLEP,  "sqr",     SQR);
    sqrtId   = enterStandard(symtabStack, BLEP,  "sqrt",    SQRT);
    succId   = enterStandard(symtabStack, BLEP,  "succ",    SUCC);
    truncId  = enterStandard(symtabStack, BLEP,  "trunc",   TRUNC);
}

SymtabEntry *Predefined::enterStandard(SymtabStack *symtabStack,
                                       const Kind kind, const string name,
                                       const Routine code)
{
    SymtabEntry *procId = symtabStack->enterLocal(name, kind);
    procId->setRoutineCode(code);

    return procId;
}

}}  // namespace wci::intermediate::symtabimpl
