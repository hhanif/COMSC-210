// Lab 3A, Const's
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Road_h
#define Road_h

class Road
{
public:
    Road(int w, int l);
    
    //set functions
    void setWidth(int);
    void setLength(int);
    
    //get functions (normally declared const)
    int getWidth() const; //return width
    int getLength() const; //return length
    int Asphalt(int) const;
private:
    int Width;
    int Length;

    };

#endif
