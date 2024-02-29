#include "fract.h"

fract::fract(int num, unsigned int denom)
    : numerator(num), denominator(denom)
{
    unsigned int divisor = gcd(numerator, denominator);
    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

int fract::num() const
{
    return numerator;
}

unsigned int fract::denom() const
{
    return denominator;
}

void fract::print(std::ostream &os) const
{
    os << num();
    if (denom() != 1)
        os << '/' << denom();
}

bool fract::equal(const fract &right) const
{
    if (numerator == right.num() && denominator == right.denom())
        return true;
    return false;
}

fract fract::neg() const
{
    return fract(-numerator, denominator);
}

void fract::add(const fract &right)
{
    unsigned int commonDenom = lcm(denominator, right.denom());

    int leftNumerator = commonDenom / denominator;
    int rightNumerator = commonDenom / right.denom();

    numerator = leftNumerator + rightNumerator;
    denominator = commonDenom;
}

void fract::reduceFraction()
{
    // skracanie ułamka ?
    unsigned int divisor = gcd(numerator, denominator);
    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

/* TODO:
-equals
-neg
-add
-sum
-mul <- multiply
-prod <- zwraca ułamek, bierze ułamek

dodatkowo:
- skroc ulamek

*/

unsigned int lcm(unsigned int a, unsigned int b)
{
    // least common multiple
    return (a * b) / gcd(a, b);
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    // greatest common divisor
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return std::max(a, b);
}
