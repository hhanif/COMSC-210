// Lab 8A, Calculator Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

#include "Stack.h"


int main()
{
    // print my name and this assignment's title
    cout << "Lab 8A, Calculator Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    float op1;
    float op2;
    float op3;
    string in="0.00000";
    string error = "Error: Not enought data";
    Stack<float> s;
    

    cout << "Enter numbers or operators 1 at a time, or Q to Quit" << endl;
    
    while (in!="Q")
    {

        cout << "Enter:  ";
        for (Stack<float> copy = s; !copy.empty(); copy.pop())
        {
            cout << copy.top() << "  ";
        }
        getline(cin, in);
        

        if (in == "Q" || in == "q") break;
        
        if (in == "+")
        {
            if (s.size() < 2) cout << error;
            else
            {
                s.top(op1); s.pop();
                s.top(op2); s.pop();
                op3 = op2 + op1;
                s.push(op3);
            }
        }
        
        else if (in == "-")
        {
            if (s.size() < 2) cout << error;
            else
            {
                s.top(op1); s.pop();
                s.top(op2); s.pop();
                op3 = op2 - op1;
                s.push(op3);
            }
        }
        
        else if (in == "*")
        {
            if (s.size() < 2) cout << error;
            else
            {
                s.top(op1); s.pop();
                s.top(op2); s.pop();
                op3 = op2 * op1;
                s.push(op3);
            }
        }
        
        else if (in == "/")
        {
            if (s.size() < 2) cout << error;
            else
            {
                s.top(op1); s.pop();
                s.top(op2); s.pop();
                op3 = op2 / op1;
                s.push(op3);
            }
        }
        
        else s.push((atof(in.c_str())));
    }
    

}
