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
     * Get the name of the object (Jasmin) file.
     * @return the file name.
     */
    string getObjectFileName() { return code->getObjectFileName(); }

    Object visitPurrgram(PurrscalParser::PurrgramContext *ctx) override;
    Object visitCallBody(PurrscalParser::CallBodyContext *ctx) override;
    Object visitMew(PurrscalParser::MewContext *ctx) override;
    Object visitHungryMew(PurrscalParser::HungryMewContext *ctx) override;
    Object visitSniffMew(PurrscalParser::SniffMewContext *ctx) override;
    Object visitHowlMew(PurrscalParser::HowlMewContext *ctx) override;
    Object visitPurrMew(PurrscalParser::PurrMewContext *ctx) override;
    Object visitYowlCallMew(PurrscalParser::YowlCallMewContext *ctx) override;
    Object visitDemand(PurrscalParser::DemandContext *ctx) override;
    Object visitKittenExpectation(PurrscalParser::KittenExpectationContext *ctx) override;
    Object visitKitten(PurrscalParser::KittenContext *ctx) override;
    Object visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx) override;
    Object visitThreadBallExpectation(PurrscalParser::ThreadBallExpectationContext *ctx) override;
    Object visitYarnBallExpectation(PurrscalParser::YarnBallExpectationContext *ctx) override;
    Object visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *context) override;
    Object visitRollExpectation(PurrscalParser::RollExpectationContext *ctx) override;
    Object visitParenthesizedExpectation(PurrscalParser::ParenthesizedExpectationContext *ctx) override;
    Object visitMeowMew(PurrscalParser::MeowMewContext *ctx) override;
    Object visitMrrrMew(PurrscalParser::MrrrMewContext *ctx) override;
    Object visitStalkMew(PurrscalParser::StalkMewContext *ctx) override;
    Object visitPounceMew(PurrscalParser::PounceMewContext *ctx) override;

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
