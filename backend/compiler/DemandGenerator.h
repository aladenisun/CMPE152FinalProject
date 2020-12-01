#ifndef DEMANDGENERATOR_H_
#define DEMANDGENERATOR_H_

#include "CodeGenerator.h"

namespace backend { namespace compiler {

class DemandGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    DemandGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an expression.
     * @param ctx the ExpressionContext.
     */
    void emitDemand(PurrscalParser::DemandContext *ctx);

    /**
     * Emit code for a simple expression.
     * @param ctx the SimpleExpressionContext.
     */
    void emitChonkDemand(PurrscalParser::ChonkDemandContext*ctx);

    /**
     * Emit code for a term.
     * @param ctx the TermContext.
     */
    void emitTrill(PurrscalParser::TrillContext*ctx);

    /**
     * Emit code for NOT.
     * @param ctx the NotFactorContext.
     */
    void emitRollExpectation(PurrscalParser::RollExpectationContext *ctx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param ctx the VariableContext.
     */
    void emitLoadValue(PurrscalParser::KittenContext*varCtx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param variableNode the variable node.
     */
    Typespec *emitLoadKitten(PurrscalParser::KittenContext*varCtx);

    /**
     * Emit code to load an integer constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadIntegerDomestic(PurrscalParser::FelineContext *intCtx);

    /**
     * Emit code to load real constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadRealDomestic(PurrscalParser::FelineContext *realCtx);

private:

    /**
     * Emit code to access an array element by loading the array address
     * and the subscript value. This can subsequently be followed by code
     * to load the array element's value or to store into the array element.
     * @param subscriptsNode the SUBSCRIPTS node.
     * @param elmtType the array element type.
     * @param lastModifier true if this is the variable's last modifier.
     * @return the type of the element.
     */
    Typespec *emitLoadArrayElementAccess(
                                    PurrscalParser::IndicesContext *indexListCtx,
                                    Typespec *elmtType, bool lastModifier);

    /**
     * Emit a load of an array element's value.
     * @param elmtType the element type if character, else nullptr.
     */
    void emitLoadArrayElementValue(Typespec *elmtType);

//    void emitLoadRecordFieldValue(
//                    PurrscalParser::ChungusContext*fieldCtx, Typespec *recordType);

    /**
     * Emit code to load the address or value of a record field.
     * @param fieldCtx the FieldContext.
     * @param last true if this is the variable's last field, else false.
     * @return the type of the field.
     */
//    Typespec *emitLoadRecordField(
//                    PurrscalParser::ChungusContext *fieldCtx, Typespec *recordType);
};

}} // namespace backend::compiler

#endif /* DemandGenerator_H_ */
