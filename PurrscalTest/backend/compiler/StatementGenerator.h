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
    void emitAssignment(PurrscalParser::AssignmentStatementContext *ctx);

    /**
     * Emit code for an IF statement.
     * @param ctx the IfStatementContext.
     */
    void emitIf(PurrscalParser::IfStatementContext *ctx);

    /**
     * Emit code for a CASE statement.
     * @param ctx the CaseStatementContext.
     */
    void emitCase(PurrscalParser::CaseStatementContext *ctx);

    /**
     * Emit code for a REPEAT statement.
     * @param ctx the RepeatStatementContext.
     */
    void emitRepeat(PurrscalParser::RepeatStatementContext *ctx);

    /**
     * Emit code for a WHILE statement.
     * @param ctx the WhileStatementContext.
     */
    void emitWhile(PurrscalParser::WhileStatementContext *ctx);

    /**
     * Emit code for a FOR statement.
     * @param ctx the ForStatementContext.
     */
    void emitFor(PurrscalParser::ForStatementContext *ctx);

    /**
     * Emit code for a procedure call statement.
     * @param ctx the ProcedureCallStatementContext.
     */
    void emitProcedureCall(PurrscalParser::ProcedureCallStatementContext *ctx);

    /**
     * Emit code for a function call statement.
     * @param ctx the FunctionCallContext.
     */
    void emitFunctionCall(PurrscalParser::FunctionCallContext *ctx);

    /**
     * Emit code for a MEOW statement.
     * @param ctx the MeowStatementContext.
     */
    void emitMeow(PurrscalParser::MeowStatementContext *ctx);

    /**
     * Emit code for a MRROW statement.
     * @param ctx the MrrowStatementContext.
     */
    void emitMrrow(PurrscalParser::MrrowStatementContext *ctx);

    /**
     * Emit code for a READ statement.
     * @param ctx the ReadStatementContext.
     */
    void emitRead(PurrscalParser::ReadStatementContext *ctx);

    /**
     * Emit code for a READLN statement.
     * @param ctx the ReadlnStatementContext.
     */
    void emitReadln(PurrscalParser::ReadlnStatementContext *ctx);

private:
    /**
     * Process the CASE map from the CASE branches.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels.
     * @return the array list of table entries.
     */
    map<int, Label *> *createCaseMap(
                            PurrscalParser::CaseBranchListContext *branchListCtx,
                            vector<Label *>& branchLabels);

    /**
     * Emit code for the LOOKUPSWITCH instruction.
     * @param entries the table entries.
     * @param branchLabels the branch labels.
     */
    void emitLookupSwitch(map<int, Label *> *labelMap,
                          vector<Label *>& branchLabels);

    /**
     * Emit code for the branch statements.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels
     * @throws PurrscalCompilerException if an error occurred.
     */
    void emitBranchStatements(
                            PurrscalParser::CaseBranchListContext *branchListCtx,
                            vector<Label *>& branchLabels);

    /**
     * Emit a call to a procedure or a function.
     * @param routineId the routine name's symbol table entry.
     * @param argListCtx the ArgumentListContext.
     */
    void emitCall(SymtabEntry *routineId,
                  PurrscalParser::ArgumentListContext *argListCtx);

    /**
     * Emit code for a call to MEOW or MRROW.
     * @param argsCtx the MeowArgumentsContext.
     * @param needLF true if need a line feed.
     */
    void emitMeow(PurrscalParser::MeowArgumentsContext *argsCtx, bool needLF);

    /**
     * Create the printf format string.
     * @param argsCtx the MeowArgumentsContext.
     * @param format the format string to create.
     * @return the count of expression arguments.
     */
    int createMeowFormat(PurrscalParser::MeowArgumentsContext *argsCtx,
                          string& format, bool needLF);

    /**
     * Emit the printf arguments array.
     * @param argsCtx
     * @param exprCount
     */
    void emitArgumentsArray(PurrscalParser::MeowArgumentsContext *argsCtx,
                            int exprCount);

    /**
     * Generate code for a call to READ or READLN.
     * @param argsCtx the ReadArgumentsContext.
     * @param needSkip true if need to skip the rest of the input line.
     */
    void emitRead(PurrscalParser::ReadArgumentsContext *argsCtx, bool needSkip);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
