// Lab 3B, Time
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>

#include <iomanip>
using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h" // testing ifndef


int main()
{
    // print my name and this assignment's title
    cout << "Lab 3B, Time \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //test all getters and setters
    Time Test;

    cout<<"Now testing the default constructor"<<endl;
    cout<<"Every value should be initialized to zero. "<<endl;
    assert(Test.InHours()==0 && Test.InMinutes()==0 && Test.InSeconds()==0);
    cout<<"All assertions have passed."<<endl;
    Time time(2,80,60);

    double hours = 1.0;
    double minutes = 40.0;
    double seconds = 30.0;
    assert(time.InSeconds()==12060);

    
    cout << "The value of hours should be set at 1 hour" << endl;
    time.setHours(hours);
    
    cout << "The value of minutes should be set at 40 minutes" << endl;
    time.setMinutes(minutes);
    
    cout << "The value of seconds should be set at 30 seconds" << endl;
    time.setSeconds(seconds);

    cout << "The expected value of Time in Seconds is: 6030 \n Time in Minutes is: 100.5 \n Time in Hours: 1.675";
    cout << endl;

    
    cout << "The actual value of Time in Seconds is: ";
    cout <<  time.InSeconds();
    cout << endl;
    assert(6030.0 == time.InSeconds());

    
    cout << "The actual value of Time in Minutes is: ";
    cout <<  time.InMinutes();
    cout << endl;
    assert(100.5 == time.InMinutes());

    
    cout << "The actual value of Time in Hours is: ";
    cout <<  time.InHours();
    cout << endl;
    assert(1.674 < time.InHours() && time.InHours() < 1.676);


    // object copy testing
    {
        const Time copy = time;
        cout << "The Time object is now copied through object copy testing. ";
        cout << "We are now going to see if they are the same values."<<endl;
        
        
        cout << "The copied value of Time in Seconds is: ";
        cout <<  copy.InSeconds();
        cout << endl;
        
        cout << "The copied value of Time in Minutes is: ";
        cout <<  copy.InMinutes();
        cout << endl;
        
        cout << "copy copie value of Time in Hours is: ";
        cout <<  copy.InHours();
        cout << endl;
    }

    // object assignment testing
    {
        Time copy(10, 4, 6); copy = time;
        cout << "The Time object is now copied through object assignment testing.";
        cout << "We are going to see if they are the same values." << endl;
        
        
        cout << "The copied value of Time in Seconds is: ";
        cout <<  copy.InSeconds();
        cout << endl;
        
        cout << "The copied value of Time in Minutes is: ";
        cout <<  copy.InMinutes();
        cout << endl;
        
        cout << "The copied value of Time in Hours is: ";
        cout <<  copy.InHours();
        cout << endl;
    }

}
