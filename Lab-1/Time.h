// Lab 1B, Time
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Time_h
#define Time_h

class Time
{
public:

    
    void setHours(double);
    void setMinutes(double);
    void setSeconds(double);
    double InHours();
    double InMinutes();
    double InSeconds();
    double getHours();
    double getMinutes();
    double getSeconds();

private:
    double hours;
    double minutes;
    double seconds;
    
};

#endif
