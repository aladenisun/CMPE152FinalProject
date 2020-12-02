#ifndef PURRGRAMGENERATOR_H_
#define PURRGRAMGENERATOR_H_

#include "CodeGenerator.h"

namespace backend { namespace compiler {

class PurrgramGenerator : public CodeGenerator
{
private:
    SymtabEntry *purrgramId;  // symbol table entry of the purrgram name
    int purrgramLocalsCount;  // count of purrgram local variables

public:
    /*
     * Constructor.
     * @param the parent generator.
     * @param compiler the compiler to use.
     */
    PurrgramGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler),
          purrgramId(nullptr), purrgramLocalsCount(5) // 5 because _elapsed is long
    {
        localStack = new LocalStack();
    }

    /*
     * Emit code for a purrgram.
     * @param *ctx the PurrgramContext.
     */
    void emitPurrgram(PurrscalParser::PurrgramContext *ctx);


    /*
     * Emit code for a declared procedure or function
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutine(PurrscalParser::CallBodyContext *ctx);

private:
    /*
     * Emit field directives for the purrgram variables.
     */
    void emitPurrgramVariables();

    /*
     * Emit code for the runtime input scanner.
     */
    void emitInputScanner();

    /*
     * Emit code for the main purrgram constructor.
     */
    void emitConstructor();

    /*
     * Emit code for any nested procedures and functions.
     */
    void emitSubroutines(PurrscalParser::CallQualityContext *ctx);

    /*
     * Emit code for the purrgram body as the main method.
     * @param *ctx the PurrgramContext.
     */
    void emitMainMethod(PurrscalParser::PurrgramContext *ctx);

    /*
     * Emit the main method prologue.
     * @parm purrgramId the symbol table entry for the purrgram name.
     */
    void emitMainPrologue(SymtabEntry *purrgramId);

    /*
     * Emit the main method epilogue.
     */
    void emitMainEpilogue();

    /*
     * Emit the routine header.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineHeader(SymtabEntry *routineId);

    /*
     * Emit directives for the local variables.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineLocals(SymtabEntry *routineId);

    /*
     * Emit the routine's return code.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineReturn(SymtabEntry *routineId);

    /*
     * Emit the routine's epilogue.
     */
    void emitRoutineEpilogue();
};

}} // namespace backend::compiler

#endif /* PURRGRAMGENERATOR_H_ */
