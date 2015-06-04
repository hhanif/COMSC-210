// Lab 2a, Fractions Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode
#include "Fraction.h"

// member function definitions
Fraction operator+(Fraction x, Fraction y)
{
    Fraction result;
    //checks to see if denominator is the same
    if(y.denom == x.denom)
        result.denom = x.denom;
    else
        result.denom = x.denom * y.denom;
    
    int temp_change = result.denom / x.denom;
    int temp_xnumer = temp_change * x.numer;
    
    temp_change = result.denom / y.denom;
    int temp_ynumer = temp_change * y.numer;
    
    
    result.numer = temp_xnumer + temp_ynumer;
    
    return result;
}

Fraction operator*(Fraction x, Fraction y)
{
    Fraction result;
    
    result.numer = x.numer * y.numer;
    result.denom = x.denom * y.denom;
    
    return result;
}

bool operator>(Fraction x, Fraction y)
{
    double temp_xtotal = (double)x.numer / (double)x.denom;
    double temp_ytotal = (double)y.numer / (double)y.denom;
    
    if(temp_xtotal > temp_ytotal)
        return true;
    else
        return false;
}
Fraction operator*(Fraction x, int y)
{
    Fraction result;
    
    result.numer = x.numer * y;
    result.denom = x.denom;
    
    return result;
}

Fraction operator*(int y, Fraction x)
{
    Fraction result;
    result.numer = y * x.numer;
    result.denom = x.denom;
    
    return result;
}
