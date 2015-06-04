// Lab 2a, Fractions Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode
#include "Fraction.h"
#include "Fraction.h" // testing ifndef
#include <iostream>
#include <cassert>

using namespace std;
int main()
{
    // print my name and this assignment's title
    cout << "Lab 2a, Factions Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    Fraction x = {1,2};
    Fraction y = {1,4};
    
    cout<<"In this test, \nFraction X will be: 1/2 \n and Fraction Y will be: 1/4"<<endl;
    
    Fraction a = x + y;
    Fraction b = x * y;
    Fraction c = 2 * x;
    Fraction d = x * 2;
    
    cout<<"Adding fractions x and y"<<endl;
    cout<<"Expected result: (1/2) + (1/4) =  6/8"<<endl;
    cout<<"Actual result:"<<endl;
    cout << a.numer;
    cout<<"/";
    cout<<a.denom;
    cout<<endl;
    assert(a.numer==6 && a.denom==8);
    
    cout<<"Multiplying Fractions X and Y"<<endl;
    cout<<"Expected result: (1/2) * (1/4) =  1/8"<<endl;
    cout<<"Actual result:"<<endl;
    assert(b.numer==1 && b.denom==8);
    cout << b.numer;
    cout<<"/";
    cout<<b.denom;
    cout<<endl;
    
    cout<<"Multiping X by 2"<<endl;
    cout<<"Expected result: (1/2) * (2) =  2/2"<<endl;
    cout<<"Actual result:"<<endl;
    assert(c.numer==2 && c.denom==2);
    cout << c.numer;
    cout<<"/";
    cout<<c.denom;
    cout<<endl;
    
    cout<<"Multiplying 2 by X"<<endl;
    cout<<"Expected result: (2) * (1/2) =  2/2"<<endl;
    cout<<"Actual result:"<<endl;
    cout << d.numer;
    cout<<"/";
    cout<<d.denom;
    cout<<endl;
    assert(d.numer==2 && d.denom==2);
    
    cout<<"Now comparing the X and the Y fraction."<<endl;
    cout<<"Expected result: X fraction (1/2) will be larger than the Y fraction (1/4)"<<endl;
    cout<<"Actual result:"<<endl;
    assert(x > y == true);
    
    if(x > y)
        cout <<"The X fraction is larger than the Y fraction"<<endl;
    else
        cout<<"The Y fraction is larger than the X fraction"<<endl;
    //object copy testing
    {
        Fraction xcopy=x;
        Fraction ycopy=y;
        cout << "The fraction object is now copied through object copy testing. ";
        cout<<"Testing xcopy expect : 1/2 ,actual: "<<xcopy.numer<<'/'<<xcopy.denom<<endl;
        cout<<"Testing ycopy expect : 1/4 ,actual: "<<ycopy.numer<<'/'<<ycopy.denom<<endl;
        assert(xcopy.numer ==1 && xcopy.denom == 2);
        assert(ycopy.numer ==1 && ycopy.denom == 4);
    }
    
    {
        Fraction xcopy;
        xcopy=x;
        Fraction ycopy;
        ycopy=y;
        cout << "The fraction object is now copied through object assignment testing.";
        cout<<"Testing xcopy expect : 1/2 ,actual: "<<xcopy.numer<<'/'<<xcopy.denom<<endl;
        cout<<"Testing ycopy expect : 1/4 ,actual: "<<ycopy.numer<<'/'<<ycopy.denom<<endl;
        assert(xcopy.numer ==1 && xcopy.denom == 2);
        assert(ycopy.numer ==1 && ycopy.denom == 4);
    }
    
}
