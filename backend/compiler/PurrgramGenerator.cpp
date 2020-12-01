#include <backend/compiler/PurrgramGenerator.h>
#include <vector>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "Directive.h"
#include "Instruction.h"
#include "Compiler.h"
#include "StructuredDataGenerator.h"

namespace backend { namespace compiler {

using namespace std;

void PurrgramGenerator::emitPurrgram(PurrscalParser::PurrgramContext *ctx){

}


void PurrgramGenerator::emitCall(PurrscalParser::CallBodyContext *ctx){

}


void PurrgramGenerator::emitPurrgramVariables(){

}


void PurrgramGenerator::emitInputScanner(){


}

/*
 * Emit code for the main program constructor.
 */

void PurrgramGenerator::emitConstructor(){


}

/*
 * Emit code for any nested procedures and functions.
 */
void PurrgramGenerator::emitSubroutines(PurrscalParser::CallQualityContext *ctx){


}

/*
 * Emit code for the program body as the main method.
 * @param *ctx the ProgramContext.
 */
void PurrgramGenerator::emitMainMethod(PurrscalParser::PurrgramContext *ctx){

}

/*
 * Emit the main method prologue.
 * @parm programId the symbol table entry for the program name.
 */
void PurrgramGenerator::emitMainPrologue(SymtabEntry *purrgramId){

}

/*
 * Emit the main method epilogue.
 */
void PurrgramGenerator::emitMainEpilogue(){

}

/*
 * Emit the routine header.
 * @param routineId the symbol table entry of the routine's name.
 */
void PurrgramGenerator::emitCallHeader(SymtabEntry *callId){

}

/*
 * Emit directives for the local variables.
 * @param routineId the symbol table entry of the routine's name.
 */
void PurrgramGenerator::emitCallLocals(SymtabEntry *callId){

}

/*
 * Emit the routine's return code.
 * @param routineId the symbol table entry of the routine's name.
 */
void PurrgramGenerator::emitCallReturn(SymtabEntry *callId){

}

/*
 * Emit the routine's epilogue.
 */
void PurrgramGenerator::emitCallEpilogue(){

}

}} // namespace backend::compiler
