// Lab 3A, Const's
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
    cout << "Lab 3A, Class Programming And Testing with consts \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //test all getters and setters
    cout<<"We create a road with a value of 150 for width and 200 for length."<<endl;
    Road road(150, 200);
    assert(road.getLength() == 200 && road.getWidth()==150);
    int Length = 10;
    int Width = 20;
    
    cout << "The value of length should be set at 10 miles" << endl;
    road.setLength(Length);
    assert(10 == road.getLength());
    
    cout << "The Value of width should be set at 20 feet" << endl;
    road.setWidth(Width);
    assert(20 == road.getWidth());
    
    cout << "The value of thickness is set to 12. ";
    cout << endl;
    cout << "The expected value of feet cubed needed is: 1,056,000";
    cout << endl;
    
    int thickness = 12;
    
    assert(1056000 == road.Asphalt(thickness));
    
    cout << "The actual value of length is: ";
    cout <<  road.getLength();
    cout << endl;
    
    cout << "The actual value of width is: ";
    cout << road.getWidth();
    cout << endl;
    
    cout << "The actual value of the total cubic feet needed is: ";
    cout << road.Asphalt(thickness);
    cout << endl;
    
    
    // object copy testing
    {
        const class Road copy = road;
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
        class Road copy(10,10); copy = road;
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
