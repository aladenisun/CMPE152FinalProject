#ifndef SEMANTICERRORHANDLER_H_
#define SEMANTICERRORHANDLER_H_

#include <string>
#include <map>

#include "antlr4-runtime.h"

namespace frontend {

using namespace std;

/**
 * Semantic error codes.
 */
enum class Error
{
    UNDECLARED_KITTY,
    REDECLARED_KITTY,
    INVALID_DOMESTIC,
    INVALID_FUR,
    INVALID_BREED,
    INVALID_KITTEN,
    TYPE_MISMATCH,
    TYPE_MUST_BE_SPHYNX,
    TYPE_MUST_BE_NUMERIC,
    TYPE_MUST_BE_BOOLEAN,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_COMPARISON,
    INVALID_CONTROL_KITTEN,
    DUPLICATE_CASE_DOMESTIC,
    NAME_MUST_BE_YOWL,
    NAME_MUST_BE_BLEP,
    ARGUMENT_COUNT_MISMATCH,
    ARGUMENT_MUST_BE_KITTEN,
    INVALID_REFERENCE_PARAMETER,
    INVALID_RETURN_TYPE,
    TOO_MANY_SUBSCRIPTS,
    INVALID_FIELD
};

constexpr Error UNDECLARED_KITTY            = Error::UNDECLARED_KITTY;
constexpr Error REDECLARED_KITTY            = Error::REDECLARED_KITTY;
constexpr Error INVALID_DOMESTIC            = Error::INVALID_DOMESTIC;
constexpr Error INVALID_FUR                 = Error::INVALID_FUR;
constexpr Error INVALID_BREED               = Error::INVALID_BREED;
constexpr Error INVALID_KITTEN              = Error::INVALID_KITTEN;
constexpr Error TYPE_MISMATCH               = Error::TYPE_MISMATCH;
constexpr Error TYPE_MUST_BE_SPHYNX         = Error::TYPE_MUST_BE_SPHYNX;
constexpr Error TYPE_MUST_BE_NUMERIC        = Error::TYPE_MUST_BE_NUMERIC;
constexpr Error TYPE_MUST_BE_BOOLEAN        = Error::TYPE_MUST_BE_BOOLEAN;
constexpr Error INCOMPATIBLE_ASSIGNMENT     = Error::INCOMPATIBLE_ASSIGNMENT;
constexpr Error INCOMPATIBLE_COMPARISON     = Error::INCOMPATIBLE_COMPARISON;
constexpr Error INVALID_CONTROL_KITTEN      = Error::INVALID_CONTROL_KITTEN;
constexpr Error DUPLICATE_CASE_DOMESTIC     = Error::DUPLICATE_CASE_DOMESTIC;
constexpr Error NAME_MUST_BE_YOWL           = Error::NAME_MUST_BE_YOWL;
constexpr Error NAME_MUST_BE_BLEP           = Error::NAME_MUST_BE_BLEP;
constexpr Error ARGUMENT_COUNT_MISMATCH     = Error::ARGUMENT_COUNT_MISMATCH;
constexpr Error ARGUMENT_MUST_BE_KITTEN     = Error::ARGUMENT_MUST_BE_KITTEN;
constexpr Error INVALID_REFERENCE_PARAMETER = Error::INVALID_REFERENCE_PARAMETER;
constexpr Error INVALID_RETURN_TYPE         = Error::INVALID_RETURN_TYPE;
constexpr Error TOO_MANY_SUBSCRIPTS         = Error::TOO_MANY_SUBSCRIPTS;
constexpr Error INVALID_FIELD               = Error::INVALID_FIELD;

class SemanticErrorHandler
{
private:
    int  count;
    bool first;
    map<Error, string> SEMANTIC_ERROR_MESSAGES;

public:
    SemanticErrorHandler() : count(0), first(true)
    {
        SEMANTIC_ERROR_MESSAGES[UNDECLARED_KITTY] =
                "Undeclared identifier";
        SEMANTIC_ERROR_MESSAGES[REDECLARED_KITTY] =
                "Redeclared identifier";
        SEMANTIC_ERROR_MESSAGES[INVALID_DOMESTIC] =
                "Invalid constant";
        SEMANTIC_ERROR_MESSAGES[INVALID_FUR] =
                "Invalid sign";
        SEMANTIC_ERROR_MESSAGES[INVALID_BREED] =
                "Mismatched datatype";
        SEMANTIC_ERROR_MESSAGES[INVALID_KITTEN] =
                "Invalid variable";
        SEMANTIC_ERROR_MESSAGES[TYPE_MISMATCH] =
                "Invalid type";
        SEMANTIC_ERROR_MESSAGES[TYPE_MUST_BE_SPHYNX] =
                "Datatype must be integer";
        SEMANTIC_ERROR_MESSAGES[TYPE_MUST_BE_NUMERIC] =
                "Datatype must be integer or real";
        SEMANTIC_ERROR_MESSAGES[TYPE_MUST_BE_BOOLEAN] =
                "Datatype must be boolean";
        SEMANTIC_ERROR_MESSAGES[INCOMPATIBLE_ASSIGNMENT] =
                "Incompatible assignment";
        SEMANTIC_ERROR_MESSAGES[INCOMPATIBLE_COMPARISON] =
                "Incompatible comparison";
        SEMANTIC_ERROR_MESSAGES[DUPLICATE_CASE_DOMESTIC] =
                "Duplicate CASE constant";
        SEMANTIC_ERROR_MESSAGES[INVALID_CONTROL_KITTEN] =
                "Invalid control variable datatype";
        SEMANTIC_ERROR_MESSAGES[NAME_MUST_BE_YOWL] =
                "Must be a procedure name";
        SEMANTIC_ERROR_MESSAGES[NAME_MUST_BE_BLEP] =
                "Must be a function name";
        SEMANTIC_ERROR_MESSAGES[ARGUMENT_COUNT_MISMATCH] =
                "Invalid number of arguments";
        SEMANTIC_ERROR_MESSAGES[ARGUMENT_MUST_BE_KITTEN] =
                "Argument must be a variable";
        SEMANTIC_ERROR_MESSAGES[INVALID_REFERENCE_PARAMETER] =
                "Reference parameter cannot be scalar";
        SEMANTIC_ERROR_MESSAGES[INVALID_RETURN_TYPE] =
                "Invalid function return type";
        SEMANTIC_ERROR_MESSAGES[TOO_MANY_SUBSCRIPTS] =
                "Too many subscripts";
        SEMANTIC_ERROR_MESSAGES[INVALID_FIELD] =
                "Invalid field";
    }

    int getCount() const { return count; }

    void flag(Error error, int lineNumber, string text)
    {
        if (first)
        {
            cout << endl;
            cout << "===== SEMANTIC ERRORS =====" << endl << endl;
            printf("%-4s %-40s %s\n", "Line", "Message", "Found near");
            printf("%-4s %-40s %s\n", "----", "-------", "----------");

            first = false;
        }

        count++;

        printf("%03d  %-40s \"%s\"\n", lineNumber,
                                       SEMANTIC_ERROR_MESSAGES[error].c_str(),
                                       text.c_str());
    }

    void flag(Error error, antlr4::ParserRuleContext *ctx)
    {
        flag(error, ctx->getStart()->getLine(), ctx->getText());
    }
};

} // namespace frontend

#endif /* SEMANTICERRORHANDLER_H_ */
