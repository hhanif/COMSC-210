// Lab 1A, Class Programming And Testing
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Road_h
#define Road_h

class Road
{
public:

    
    //set functions
    void setWidth(int);
    void setLength(int);
    
    //get functions (normally declared const)
    int getWidth(); //return width
    int getLength(); //return length
    int Asphalt(int);
private:
    int Width;
    int Length;

    };

#endif
