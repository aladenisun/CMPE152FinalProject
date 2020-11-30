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
     * @param ctx the AssignmentStatementContext.
     */
    void emitAssignment(PurrscalParser::HungryMewContext *ctx);

    /**
     * Emit code for an IF statement.
     * @param ctx the IfStatementContext.
     */
    void emitIf(PurrscalParser::SniffMewContext*ctx);

    /**
     * Emit code for a CASE statement.
     * @param ctx the CaseStatementContext.
     */
//    void emitCase(PurrscalParser::CaseStatementContext *ctx);

    /**
     * Emit code for a REPEAT statement.
     * @param ctx the RepeatStatementContext.
     */
    void emitRepeat(PurrscalParser::HowlMewContext *ctx);

    /**
     * Emit code for a WHILE statement.
     * @param ctx the WhileStatementContext.
     */
    void emitWhile(PurrscalParser::PurrMewContext *ctx);

    /**
     * Emit code for a FOR statement.
     * @param ctx the ForStatementContext.
     */
//    void emitFor(PurrscalParser::ForStatementContext *ctx);

    /**
     * Emit code for a procedure call statement.
     * @param ctx the ProcedureCallStatementContext.
     */
    void emitProcedureCall(PurrscalParser::YowlCallMewContext*ctx);

    /**
     * Emit code for a function call statement.
     * @param ctx the FunctionCallContext.
     */
    void emitFunctionCall(PurrscalParser::BlepCallContext*ctx);

    /**
     * Emit code for a WRITE statement.
     * @param ctx the WriteStatementContext.
     */
    void emitWrite(PurrscalParser::MeowMewContext *ctx);

    /**
     * Emit code for a WRITELN statement.
     * @param ctx the WritelnStatementContext.
     */
    void emitWriteln(PurrscalParser::MrrrMewContext*ctx);

    /**
     * Emit code for a READ statement.
     * @param ctx the ReadStatementContext.
     */
    void emitRead(PurrscalParser::StalkMewContext *ctx);

    /**
     * Emit code for a READLN statement.
     * @param ctx the ReadlnStatementContext.
     */
    void emitReadln(PurrscalParser::PounceMewContext*ctx);

private:
    /**
     * Process the CASE map from the CASE branches.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels.
     * @return the array list of table entries.
     */
//    map<int, Label *> *createCaseMap(
//                            PurrscalParser::CaseBranchListContext *branchListCtx,
//                            vector<Label *>& branchLabels);

    /**
     * Emit code for the LOOKUPSWITCH instruction.
     * @param entries the table entries.
     * @param branchLabels the branch labels.
     */
//    void emitLookupSwitch(map<int, Label *> *labelMap,
//                          vector<Label *>& branchLabels);

    /**
     * Emit code for the branch statements.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels
     * @throws PascalCompilerException if an error occurred.
     */
//    void emitBranchStatements(
//                            PurrscalParser::CaseBranchListContext *branchListCtx,
//                            vector<Label *>& branchLabels);

    /**
     * Emit a call to a procedure or a function.
     * @param routineId the routine name's symbol table entry.
     * @param argListCtx the ArgumentListContext.
     */
    void emitCall(SymtabEntry *routineId,
                  PurrscalParser::ChirpContext *argListCtx);

    /**
     * Emit code for a call to WRITE or WRITELN.
     * @param argsCtx the WriteArgumentsContext.
     * @param needLF true if need a line feed.
     */
    void emitWrite(PurrscalParser::MeowsContext *argsCtx, bool needLF);

    /**
     * Create the printf format string.
     * @param argsCtx the WriteArgumentsContext.
     * @param format the format string to create.
     * @return the count of expression arguments.
     */
    int createWriteFormat(PurrscalParser::MeowsContext *argsCtx,
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
     * @param argsCtx the ReadArgumentsContext.
     * @param needSkip true if need to skip the rest of the input line.
     */
    void emitRead(PurrscalParser::MrowusContext *argsCtx, bool needSkip);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
