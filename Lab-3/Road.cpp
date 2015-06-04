// Lab 3A, Const's
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "Road.h"

Road::Road(int w, int l)
{
    Width = w;
    Length = l;
}


void Road::setWidth(int w)
{
    Width = w;
}
void Road::setLength(int l)
{
    Length = l;
}
int Road::getWidth() const
{
    return Width;
}

int Road::getLength() const
{
    return Length;
}
int Road::Asphalt(int thickness) const
{
    return 5280 * Length * Width * thickness/12;
}

