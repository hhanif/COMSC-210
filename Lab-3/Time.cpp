// Lab 3B, Time
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "Time.h"

Time::Time()
{
   	hours = 0;
    minutes = 0;
    seconds = 0;
}
Time::Time(double h, double m, double s)
{
    hours =  h;
    minutes =  m;
    seconds =  s;
}

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
double Time::InHours() const
{
    return hours + (minutes / 60) + (seconds / 3600);
}

double Time::InMinutes() const
{
    return (hours * 60) + minutes + (seconds / 60);
}

double Time::InSeconds() const
{
    return (hours * 3600) + (minutes * 60) + seconds;
}
