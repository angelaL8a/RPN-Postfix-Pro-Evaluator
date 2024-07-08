#ifndef POSTFIX_EVALUATOR_HPP
#define POSTFIX_EVALUATOR_HPP

#include <string>
#include <stdexcept>

#include <cmath>
#include <array>
#include <iterator>
#include <algorithm>

#include "stack.hpp"
#include "symbol_table.hpp"
#include "math_operations.hpp"

class Result
{
public:
    bool isAssignment = false;
    bool isResult = false;
    double result;
};

/**
 * @class PostfixEvaluator
 * @brief Evaluates postfix expressions
 *
 * This class evaluates postfix expressions by using a stack to hold operands and a symbol table to hold variable values.
 */
class PostfixEvaluator
{
private:
    Stack<std::string> stack; // Stack to hold operands
    SymbolTable symbolTable;  // Symbol table to hold variable values

    /**
     * @brief Checks if a token is a number
     *
     * This method checks if a given token is a number.
     *
     * @param token The token to be checked
     * @return True if the token is a number, false otherwise
     */
    bool isNumber(const std::string &token) const;

    /**
     * @brief Checks if a token is a variable [A..Z]
     *
     * This method checks if a given token is a variable [A..Z].
     *
     * @param token The token to be checked
     * @return True if the token is a variable, false otherwise
     */
    bool isVariable(const std::string &token) const;

    /**
     * @brief Performs an operation on the stack
     *
     * This method performs an operation on the stack using the top (one/two) operand(s) and the given operation.
     *
     * @param operation The operation to be performed
     */
    void performOperation(const std::string &operation);

    // void assignKey(const std::string &key, const std::string &value)

    /**
     * @brief Evaluates the value of a token in a postfix expression.
     *
     * This function evaluates the numeric value of a token in a postfix expression.
     * If the token represents a variable, it searches for its value in the symbol table. If the token is a numeric literal, it converts it to a double and returns the value.
     *
     * @param token A string representing a token in the postfix expression.
     * @return The numeric value of the token.
     */
    double evaluateValue(const std::string &token) const;

public:
    /**
     * @brief Evaluates a postfix expression
     *
     * This method evaluates a postfix expression and returns the result.
     *
     * @param expression The postfix expression to be evaluated
     * @return A Result object containing the result and whether it was an assignment
     */
    Result evaluate(const std::string &expression);
    void printSymbolTable();
};

#endif // POSTFIX_EVALUATOR_HPP