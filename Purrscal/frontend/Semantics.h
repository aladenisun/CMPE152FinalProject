#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include <map>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "SemanticErrorHandler.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Semantics : public PurrscalBaseVisitor
{
private:
    BackendMode mode;
    SymtabStack *symtabStack;
    SymtabEntry *programId;
    SemanticErrorHandler error;

    map<string, Typespec *> *typeTable;

    /**
     * Return the number of values in a datatype.
     * @param type the datatype.
     * @return the number of values.
     */
    int typeCount(Typespec *type);

    /**
     * Determine whether or not an expression is a variable only.
     * @param exprCtx the ExpressionContext.
     * @return true if it's an expression only, else false.
     */
    bool expressionIsVariable(PurrscalParser::DemandContext *exprCtx);

    /**
     * Perform semantic operations on procedure and function call arguments.
     * @param listCtx the ArgumentListContext.
     * @param parameters the vector of parameters to fill.
     */
    void checkCallArguments(PurrscalParser::ChirpsContext *listCtx,
                            vector<SymtabEntry *> *parms);

    /**
     * Determine the datatype of a variable that can have modifiers.
     * @param varCtx the VariableContext.
     * @param varType the variable's datatype without the modifiers.
     * @return the datatype with any modifiers.
     */
    Typespec *variableDatatype(PurrscalParser::KittenContext *varCtx,
                               Typespec *varType);

    /**
     * Create a new record type.
     * @param recordTypeSpecCtx the RecordTypespecContext.
     * @param recordTypeName the name of the record type.
     * @return the symbol table entry of the record type identifier.
     */
//    SymtabEntry *createRecordType(
//                        PurrscalParser::RecordTypespecContext *recordTypeSpecCtx,
//                        string recordTypeName);

    /**
     * Create the fully qualified type pathname of a record type.
     * @param recordType the record type.
     * @return the pathname.
     */
//    string createRecordTypePath(Typespec *recordType);

    /**
     * Create the symbol table for a record type.
     * @param ctx the RecordFieldsContext,
     * @param ownerId the symbol table entry of the owner's identifier.
     * @return the symbol table.
     */
//    Symtab *createRecordSymtab(
//                PurrscalParser::RecordFieldsContext *ctx, SymtabEntry *ownerId);

public:
    Semantics(BackendMode mode) : mode(mode), programId(nullptr)
    {
        // Create and initialize the symbol table stack.
        symtabStack = new SymtabStack();
        Predefined::initialize(symtabStack);

        typeTable = new map<string, Typespec *>();
        (*typeTable)["integer"] = Predefined::integerType;
        (*typeTable)["real"]    = Predefined::realType;
        (*typeTable)["boolean"] = Predefined::booleanType;
        (*typeTable)["char"]    = Predefined::charType;
        (*typeTable)["string"]  = Predefined::stringType;
    }

    /**
     * Get the symbol table entry of the program identifier.
     * @return the entry.
     */
    SymtabEntry *getProgramId() { return programId; }

    /**
     * Get the count of semantic errors.
     * @return the count.
     */
    int getErrorCount() const { return error.getCount(); }

    /**
     * Return the default value for a given datatype.
     * @param type the datatype.
     */
    static Object defaultValue(Typespec *type);

    Object visitProgram(PurrscalParser::PurrgramContext *ctx) override;
    Object visitProgramHeader(PurrscalParser::PurrgramSnootContext *ctx) override;
    Object visitConstantDefinition(PurrscalParser::DomesticBodyContext *ctx) override;
    Object visitConstant(PurrscalParser::DomesticContext *ctx) override;
    Object visitTypeDefinition(PurrscalParser::BreedBodyContext *ctx) override;
//    Object visitRecordTypespec(PurrscalParser::RecordTypespecContext *ctx) override;
    Object visitSimpleTypespec(PurrscalParser::ChonkTypespecContext *ctx) override;
    Object visitTypeIdentifierTypespec(PurrscalParser::KittyBreedTypsecContext *ctx) override;
    Object visitTypeIdentifier(PurrscalParser::KittyBreedContext *ctx) override;
    Object visitEnumerationTypespec(PurrscalParser::FluffballTypespecContext *ctx) override;
    Object visitSubrangeTypespec(PurrscalParser::KittenKaboodleTypespecContext *ctx) override;
//    Object visitArrayTypespec(PurrscalParser::ArrayTypespecContext *ctx) override;
    Object visitVariableDeclarations(PurrscalParser::KittenBodiesContext *ctx) override;
    Object visitRoutineDefinition(PurrscalParser::CallBodyContext *ctx) override;
    Object visitParameterDeclarationsList(PurrscalParser::PurrameterPurrsContext *ctx) override;
    Object visitParameterDeclarations(PurrscalParser::PurrameterPurrContext *ctx) override;
    Object visitAssignmentStatement(PurrscalParser::HungryMewContext *ctx) override;
    Object visitLhs(PurrscalParser::LpsContext*ctx) override;
    Object visitIfStatement(PurrscalParser::SniffMewContext *ctx) override;
    Object visitRepeatStatement(PurrscalParser::HowlMewContext*ctx) override;
    Object visitWhileStatement(PurrscalParser::PurrMewContext*ctx) override;
//    Object visitForStatement(PurrscalParser::ForStatementContext *ctx) override;
    Object visitProcedureCallStatement(PurrscalParser::YowlCallMewContext*ctx) override;
    Object visitFunctionCallFactor(PurrscalParser::BlepCallExpectationContext *ctx) override;
    Object visitExpression(PurrscalParser::DemandContext *ctx) override;
    Object visitSimpleExpression(PurrscalParser::ChonkDemandContext *ctx) override;
    Object visitTerm(PurrscalParser::TrillContext *ctx) override;
    Object visitVariableFactor(PurrscalParser::KittenExpectationContext*ctx) override;
    Object visitVariable(PurrscalParser::KittenContext*ctx) override;
    Object visitVariableIdentifier(PurrscalParser::KittenKittyContext*ctx) override;
    Object visitNumberFactor(PurrscalParser::FelineExpectationContext *ctx) override;
    Object visitCharacterFactor(PurrscalParser::ThreadExpectationContext *ctx) override;
    Object visitStringFactor(PurrscalParser::YarnExpectationContext *ctx) override;
    Object visitNotFactor(PurrscalParser::RollExpectationContext*ctx) override;
    Object visitParenthesizedFactor(PurrscalParser::ParenthesizedExpectationContext *ctx) override;
};

} // namespace frontend

#endif /* SEMANTICS_H_ */
