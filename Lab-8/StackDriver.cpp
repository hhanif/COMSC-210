// Lab 8A, Stack Driver
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
using namespace std;

#include "Stack.h"
#include "Stack.h" // testing ifndef


int main()
{
    // print my name and this assignment's title
    cout << "Lab 8A, Stack Driver \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    float tFloat;
    

    Stack<float> s;
    

    cout << "1  Testing s.empty() (expect \"1\"):  ";
    cout << s.empty();
    cout << endl;
    

    cout << "2  Testing s.size() (expect \"0\"):   ";
    cout << s.size();
    cout << endl;
    

    cout << "3  Testing s.push(1.5) ";
    cout << endl ;;
    s.push(1.5);
    

    cout << "4  Testing s.top() (expect \"1.5\"):  ";
    cout<< s.top();
    cout << endl;

    cout << "5  Testing s.top() again (expect \"1.5\"):  ";
    cout << s.top();
    cout << endl;
    

    cout << "6  Testing s.size() (expect \"1\"):   " ;
    cout << s.size();
    cout << endl;
    

    cout << "7  Testing s.empty() (expect \"0\"):  ";
    cout << s.empty();
    cout << endl;
    

    cout << "8  Testing s.pop() (expect \"1\"):    ";
    cout << s.pop();
    cout << endl;
    

    cout << "9  Testing s.size() (expect \"0\"):   ";
    cout << s.size();
    cout << endl;
    

    cout << "10 Testing s.pop() (expect \"0\"):    ";
    cout << s.pop();
    cout << endl;
    

    cout << "11 Pushing 1.1, "; s.push(1.1);
    cout << "2.2, "; s.push(2.2);
    cout << "3.3, "; s.push(3.3);
    cout << "4.4, "; s.push(4.4);
    cout << "5.5, "; s.push(5.5);
    

    cout << "12 Testing s.size() (expect \"5\"):   ";
    cout << s.size();
    cout << endl;
    

    cout << "13 Testing s.empty() (expect \"0\"):  ";
    cout << s.empty();
    cout << endl;


    cout << "14 Testing s.top() (expect \"5.5\"):  ";
    cout << s.top();
    cout << endl;
    

    cout << "15 Testing s.pop() (expect \"1\"):    ";
    cout << s.pop();
    cout << endl;
    

    cout << "16 Testing s.top() (expect \"4.4\"):  ";
    cout << s.top();
    cout << endl;
    

    cout << "17 Testing s.pop(var) (\"4.4\"):      ";
    s.pop(tFloat);
    cout << tFloat << endl;
    

    cout << "18 Testing s.top() (expect \"3.3\"):  ";
    cout << s.top();
    cout << endl;
    

    cout << "19 Testing s.top(var) (expect \"1\" and \"3.3\"): ";
    cout << s.top(tFloat) << ", ";
    cout << tFloat << endl;
    

    cout << "20 Testing s.size() (expect \"3\"):   ";
    cout << s.size();
    cout << endl;
    

    cout << "21 Testing s.makeEmpty()";
    s.makeEmpty();
    cout << endl << endl;
    

    cout << "22 Testing s.empty() (expect \"1\"):  ";
    cout << s.empty();
    cout << endl;
    

    cout << "23 Testing s.size() (expect \"0\"):   ";
    cout << s.size();
    cout << endl;
    

    cout << "  Now repopulating the stack with \"1.1\" - \"9.9\" for copy testing" << endl;
    s.push(1.1);
    s.push(2.2);
    s.push(3.3);
    s.push(4.4);
    s.push(5.5);
    s.push(6.6);
    s.push(7.7);
    s.push(8.8);
    s.push(9.9);
    cout << "  Testing s.top() (expect \"9.9\"):  ";
    cout << s.top();
    cout << endl;
    cout << "  Testing s.size() (expect \"9\"):   ";
    cout << s.size();
    cout << endl;

    
    // Copy test object with assignment upon declaration:
    {

        cout << "Copying object with assignment upon declaration" << endl;
        Stack<float> copy = s;
        
        cout << "Testing .size() and .top() (expect \"9\" and \"9.9\"): ";
        cout << copy.size() << ", ";
        cout << copy.top();
        cout << endl;
    }
    
    // object copy testing, with assignment after declaration
    {

        
        cout << "Copying object with assignment after declaration..." << endl;
        Stack<float> copy; copy = s;
        
        cout << "Testing .size() and .top() (expect \"9\" and \"9.9\"): ";
        cout << copy.size() << ", ";
        cout << copy.top();
        cout << endl;
    }
    
    // CONST object copy testing, with assignment upon declaration
    {

        cout << "Copying CONST object with assignment upon declaration..." << endl;
        const Stack<float> copy = s;
        
        cout << "Testing .size() and .top() (expect \"9\" and \"9.9\"): ";
        cout << copy.size() << ", ";
        cout << copy.top();
        cout << endl;
        
    }
    
} // end main
