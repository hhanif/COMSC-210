// Lab 3c, Fractions Program
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

Fraction operator+(const Fraction&, const Fraction&);
Fraction operator*(const Fraction&, const Fraction&);
bool operator>(const Fraction&, const Fraction&);
Fraction operator*(const Fraction&, int);
Fraction operator*(int, const Fraction&);

#endif
