// Lab 1B, Time
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
    cout << "Lab 1B, Time \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    Time Time;
    double hours = 1.0;
    double minutes = 40.0;
    double seconds = 30.0;
    
    cout << "The value of hours should be set at 1 hour" << endl;
    Time.setHours(hours);
    
    cout << "The value of minutes should be set at 40 minutes" << endl;
    Time.setMinutes(minutes);
    
    cout << "The value of seconds should be set at 30 seconds" << endl;
    Time.setSeconds(seconds);

    cout << "The expected value of Time in Seconds is: 6030 \n Time in Minutes is: 100.5 \n Time in Hours: 1.675";
    cout << endl;

    
    cout << "The actual value of Time in Seconds is: ";
    cout <<  Time.InSeconds();
    cout << endl;
    assert(6030.0 == Time.InSeconds());

    
    cout << "The actual value of Time in Minutes is: ";
    cout <<  Time.InMinutes();
    cout << endl;
    assert(100.5 == Time.InMinutes());

    
    cout << "The actual value of Time in Hours is: ";
    cout <<  Time.InHours();
    cout << endl;
    assert(1.674 < Time.InHours() && Time.InHours() < 1.676);


    // object copy testing
    {
        class Time copy = Time;
        cout << "The Time object is now copied through object copy testing. ";
        cout << "We are now going to see if they are the same values."<<endl;
        cout << "The expected value of Time in Seconds is: 6030 \n Time in Minutes is: 100.5 \n Time in Hours: 1.675";
        cout << endl;
        
        
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
        class Time copy; copy = Time;
        cout << "The Time object is now copied through object assignment testing.";
        cout << "We are going to see if they are the same values." << endl;
        cout << "The expected value of Time in Seconds is: 6030 \n Time in Minutes is: 100.5 \n Time in Hours: 1.675";
        cout << endl;
        
        
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
