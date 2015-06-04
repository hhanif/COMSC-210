// Lab 2a, Fractions Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
    int numer;
    int denom;
};

Fraction operator+(Fraction, Fraction);
Fraction operator*(Fraction, Fraction);
bool operator>(Fraction, Fraction);
Fraction operator*(Fraction, int);
Fraction operator*(int, Fraction);

#endif
