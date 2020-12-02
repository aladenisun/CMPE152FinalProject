#ifndef COMPILER_H_
#define COMPILER_H_

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "PurrgramGenerator.h"
#include "StatementGenerator.h"
#include "ExpressionGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class CodeGenerator;

class Compiler : public PurrscalBaseVisitor
{
private:
    SymtabEntry *purrgramId;  // symbol table entry of the purrgram name
    string purrgramName;      // the purrgram name

    CodeGenerator       *code;            // base code generator
    PurrgramGenerator    *purrgramCode;     // purrgram code generator
    StatementGenerator  *statementCode;   // statement code generator
    ExpressionGenerator *expressionCode;  // expression code generator

public:
    /**
     * Constructor for the base compiler.
     * @param purrgramId the symtab entry for the purrgram name.
     */
    Compiler(SymtabEntry *purrgramId)
        : purrgramId(purrgramId), purrgramName(purrgramId->getName()),
          code(new CodeGenerator(purrgramName, "j", this)),
          purrgramCode(nullptr), statementCode(nullptr),
          expressionCode(nullptr) {}

    /**
     * Constructor for child compilers of procedures and functions.
     * @param parent the parent compiler.
     */
    Compiler(Compiler *parent)
        : purrgramId(parent->purrgramId), purrgramName(parent->purrgramName),
          code(parent->code), purrgramCode(parent->purrgramCode),
          statementCode(nullptr), expressionCode(nullptr) {}

    /**
     * Constructor for child compilers of records.
     * @param parent the parent compiler.
     * @param recordId the symbol table entry of the name of the record to compile.
     */
    Compiler(Compiler *parent, SymtabEntry *recordId)
    {
        string recordTypePath = recordId->getType()->getRecordTypePath();
        code = new CodeGenerator(recordTypePath, "j", this);
        createNewGenerators(code);

        purrgramCode->emitRecord(recordId, recordTypePath);
    }

    /**
     * Get the name of the object (Jasmin) file.
     * @return the file name.
     */
    string getObjectFileName() { return code->getObjectFileName(); }

    Object visitPurrgram(PurrscalParser::PurrgramContext *ctx) override;
    Object visitRoutineDefinition(PurrscalParser::RoutineDefinitionContext *ctx) override;
    Object visitStatement(PurrscalParser::StatementContext *ctx) override;
    Object visitAssignmentStatement(PurrscalParser::AssignmentStatementContext *ctx) override;
    Object visitIfStatement(PurrscalParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(PurrscalParser::CaseStatementContext *ctx) override;
    Object visitRepeatStatement(PurrscalParser::RepeatStatementContext *ctx) override;
    Object visitWhileStatement(PurrscalParser::WhileStatementContext *ctx) override;
    Object visitForStatement(PurrscalParser::ForStatementContext *ctx) override;
    Object visitProcedureCallStatement(PurrscalParser::ProcedureCallStatementContext *ctx) override;
    Object visitExpression(PurrscalParser::ExpressionContext *ctx) override;
    Object visitVariableFactor(PurrscalParser::VariableFactorContext *ctx) override;
    Object visitVariable(PurrscalParser::VariableContext *ctx) override;
    Object visitNumberFactor(PurrscalParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(PurrscalParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(PurrscalParser::StringFactorContext *ctx) override;
    Object visitFunctionCallFactor(PurrscalParser::FunctionCallFactorContext *context) override;
    Object visitNotFactor(PurrscalParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(PurrscalParser::ParenthesizedFactorContext *ctx) override;
    Object visitMeowStatement(PurrscalParser::MeowStatementContext *ctx) override;
    Object visitMrrowStatement(PurrscalParser::MrrowStatementContext *ctx) override;
    Object visitReadStatement(PurrscalParser::ReadStatementContext *ctx) override;
    Object visitReadlnStatement(PurrscalParser::ReadlnStatementContext *ctx) override;

private:
    /**
     * Create new child code generators.
     * @param parentGenerator the parent code generator.
     */
    void createNewGenerators(CodeGenerator *parentGenerator)
    {
        purrgramCode    = new PurrgramGenerator(parentGenerator, this);
        statementCode  = new StatementGenerator(purrgramCode, this);
        expressionCode = new ExpressionGenerator(purrgramCode, this);
    }
};

}}  // namespace backend::compiler

#endif /* COMPILER_H_ */
