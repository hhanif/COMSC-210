// Lab 1A, Class Programming And Testing
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <stdio.h>
#include "Road.h"


void Road::setWidth(int w)
{
    Width = w;
}
void Road::setLength( int l)
{
    Length = l;
}
int Road::getWidth()
{
    return Width;
}

int Road::getLength()
{
    return Length;
}
int Road::Asphalt(int thickness)
{
    return 5280 * Length * Width * thickness/12;
}

