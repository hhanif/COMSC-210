// Lab 1A, Class Programming And Testing
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>

#include <iomanip>
using namespace std;

#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef


int main()
{
    // print my name and this assignment's title
    cout << "Lab 1A, Class Programming And Testing \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //test all getters and setters
    
    Road Road;
    int Length = 10;
    int Width = 20;
    
    cout << "The value of length should be set at 10 miles" << endl;
    Road.setLength(Length);
    assert(10 == Road.getLength());
    
    cout << "The Value of width should be set at 20 feet" << endl;
    Road.setWidth(Width);
    assert(20 == Road.getWidth());
    
    cout << "The value of thickness is set to 12. ";
    cout << endl;
    cout << "The expected value of feet cubed needed is: 1,056,000";
    cout << endl;
    
    int thickness=12;
    
    assert(1056000 == Road.Asphalt(thickness));
    
    cout << "The actual value of length is: ";
    cout <<  Road.getLength();
    cout << endl;
    
    cout << "The actual value of width is: ";
    cout << Road.getWidth();
    cout << endl;
    
    cout << "The actual value of the total cubic feet needed is: ";
    cout << Road.Asphalt(thickness);
    cout << endl;
    
    
    // object copy testing
    {
        class Road copy = Road;
        cout << "The Road object is now  copied through object copy testing. ";
        cout << "We are now going to use the getters to check to see if they are the same values."<<endl;
        cout << "The expected values are:";
        cout << endl;
        cout << "length: 10";
        cout << endl;
        cout << "Width: 20";
        cout << endl;
        cout << "Thickness: 1,056,000.";
        cout << endl;
        
        cout << "The Actual value of the Length is: ";
        cout << copy.getLength();
        cout << endl;
        cout << "The Actual value of the Width is: ";
        cout << copy.getWidth();
        cout << endl;
        cout << " The Actual value of the Thickness is: ";
        cout << copy.Asphalt(thickness);
        cout << endl;
        
        assert(10 == copy.getLength());
        assert(20 == copy.getWidth());
        assert(1056000 == copy.Asphalt(thickness));
    }
    // object assignment testing
    {
        class Road copy; copy = Road;
        cout << "The Road object is now copied through object assignment testing.";
        cout << "We are going to use getters to check to see if they are the same values." << endl;
        cout << "The expected values are:";
        cout << endl;
        cout << "length: 10";
        cout << endl;
        cout << "Width: 20";
        cout << endl;
        cout << "Thickness: 1,056,000.";
        cout << endl;
        cout << "The Actual value of the Length is: ";
        cout << copy.getLength();
        cout << endl;
        cout << "The Actual value of the Width is: ";
        cout << copy.getWidth();
        cout << endl;
        cout << " The Actual value of the Thickness is: ";
        cout << copy.Asphalt(thickness);
        cout << endl;
        
        assert(10 == copy.getLength());
        assert(20 == copy.getWidth());
        assert(1056000 == copy.Asphalt(thickness));
    }
}
