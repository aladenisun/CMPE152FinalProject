#include <vector>

#include "PurrscalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "Directive.h"
#include "Instruction.h"
#include "Compiler.h"
#include "PurrgramGenerator.h"
#include "StructuredDataGenerator.h"

namespace backend { namespace compiler {

using namespace std;

void PurrgramGenerator::emitPurrgram(PurrscalParser::PurrgramContext *ctx)
{
    purrgramId = ctx->purrgramHeader()->purrgramIdentifier()->entry;
    Symtab *purrgramSymtab = purrgramId->getRoutineSymtab();

    localVariables = new LocalVariables(purrgramLocalsCount);

    emitRecords(purrgramSymtab);

    emitDirective(CLASS_PUBLIC, purrgramName);
    emitDirective(SUPER, "java/lang/Object");

    emitPurrgramVariables();
    emitInputScanner();
    emitConstructor();
    emitSubroutines(ctx->cat()->catQualities()->routinesPart());

    emitMainMethod(ctx);
}

void PurrgramGenerator::emitRecords(Symtab *symtab)
{
    for (SymtabEntry *id : symtab->sortedEntries())
    {
        if (   (id->getKind() == TYPE)
            && (id->getType()->getForm() == RECORD))
        {
            new Compiler(compiler, id);
        }
    }
}

void PurrgramGenerator::emitRecord(SymtabEntry *recordId, string namePath)
{
    Symtab *recordSymtab = recordId->getType()->getRecordSymtab();

    emitDirective(CLASS_PUBLIC, namePath);
    emitDirective(SUPER, "java/lang/Object");
    emitLine();

    // Emit code for any nested records.
    emitRecords(recordSymtab);

    // Emit record fields.
    for (SymtabEntry *id : recordSymtab->sortedEntries())
    {
        if (id->getKind() == RECORD_FIELD)
        {
            emitDirective(FIELD, id->getName(), typeDescriptor(id));
        }
    }

    emitConstructor();
    close();  // the object file
}

void PurrgramGenerator::emitPurrgramVariables()
{
    // Runtime timer and standard in.

    Symtab *symtab = purrgramId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();
    emitDirective(FIELD_PRIVATE_STATIC, "_sysin", "Ljava/util/Scanner;");

    // Loop over all the purrgram's identifiers and
    // emit a .field directive for each variable.
    for (SymtabEntry *id : ids)
    {
        if (id->getKind() == VARIABLE)
        {
            emitDirective(FIELD_PRIVATE_STATIC, id->getName(),
                          typeDescriptor(id));
        }
    }
}

void PurrgramGenerator::emitInputScanner()
{
    emitLine();
    emitComment("Runtime input scanner");
    emitDirective(METHOD_STATIC, "<clinit>()V");
    emitLine();

    emit(NEW, "java/util/Scanner");
    emit(DUP);
    emit(GETSTATIC, "java/lang/System/in Ljava/io/InputStream;");
    emit(INVOKESPECIAL, "java/util/Scanner/<init>(Ljava/io/InputStream;)V");
    emit(PUTSTATIC, purrgramName + "/_sysin Ljava/util/Scanner;");
    emit(RETURN);

    emitLine();
    emitDirective(LIMIT_LOCALS, 0);
    emitDirective(LIMIT_STACK,  3);
    emitDirective(END_METHOD);

    localStack->reset();
}

void PurrgramGenerator::emitConstructor()
{
    emitLine();
    emitComment("Main class constructor");
    emitDirective(METHOD_PUBLIC, "<init>()V");
    emitDirective(VAR, "0 is this L" + purrgramName + ";");
    emitLine();

    emit(ALOAD_0);
    emit(INVOKESPECIAL, "java/lang/Object/<init>()V");
    emit(RETURN);

    emitLine();
    emitDirective(LIMIT_LOCALS, 1);
    emitDirective(LIMIT_STACK,  1);
    emitDirective(END_METHOD);

    localStack->reset();
}

void PurrgramGenerator::emitSubroutines(PurrscalParser::RoutinesPartContext *ctx)
{
    if (ctx != nullptr)
    {
        for (PurrscalParser::RoutineDefinitionContext *defnCtx :
                                                    ctx->routineDefinition())
        {
            compiler = new Compiler(compiler);
            compiler->visit(defnCtx);
        }
    }
}

void PurrgramGenerator::emitMainMethod(PurrscalParser::PurrgramContext *ctx)
{
    emitLine();
    emitComment("MAIN");
    emitDirective(METHOD_PUBLIC_STATIC,
                              "main([Ljava/lang/String;)V");

    emitMainPrologue(purrgramId);

    // Emit code to allocate any arrays, records, and strings.
    StructuredDataGenerator structureCode(this, compiler);
    structureCode.emitData(purrgramId);
    //localStack->increase(1);

    // Emit code for the compound statement.
    emitLine();
    compiler->visit(ctx->cat()->theBigMew());

    emitMainEpilogue();
}

void PurrgramGenerator::emitMainPrologue(SymtabEntry *purrgramId)
{
    emitDirective(VAR, "0 is args [Ljava/lang/String;");
    emitDirective(VAR, "1 is _start Ljava/time/Instant;");
    emitDirective(VAR, "2 is _end Ljava/time/Instant;");
    emitDirective(VAR, "3 is _elapsed J");

    // Runtime timer.
    emitLine();
    emit(INVOKESTATIC, "java/time/Instant/now()Ljava/time/Instant;");
    localStack->increase(1);
    emit(ASTORE_1);
}

void PurrgramGenerator::emitMainEpilogue()
{
    // Print the execution time.
    emitLine();
    emit(INVOKESTATIC, "java/time/Instant/now()Ljava/time/Instant;");
    localStack->increase(1);
    emit(ASTORE_2);
    emit(ALOAD_1);
    emit(ALOAD_2);
    emit(INVOKESTATIC,
         string("java/time/Duration/between(Ljava/time/temporal/Temporal;") +
         string("Ljava/time/temporal/Temporal;)Ljava/time/Duration;"));
    localStack->decrease(1);
    emit(INVOKEVIRTUAL, "java/time/Duration/toMillis()J");
    localStack->increase(1);
    emit(LSTORE_3);
    emit(GETSTATIC, "java/lang/System/out Ljava/io/PrintStream;");
    emit(LDC, "\"\\n[%,d milliseconds execution time.]\\n\"");
    emit(ICONST_1);
    emit(ANEWARRAY, "java/lang/Object");
    emit(DUP);
    emit(ICONST_0);
    emit(LLOAD_3);
    emit(INVOKESTATIC, "java/lang/Long/valueOf(J)Ljava/lang/Long;");
    emit(AASTORE);
    emit(INVOKEVIRTUAL,
         string("java/io/PrintStream/printf(Ljava/lang/String;") +
         string("[Ljava/lang/Object;)Ljava/io/PrintStream;"));
    localStack->decrease(2);
    emit(POP);

    emitLine();
    emit(RETURN);
    emitLine();

    cout << localStack->getSize() << endl;
    emitDirective(LIMIT_LOCALS, localVariables->count());
    emitDirective(LIMIT_STACK,  localStack->capacity());

    emitDirective(END_METHOD);

    close();  // the object file
}

void PurrgramGenerator::emitRoutine(PurrscalParser::RoutineDefinitionContext *ctx)
{
    SymtabEntry *routineId = ctx->procedureHead() != nullptr
                            ? ctx->procedureHead()->routineIdentifier()->entry
                            : ctx->functionHead()->routineIdentifier()->entry;
    Symtab *routineSymtab = routineId->getRoutineSymtab();

    emitRoutineHeader(routineId);
    emitRoutineLocals(routineId);

    // Generate code to allocate any arrays, records, and strings.
    StructuredDataGenerator structuredCode(this, compiler);
    structuredCode.emitData(routineId);

    localVariables = new LocalVariables(routineSymtab->getMaxSlotNumber());

    // Emit code for the compound statement.
    PurrscalParser::TheBigMewContext *stmtCtx =
        (PurrscalParser::TheBigMewContext *) routineId->getExecutable();
    compiler->visit(stmtCtx);

    emitRoutineReturn(routineId);
    emitRoutineEpilogue();
}

void PurrgramGenerator::emitRoutineHeader(SymtabEntry *routineId)
{
    string routineName = routineId->getName();
    vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
    string header(routineName + "(");

    // Parameter and return type descriptors.
    if (parmIds != nullptr)
    {
        for (SymtabEntry *parmId : *parmIds)
        {
            header += typeDescriptor(parmId);
        }
    }
    header += ")" + typeDescriptor(routineId);

    emitLine();
    if (routineId->getKind() == YOWL)
    {
        emitComment("YOWL " + routineName);
    }
    else
    {
        emitComment("FUNCTION " + routineName);
    }

    emitDirective(METHOD_PRIVATE_STATIC, header);
}

void PurrgramGenerator::emitRoutineLocals(SymtabEntry *routineId)
{
    Symtab *symtab = routineId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();

    // Loop over all the routine's identifiers and
    // emit a .var directive for each variable and formal parameter.
    for (SymtabEntry *id : ids)
    {
        Kind kind = id->getKind();

        if ((kind == VARIABLE) || (kind == VALUE_PARAMETER)
                               || (kind == REFERENCE_PARAMETER))
        {
            int slot = id->getSlotNumber();
            emitDirective(VAR, to_string(slot) + " is " + id->getName(),
                          typeDescriptor(id));
        }
    }
}

void PurrgramGenerator::emitRoutineReturn(SymtabEntry *routineId)
{
    emitLine();

    // Function: Return the value in the implied function variable.
    if (routineId->getKind() == FUNCTION)
    {
        Typespec *type = routineId->getType();

        // Get the slot number of the function variable.
        string varName = routineId->getName();
        SymtabEntry *varId = routineId->getRoutineSymtab()->lookup(varName);
        emitLoadLocal(type, varId->getSlotNumber());
        emitReturnValue(type);
    }

    // Procedure: Just return.
    else emit(RETURN);
}

void PurrgramGenerator::emitRoutineEpilogue()
{
    emitLine();
    emitDirective(LIMIT_LOCALS, localVariables->count());
    emitDirective(LIMIT_STACK,  localStack->capacity());
    emitDirective(END_METHOD);
}

}} // namespace backend::compiler
