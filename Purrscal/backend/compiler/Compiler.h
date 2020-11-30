#ifndef COMPILER_H_
#define COMPILER_H_

#include <backend/compiler/PurrgramGenerator.h>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
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
    PurrgramGenerator    *purrgramCode;     // program code generator
    StatementGenerator  *statementCode;   // statement code generator
    ExpressionGenerator *expressionCode;  // expression code generator

public:
    /**
     * Constructor for the base compiler.
     * @param purrgramCode the symtab entry for the program name.
     */
    Compiler(SymtabEntry *purrgramCode)
        : purrgramCode(purrgramCode), purrgramName(purrgramCode->getName()),
          code(new CodeGenerator(purrgramName, "j", this)),
          purrgramCode(nullptr), statementCode(nullptr),
          expressionCode(nullptr) {}

    /**
     * Constructor for child compilers of procedures and functions.
     * @param parent the parent compiler.
     */
    Compiler(Compiler *parent)
        : purrgramCode(parent->purrgramCode), purrgramName(parent->purrgramName),
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

    Object visitProgram(PurrscalParser::PurrgramContext *ctx) override;
    Object visitRoutineDefinition(PurrscalParser::CallBodyContext *ctx) override;
    Object visitStatement(PurrscalParser::MewContext *ctx) override;
    Object visitAssignmentStatement(PurrscalParser::HungryMewContext *ctx) override;
    Object visitIfStatement(PurrscalParser::SniffMewContext*ctx) override;
//    Object visitCaseStatement(PurrscalParser::CaseStatementContext *ctx) override;
    Object visitRepeatStatement(PurrscalParser::HowlMewContext *ctx) override;
    Object visitWhileStatement(PurrscalParser::PurrMewContext *ctx) override;
//    Object visitForStatement(PurrscalParser::ForStatementContext *ctx) override;
    Object visitProcedureCallStatement(PurrscalParser::YowlCallMewContext *ctx) override;
    Object visitExpression(PurrscalParser::DemandContext *ctx) override;
    Object visitVariableFactor(PurrscalParser::KittenExpectationContext*ctx) override;
    Object visitVariable(PurrscalParser::KittenContext *ctx) override;
    Object visitNumberFactor(PurrscalParser::FelineExpectationContext*ctx) override;
    Object visitCharacterFactor(PurrscalParser::ThreadExpectationContext *ctx) override;
    Object visitStringFactor(PurrscalParser::YarnExpectationContext*ctx) override;
    Object visitFunctionCallFactor(PurrscalParser::BlepCallExpectationContext *context) override;
    Object visitNotFactor(PurrscalParser::RollExpectationContext *ctx) override;
    Object visitParenthesizedFactor(PurrscalParser::ParenthesizedExpectationContext *ctx) override;
    Object visitWriteStatement(PurrscalParser::MeowMewContext *ctx) override;
    Object visitWritelnStatement(PurrscalParser::MrrrMewContext *ctx) override;
    Object visitReadStatement(PurrscalParser::StalkMewContext *ctx) override;
    Object visitReadlnStatement(PurrscalParser::PounceMewContext *ctx) override;

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
