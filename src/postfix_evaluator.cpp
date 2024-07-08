
#include "postfix_evaluator.hpp"
#include <sstream>

double PostfixEvaluator::evaluateValue(const std::string &token) const
{
    /**
     * *PSEUDOCODE:
        FUNCTION EVALUATE_VALUE(token)
            if  IS_VARIABLE(token) then
                return SYMBOL_TABLE.SEARCH(token)
            ELSE
                return TO_NUMBER(token)
            END IF
        END FUNCTION
    */
    double boolValue = (token == "true") ? 1 : (token == "false") ? 0
                                                                  : -1;
    if (boolValue != -1)
        return boolValue;

    if (isVariable(token))
    {
        return symbolTable.search(token[0]);
    }
    else
    {
        return std::stod(token);
    }
}

bool PostfixEvaluator::isNumber(const std::string &token) const
{
    /**
     * *PSEUDOCODE:
        FUNCTION IS_NUMBER(token)
            if token can be converted to a number:
                return TRUE
            return FALSE otherwise
        END FUNCTION
    */
    try
    {
        (void)std::stod(token);
        return true;
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
}

bool PostfixEvaluator::isVariable(const std::string &token) const
{
    /**
     * *PSEUDOCODE:
        FUNCTION IS_VARIABLE(token)
            IF LENGTH(token) = 1
            AND token is a letter between "A" AND "Z"
                return TRUE
            return FALSE
        END FUNCTION
    */
    return (token.length() == 1 && token[0] >= 'A' && token[0] <= 'Z');
}

//////////////////////////////////////////////////////////////////
/**
 * *PSEUDOCODE:
    FUNCTION PERFORM_OPERATION(operation)
    DECLARE a, b AS DOUBLE
    if operation = "+" THEN
        b ← EVALUATE_VALUE(stack.POP())
        a ← EVALUATE_VALUE(stack.POP())
    ...
    else
        THROW "Invalid token in expression"
 */
void PostfixEvaluator::performOperation(const std::string &operation)
{
    double a, b;

    const std::array<std::string, 30> validOperations = {
        "+",     // 0
        "-",     // 1
        "*",     // 2
        "/",     // 3
        "%",     // 4
        "pow",   // 5
        "sqrt",  // 6
        "cbrt",  // 7
        "hyp",   // 8
        "floor", // 9
        "ceil",  // 10
        "abs",   // 11
        "sgn",   // 12
        "round", // 13
        "!",     // 14
        "log10", // 15
        "log2",  // 16
        "perm",  // 17
        "comb",  // 18
        "gcd",   // 19
        "lcm",   // 20
        "sin",   // 21
        "cos",   // 22
        "tan",   // 23
        "asin",  // 24
        "acos",  // 25
        "atan",  // 26
        "ge",    // 27
        "le",    // 28
        "=="     // 29
    };
    auto it = std::find(validOperations.begin(), validOperations.end(), operation);
    if (it == validOperations.end())
    {
        throw std::runtime_error("Invalid token in expression: " + operation);
    }

    switch (std::distance(validOperations.begin(), it))
    {
    case 0: // "+"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::add(a, b)));
        break;
    case 1: // "-"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::subtract(a, b)));
        break;
    case 2: // "*"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::multiply(a, b)));
        break;
    case 3: // "/"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::divide(a, b)));
        break;
    case 4: // "%"
        b = static_cast<int>(evaluateValue(stack.pop()));
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::modulus(a, b)));
        break;
    case 5: // "pow"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::power(a, b)));
        break;
    case 6: // "sqrt"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::squareRoot(a)));
        break;
    case 7: // "cbrt"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::cubeRoot(a)));
        break;
    case 8: // "hyp"
        b = evaluateValue(stack.pop());
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::hypotenuse(a, b)));
    case 9: // "floor"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::floor(a)));
        break;
    case 10: // "ceil"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::ceil(a)));
        break;
    case 11: // "abs"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::abs(a)));
        break;
    case 12: // "sgn"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::sign(a)));
        break;
    case 13: // "round"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::round(a)));
        break;
    case 14: //"!"
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::factorial(static_cast<int>(a))));
        break;
    case 15: // "log10"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::log10(a)));
        break;
    case 16: // "log2"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::log2(a)));
        break;
    case 17: // "perm"
        b = static_cast<int>(evaluateValue(stack.pop()));
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::perm(static_cast<int>(a), static_cast<int>(b))));

        break;
    case 18: // "comb"
        b = static_cast<int>(evaluateValue(stack.pop()));
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::comb(static_cast<int>(a), static_cast<int>(b))));
        break;
    case 19: // "gcd"
        b = static_cast<int>(evaluateValue(stack.pop()));
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::gcd(static_cast<int>(a), static_cast<int>(b))));
        break;
    case 20: // "lcm"
        b = static_cast<int>(evaluateValue(stack.pop()));
        a = static_cast<int>(evaluateValue(stack.pop()));
        stack.push(std::to_string(MathOperations::lcm(static_cast<int>(a), static_cast<int>(b))));
        break;
    case 21: // "sin"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::sin(a)));
        break;
    case 22: // "cos"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::cos(a)));
        break;
    case 23: // "tan"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::tan(a)));
        break;
    case 24: // "asin"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::arcSin(a)));
        break;
    case 25: // "acos"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::arcCos(a)));
        break;
    case 26: // "atan"
        a = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::arcTan(a)));
        break;
    case 27: // "ge"
        a = evaluateValue(stack.pop());
        b = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::isGreater(a, b)));
        break;
    case 28: // "le"
        a = evaluateValue(stack.pop());
        b = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::isLess(a, b)));
        break;
    case 29: // "=="
        a = evaluateValue(stack.pop());
        b = evaluateValue(stack.pop());
        stack.push(std::to_string(MathOperations::isEqual(a, b)));
        break;
    }
}
////////////////////////////////////////////////////////////////////////////
Result PostfixEvaluator::evaluate(const std::string &expression)
{
    /**
     * *PSEUDOCODE:
        FUNCTION EVALUATE(expression)
            DECLARE tokens AS LIST OF STRING = SPLIT(expression, " ")
            DECLARE assign AS BOOL

            FOR EACH token IN tokens DO
                IF IS_NUMBER(token) OR IS_VARIABLE(token) THEN
                    stack.PUSH(token)
                ELSE IF token = "=" THEN
                    DECLARE value AS DOUBLE = EVALUATE_VALUE(stack.POP())
                    DECLARE key AS STRING = stack.POP()
                    IF LENGTH(key) ≠ 1 OR NOT IS_ALPHA(key[0]) THEN
                        THROW "Invalid variable name"
                    END IF
                    SYMBOL_TABLE.INSERT(key, value)
                    assign = true
                ELSE
                    PERFORM_OPERATION(token)
                END IF
            END FOR

            result = NULL
            IF stack.is_empty() = FALSE
                result = stack.pop()
                if stack.is_empty() = FALSE THEN
                    stack.clearStack()
                    THROW "Invalid expression"
            END IF
            RETURN result
        END FUNCTION
    */

    std::istringstream iss(expression);
    std::string token;

    Result result;

    while (iss >> token)
    {
        if (isNumber(token) || isVariable(token))
        {
            stack.push(token);
        }
        else if (token == "=")
        {
            double value = evaluateValue(stack.pop());
            std::string key = stack.pop();
            if (key.length() != 1 || !isalpha(key[0]))
            {
                throw std::runtime_error("Invalid variable name");
            }
            symbolTable.insert(key[0], value);
            result.isAssignment = true;
        }
        else
        {
            performOperation(token);
        }
    }

    if (!stack.isEmpty())
    {
        result.result = evaluateValue(stack.pop());
        if (!stack.isEmpty())
        {
            stack.clearStack();
            throw std::runtime_error("Invalid expression");
        }
        result.isResult = true;
    }
    return result;
}
/////////////////////////////////////////////////
void PostfixEvaluator::printSymbolTable()
{
    symbolTable.printST();
}