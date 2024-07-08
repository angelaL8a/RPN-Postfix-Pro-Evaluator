#ifndef MATH_OPERATIONS_HPP
#define MATH_OPERATIONS_HPP

#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <numeric>

class MathOperations
{
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b)
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    static double power(double a, double b) { return std::pow(a, b); }
    static double modulus(double a, double b) { return std::fmod(a, b); }
    static double squareRoot(double a) { return std::sqrt(a); }
    static double cubeRoot(double a) { return std::cbrt(a); }
    static double hypotenuse(double x, double y)
    {
        return std::hypot(x, y);
    }
    static double floor(double a) { return std::floor(a); }
    static double ceil(double a) { return std::ceil(a); }
    static double abs(double a) { return std::abs(a); }
    static int sign(double a) { return (a > 0) - (a < 0); }
    static double round(double a) { return std::round(a); }
    static double factorial(int n)
    {
        if (n < 0)
            throw std::invalid_argument("Factorial is not defined for negative numbers");
        else if (n == 1)
            return n;
        return n * factorial(n - 1);
    }
    static double log10(double a) { return std::log10(a); }
    static double log2(double a) { return std::log2(a); }
    static double perm(int n, int k)
    {
        if (n < 0 || k < 0 || k > n)
            throw std::invalid_argument("Invalid values for perm(n, k)");
        return factorial(n) / factorial(n - k);
    }
    static double comb(int n, int k)
    {
        if (n < 0 || k < 0 || k > n)
            throw std::invalid_argument("Invalid values for comb(n, k)");
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
    static int gcd(int x, int y)
    {
        if (y == 0)
            return std::abs(x);
        else
            return gcd(y, x % y);
    }
    static int lcm(int x, int y)
    {
        if (x == 0 || y == 0)
            return 0;
        return std::abs(x * y) / gcd(x, y);
    }
    static double sin(double a) { return std::sin(a); }
    static double cos(double a) { return std::cos(a); }
    static double tan(double a) { return std::tan(a); }
    static double arcSin(double a) { return std::asin(a); }
    static double arcCos(double a) { return std::acos(a); }
    static double arcTan(double a) { return std::atan(a); }

    static bool isEqual(double a, double b) { return a == b; }
    static bool isGreater(double a, double b) { return a > b; }
    static bool isLess(double a, double b) { return a < b; }
};

#endif // MATH_OPERATIONS_HPP