// Lab 3B, Time
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Time_h
#define Time_h

class Time
{
public:
    Time();
    Time(double h, double m, double s);
    
    
    void setHours(double);
    void setMinutes(double);
    void setSeconds(double);
    double InHours() const;
    double InMinutes() const;
    double InSeconds() const;

private:
    double hours;
    double minutes;
    double seconds;
    
};

#endif
