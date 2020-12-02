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
    SymtabEntry *purrgramId;
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
    bool expressionIsVariable(PurrscalParser::ExpressionContext *exprCtx);

    /**
     * Perform semantic operations on procedure and function call arguments.
     * @param listCtx the ArgumentListContext.
     * @param parameters the vector of parameters to fill.
     */
    void checkCallArguments(PurrscalParser::ArgumentListContext *listCtx,
                            vector<SymtabEntry *> *parms);

    /**
     * Determine the datatype of a variable that can have modifiers.
     * @param varCtx the VariableContext.
     * @param varType the variable's datatype without the modifiers.
     * @return the datatype with any modifiers.
     */
    Typespec *variableDatatype(PurrscalParser::VariableContext *varCtx,
                               Typespec *varType);

    /**
     * Create a new record type.
     * @param recordTypeSpecCtx the RecordTypespecContext.
     * @param recordTypeName the name of the record type.
     * @return the symbol table entry of the record type identifier.
     */
    SymtabEntry *createRecordType(
                        PurrscalParser::RecordTypespecContext *recordTypeSpecCtx,
                        string recordTypeName);

    /**
     * Create the fully qualified type pathname of a record type.
     * @param recordType the record type.
     * @return the pathname.
     */
    string createRecordTypePath(Typespec *recordType);

    /**
     * Create the symbol table for a record type.
     * @param ctx the RecordFieldsContext,
     * @param ownerId the symbol table entry of the owner's identifier.
     * @return the symbol table.
     */
    Symtab *createRecordSymtab(
                PurrscalParser::RecordFieldsContext *ctx, SymtabEntry *ownerId);

public:
    Semantics(BackendMode mode) : mode(mode), purrgramId(nullptr)
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
     * Get the symbol table entry of the purrgram identifier.
     * @return the entry.
     */
    SymtabEntry *getpurrgramId() { return purrgramId; }

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

    Object visitPurrgram(PurrscalParser::PurrgramContext *ctx) override;
    Object visitPurrgramHeader(PurrscalParser::PurrgramHeaderContext *ctx) override;
    Object visitConstantDefinition(PurrscalParser::ConstantDefinitionContext *ctx) override;
    Object visitConstant(PurrscalParser::ConstantContext *ctx) override;
    Object visitTypeDefinition(PurrscalParser::TypeDefinitionContext *ctx) override;
    Object visitRecordTypespec(PurrscalParser::RecordTypespecContext *ctx) override;
    Object visitSimpleTypespec(PurrscalParser::SimpleTypespecContext *ctx) override;
    Object visitTypeIdentifierTypespec(PurrscalParser::TypeIdentifierTypespecContext *ctx) override;
    Object visitTypeIdentifier(PurrscalParser::TypeIdentifierContext *ctx) override;
    Object visitEnumerationTypespec(PurrscalParser::EnumerationTypespecContext *ctx) override;
    Object visitSubrangeTypespec(PurrscalParser::SubrangeTypespecContext *ctx) override;
    Object visitArrayTypespec(PurrscalParser::ArrayTypespecContext *ctx) override;
    Object visitVariableDeclarations(PurrscalParser::VariableDeclarationsContext *ctx) override;
    Object visitRoutineDefinition(PurrscalParser::RoutineDefinitionContext *ctx) override;
    Object visitParameterDeclarationsList(PurrscalParser::ParameterDeclarationsListContext *ctx) override;
    Object visitParameterDeclarations(PurrscalParser::ParameterDeclarationsContext *ctx) override;
    Object visitAssignmentStatement(PurrscalParser::AssignmentStatementContext *ctx) override;
    Object visitLhs(PurrscalParser::LhsContext *ctx) override;
    Object visitIfStatement(PurrscalParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(PurrscalParser::CaseStatementContext *ctx) override;
    Object visitRepeatStatement(PurrscalParser::RepeatStatementContext *ctx) override;
    Object visitWhileStatement(PurrscalParser::WhileStatementContext *ctx) override;
    Object visitForStatement(PurrscalParser::ForStatementContext *ctx) override;
    Object visitProcedureCallStatement(PurrscalParser::ProcedureCallStatementContext *ctx) override;
    Object visitFunctionCallFactor(PurrscalParser::FunctionCallFactorContext *ctx) override;
    Object visitExpression(PurrscalParser::ExpressionContext *ctx) override;
    Object visitSimpleExpression(PurrscalParser::SimpleExpressionContext *ctx) override;
    Object visitTerm(PurrscalParser::TermContext *ctx) override;
    Object visitVariableFactor(PurrscalParser::VariableFactorContext *ctx) override;
    Object visitVariable(PurrscalParser::VariableContext *ctx) override;
    Object visitVariableIdentifier(PurrscalParser::VariableIdentifierContext *ctx) override;
    Object visitNumberFactor(PurrscalParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(PurrscalParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(PurrscalParser::StringFactorContext *ctx) override;
    Object visitNotFactor(PurrscalParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(PurrscalParser::ParenthesizedFactorContext *ctx) override;
};

} // namespace frontend

#endif /* SEMANTICS_H_ */
