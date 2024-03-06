#include "fract.h"

fract::fract(int num, unsigned int denom)
    : numerator(num), denominator(denom)
{
    reduceFraction();
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
    return numerator == right.num() && denominator == right.denom();
}

fract fract::neg() const
{
    return fract(-numerator, denominator);
}

void fract::add(const fract &right)
{
    unsigned int commonDenom = lcm(denominator, right.denom());

    int leftNumerator = (commonDenom / denominator) * numerator;
    int rightNumerator = (commonDenom / right.denom()) * right.num();

    numerator = leftNumerator + rightNumerator;
    denominator = commonDenom;

    reduceFraction();
}

fract fract::sum(const fract &right) const
{
    // use add function
    fract result(numerator, denominator);
    result.add(right);
    return result;
}

void fract::mul(const fract &right)
{
    // mltiplication of two fractions
    numerator *= right.num();
    denominator *= right.denom();

    reduceFraction();
}

fract fract::prod(const fract &right) const
{
    fract result(numerator, denominator);
    result.mul(right);
    return result;
}

void fract::reduceFraction()
{
    // skracanie ułamka ?
    // cannot be unsigned, because numerator is an int - we get wrong result
    // casting it to int would do the trick
    int divisor = gcd(abs(numerator), denominator);

    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

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
