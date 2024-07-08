#include <iostream>
#include <string>
#include "postfix_evaluator.hpp"

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string SOFT_PINK = "\033[38;5;225m";

/**
 * @brief Display the allowed variables and usage instructions.
 */
void displayInstructions()
{
    std::cout << SOFT_PINK << "\nPostfix Expression Evaluator\n";
    std::cout << "=============================\n";
    std::cout << "Allowed variables: [A-Z]\n";
    std::cout << "Operations supported:\n";
    std::cout << " +  : Addition\n";
    std::cout << " -  : Subtraction\n";
    std::cout << " *  : Multiplication\n";
    std::cout << " /  : Division\n";
    std::cout << " %  : Modulus\n";
    std::cout << " floor : Floor function\n";
    std::cout << " ceil  : Ceiling function\n";
    std::cout << " round : Round function\n";
    std::cout << " abs   : Absolute value\n";
    std::cout << " cos   : Cosine\n";
    std::cout << " sin   : Sine\n";
    std::cout << " tan   : Tangent\n";
    std::cout << " log10 : Logarithm base 10\n";
    std::cout << " log2  : Logarithm base 2\n";
    std::cout << " pow   : Power function\n";
    std::cout << " sqrt  : Square root function\n";
    std::cout << " cbrt  : Cube root function\n";
    std::cout << " hyp   : Hypotenuse function\n";
    std::cout << " asin  : Arcsine function\n";
    std::cout << " acos  : Arccosine function\n";
    std::cout << " atan  : Arctangent function\n";
    std::cout << " !     : Factorial function\n";
    std::cout << " sgn   : Sign function\n";
    std::cout << " perm  : Permutations function\n";
    std::cout << " comb  : Combinations function\n";
    std::cout << " gcd   : Greatest Common Divisor function\n";
    std::cout << " lcm   : Least Common Multiple function\n";
    std::cout << " ==    : Equality comparison (TRUE = 1, FALSE = 0)\n";
    std::cout << " >     : Greater than comparison (TRUE = 1, FALSE = 0)\n";
    std::cout << " <     : Less than comparison (TRUE = 1, FALSE = 0)\n";
    std::cout << "Enter 'exit' to quit the program.\n";
    std::cout << "Note: Ensure your expressions are space-separated.\n";
    std::cout << "Example: A 5 = B 3 = A B +\n";
    std::cout << "=============================\n";
    std::cout << "Write 'vars' to display assigned variables.\n"
              << RESET;
}

/**
 * @brief The main function of the program.
 *
 * This function handles user input, evaluates the postfix expression using the PostfixEvaluator, and prints the result to the terminal.
 */
int main()
{
    displayInstructions();
    PostfixEvaluator evaluator;
    std::string input;

    while (true)
    {
        std::cout << "\n"
                  << CYAN << "Enter postfix expression: "
                             "\n"
                  << RESET;
        std::getline(std::cin, input);

        if (input == "exit")
        {
            break;
        }
        else if (input == "vars")
        {
            evaluator.printSymbolTable();
        }
        else
        {
            try
            {
                Result result = evaluator.evaluate(input);
                if (result.isAssignment == true)
                    std::cout << "Assignment successful.\n";
                if (result.isResult == true)
                    std::cout << SOFT_PINK << "Result: " << result.result << "\n"
                              << RESET;
            }
            catch (const std::exception &e)
            {
                std::cerr << RED << "Error: " << e.what() << "\n"
                          << RESET;
            }
        }
    }

    std::cout << SOFT_PINK << "Exiting program. Goodbye!\n"
              << RESET;
    return 0;
}
