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
    bool expressionIsVariable(PurrscalParser::DemandContext *exprCtx);

    /**
     * Perform semantic operations on procedure and function call arguments.
     * @param listCtx the ChirpsContext.
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


public:
    Semantics(BackendMode mode) : mode(mode), purrgramId(nullptr)
    {
        // Create and initialize the symbol table stack.
        symtabStack = new SymtabStack();
        Predefined::initialize(symtabStack);

        typeTable = new map<string, Typespec *>();
        (*typeTable)["sphynx"] = Predefined::integerType;
        (*typeTable)["feline"]    = Predefined::realType;
        (*typeTable)["schroedinger"] = Predefined::booleanType;
        (*typeTable)["thread"]    = Predefined::charType;
        (*typeTable)["yarn"]  = Predefined::stringType;
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
    Object visitPurrgramSnoot(PurrscalParser::PurrgramSnootContext *ctx) override;
    Object visitDomesticBody(PurrscalParser::DomesticBodyContext *ctx) override;
    Object visitDomestic(PurrscalParser::DomesticContext *ctx) override;
    Object visitBreedBody(PurrscalParser::BreedBodyContext *ctx) override;
    Object visitChonkspec(PurrscalParser::ChonkspecContext *ctx) override;
    Object visitKittyBreedspec(PurrscalParser::KittyBreedspecContext *ctx) override;
    Object visitKittyBreed(PurrscalParser::KittyBreedContext *ctx) override;
    Object visitFluffballspec(PurrscalParser::FluffballspecContext *ctx) override;
    Object visitKittenKaboodleBasketspec(PurrscalParser::KittenKaboodleBasketspecContext *ctx) override;
    Object visitKaboodlespec(PurrscalParser::KaboodlespecContext *ctx) override;
    Object visitKittenBody(PurrscalParser::KittenBodyContext *ctx) override;
    Object visitCallBody(PurrscalParser::CallBodyContext *ctx) override;
    Object visitPurrameterPurrs(PurrscalParser::PurrameterPurrsContext *ctx) override;
    Object visitPurrameterPurr(PurrscalParser::PurrameterPurrContext *ctx) override;
    Object visitHungryMew(PurrscalParser::HungryMewContext *ctx) override;
    Object visitLps(PurrscalParser::LpsContext *ctx) override;
    Object visitSniffMew(PurrscalParser::SniffMewContext *ctx) override;
    Object visitHowlMew(PurrscalParser::HowlMewContext *ctx) override;
    Object visitPurrMew(PurrscalParser::PurrMewContext *ctx) override;
    Object visitYowlCallMew(PurrscalParser::YowlCallMewContext *ctx) override;
    Object visitBlepCallExpectation(PurrscalParser::BlepCallExpectationContext *ctx) override;
    Object visitDemand(PurrscalParser::DemandContext *ctx) override;
    Object visitChonkDemand(PurrscalParser::ChonkDemandContext *ctx) override;
    Object visitTrill(PurrscalParser::TrillContext *ctx) override;
    Object visitKittenExpectation(PurrscalParser::KittenExpectationContext *ctx) override;
    Object visitKitten(PurrscalParser::KittenContext *ctx) override;
    Object visitKittenKitty(PurrscalParser::KittenKittyContext *ctx) override;
    Object visitFelineExpectation(PurrscalParser::FelineExpectationContext *ctx) override;
    Object visitThreadBallExpectation(PurrscalParser::ThreadBallExpectationContext *ctx) override;
    Object visitYarnBallExpectation(PurrscalParser::YarnBallExpectationContext *ctx) override;
    Object visitRollExpectation(PurrscalParser::RollExpectationContext *ctx) override;
    Object visitParenthesizedExpectation(PurrscalParser::ParenthesizedExpectationContext *ctx) override;
};

} // namespace frontend

#endif /* SEMANTICS_H_ */
