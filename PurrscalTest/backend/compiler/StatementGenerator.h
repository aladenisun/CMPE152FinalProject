#ifndef STATEMENTGENERATOR_H_
#define STATEMENTGENERATOR_H_

#include <vector>
#include <map>

#include "CodeGenerator.h"

namespace backend { namespace compiler {

using namespace std;

class StatementGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    StatementGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an assignment statement.
     * @param ctx the HungryMewContext.
     */
    void emitAssignment(PurrscalParser::HungryMewContext *ctx);

    /**
     * Emit code for an IF statement.
     * @param ctx the SniffMewContext.
     */
    void emitIf(PurrscalParser::SniffMewContext *ctx);

       /**
     * Emit code for a REPEAT statement.
     * @param ctx the HowlMewContext.
     */
    void emitRepeat(PurrscalParser::HowlMewContext *ctx);

    /**
     * Emit code for a WHILE statement.
     * @param ctx the PurrMewContext.
     */
    void emitWhile(PurrscalParser::PurrMewContext *ctx);


    /**
     * Emit code for a procedure call statement.
     * @param ctx the YowlCallMewContext.
     */
    void emitProcedureCall(PurrscalParser::YowlCallMewContext *ctx);

    /**
     * Emit code for a function call statement.
     * @param ctx the FunctionCallContext.
     */
    void emitFunctionCall(PurrscalParser::BlepCallContext *ctx);

    /**
     * Emit code for a MEOW statement.
     * @param ctx the MeowMewContext.
     */
    void emitMeow(PurrscalParser::MeowMewContext *ctx);

    /**
     * Emit code for a MRROW statement.
     * @param ctx the MrrrMewContext.
     */
    void emitMrrow(PurrscalParser::MrrrMewContext *ctx);

    /**
     * Emit code for a READ statement.
     * @param ctx the StalkMewContext.
     */
    void emitRead(PurrscalParser::StalkMewContext *ctx);

    /**
     * Emit code for a READLN statement.
     * @param ctx the PounceMewContext.
     */
    void emitReadln(PurrscalParser::PounceMewContext *ctx);

private:
    /**
     * Emit a call to a procedure or a function.
     * @param routineId the routine name's symbol table entry.
     * @param argListCtx the ChirpsContext.
     */
    void emitCall(SymtabEntry *routineId,
                  PurrscalParser::ChirpsContext *argListCtx);

    /**
     * Emit code for a call to MEOW or MRROW.
     * @param argsCtx the MeowsContext.
     * @param needLF true if need a line feed.
     */
    void emitMeow(PurrscalParser::MeowsContext *argsCtx, bool needLF);

    /**
     * Create the printf format string.
     * @param argsCtx the MeowsContext.
     * @param format the format string to create.
     * @return the count of expression arguments.
     */
    int createMeowFormat(PurrscalParser::MeowsContext *argsCtx,
                          string& format, bool needLF);

    /**
     * Emit the printf arguments array.
     * @param argsCtx
     * @param exprCount
     */
    void emitArgumentsArray(PurrscalParser::MeowsContext *argsCtx,
                            int exprCount);

    /**
     * Generate code for a call to READ or READLN.
     * @param argsCtx the MrowusContext.
     * @param needSkip true if need to skip the rest of the input line.
     */
    void emitRead(PurrscalParser::MrowusContext *argsCtx, bool needSkip);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
