// Lab 1B, Time
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "Time.h"

void Time::setHours(double h)
{
    hours = h;
}

void Time::setMinutes(double m)
{
    minutes = m;
}
void Time::setSeconds(double s)
{
    seconds = s;
}
double Time::InHours()
{
    return hours + (minutes / 60) + (seconds / 3600);
}

double Time::InMinutes()
{
    return (hours * 60) + minutes + (seconds / 60);
}

double Time::InSeconds()
{
    return (hours * 3600) + (minutes * 60) + seconds;
}
