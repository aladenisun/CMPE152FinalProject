#ifndef COMPILER_H_
#define COMPILER_H_

#include <backend/compiler/DemandGenerator.h>
#include <backend/compiler/MewGenerator.h>
#include <backend/compiler/PurrgramGenerator.h>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"

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
    MewGenerator  *mewCode;   // statement code generator
    DemandGenerator *demandCode;  // expression code generator

public:
    /**
     * Constructor for the base compiler.
     * @param purrgramCode the symtab entry for the program name.
     */
    Compiler(SymtabEntry *purrgramId)
        : purrgramId(purrgramId), purrgramName(purrgramId->getName()),
          code(new CodeGenerator(purrgramName, "j", this)),
          purrgramCode(nullptr), mewCode(nullptr),
		  demandCode(nullptr) {}

    /**
     * Constructor for child compilers of procedures and functions.
     * @param parent the parent compiler.
     */
    Compiler(Compiler *parent)
        : purrgramId(parent->purrgramId), purrgramName(parent->purrgramName),
          code(parent->code), purrgramCode(parent->purrgramCode),
		  mewCode(nullptr), demandCode(nullptr) {}


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
    Object visitHowlMew(PurrscalParser::HowlMewContext*ctx) override;
    Object visitPurrMew(PurrscalParser::PurrMewContext*ctx) override;
    Object visitYowlCallMew(PurrscalParser::YowlCallMewContext*ctx) override;
    Object visitDemand(PurrscalParser::DemandContext *ctx) override;
    Object visitKittenExpectation(PurrscalParser::KittenExpectationContext*ctx) override;
    Object visitKitten(PurrscalParser::KittenContext*ctx) override;
    Object visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx) override;
    Object visitThreadExpectation(PurrscalParser::ThreadExpectationContext *ctx) override;
    Object visitYarnExpectation(PurrscalParser::YarnExpectationContext *ctx) override;
    Object visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *ctx) override;
    Object visitRollExpectation(PurrscalParser::RollExpectationContext*ctx) override;
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
        mewCode  = new MewGenerator(purrgramCode, this);
        demandCode = new DemandGenerator(purrgramCode, this);
    }
};

}}  // namespace backend::compiler

#endif /* COMPILER_H_ */
