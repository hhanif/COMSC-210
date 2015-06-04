// Lab 8B, Queue Driver
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <string>
using namespace std;

#define NODE
#include "Queue.h"
#include "Queue.h" // testing ifndef


int main()
{
    cout << "Lab 8B, Queue Driver \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    string tString;
    string str1 = "Beginning", str2 = "Second", str3 = "Third", str4 = "Fourth", str5 = "End";
    string strFirst = "First";
    string strLast = "Last";
    

    Queue<string> q;
    
    cout << "Created Queue<string> object \"q\"..." << endl;
    

    
    cout << "1  Testing q.empty() (expect \"1\"):  ";
    cout << q.empty();
    cout << endl;
    

    cout << "2  Testing q.size() (expect \"0\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "3  Testing q.push(Beginning)";
    cout << endl;
    q.push(str1);
    

    cout << "4  Testing q.peek() (expect \"Beginning\"):  ";
    cout << q.peek();
    cout << endl;
    cout << "5  Testing q.peek(var) (expect \"Beginning\"): ";
    q.peek(tString);
    cout << tString << endl;
    

    cout << "6  Testing q.size() (expect \"1\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "7  Testing q.empty() (expect \"0\"):  ";
    cout << q.empty();
    cout << endl;
    

    cout << "8  Testing q.pop() (expect \"1\"):    ";
    cout << q.pop();
    cout << endl;
    

    cout << "9  Testing q.size() (expect \"0\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "10 Testing q.pop() (expect \"0\"):    ";
    cout << q.pop();
    cout << endl;
    

    cout << "11 Pushing \"Beginning\", "; q.push(str1);
    cout << "\"Second\", "; q.push(str2);
    cout << "\"Third\", "; q.push(str3);
    cout << "\"Fourth\", "; q.push(str4);
    cout << "\"End\", "; q.push(str5);

    

    cout << "12 Testing q.size() (expect \"5\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "13 Testing q.empty() (expect \"0\"):  ";
    cout << q.empty();
    cout << endl;
    

    cout << "14 Testing q.peek() (expect \"Beginning\"): ";
    cout << q.peek();
    cout << endl;
    

    cout << "15 Testing q.pop() (expect \"1\"):    ";
    cout << q.pop();
    cout<< endl;
    

    cout << "16 Testing q.peek() (expect \"Second\"):  ";
    cout<< q.peek();
    cout << endl;
    

    cout << "17 Testing q.pop(var) (\"Second\"): ";
    q.pop(tString);
    cout << tString;
    cout << endl;
    

    cout << "18 Testing q.peek() (expect \"Third\"): ";
    cout << q.peek();
    cout << endl;
    

    cout << "19 Testing q.peek(var) (expect \"1\" and \"Third\"): ";
    cout << q.peek(tString) << ", ";
    cout << tString;
    cout << endl;
    

    cout << "20 Testing q.size() (expect \"3\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "21 Testing q.makeEmpty()";
    q.makeEmpty();
    cout << endl;
    

    cout << "22 Testing q.empty() (expect \"1\"):  ";
    cout << q.empty();
    cout << endl;
    

    cout << "23 Testing q.size() (expect \"0\"):   ";
    cout << q.size();
    cout << endl;
    

    cout << "Now repopulating the queue with \"First\" - \"Last\" (7 numbers) for copy testing..." << endl;
    q.push(strFirst);
    q.push(str2);
    q.push(str3);
    q.push(str4);
    q.push((string)"Fifth");
    q.push((string)"Sixth");
    q.push(strLast);
    cout << "  Testing q.peek() (expect \"First\"):  ";
    cout << q.peek();
    cout << endl;
    cout << "  Testing q.size() (expect \"7\"):      ";
    cout << q.size();
    cout << endl;

    
    // Copy test object with assignment upon declaration:
    {

        cout << "  Copying object with assignment upon declaration..." << endl;
        Queue<string> copy = q;
        
        cout << "  Testing .size() and .peek() (expect \"7\" and \"First\"): ";
        cout << copy.size() << ", ";
        cout << copy.peek();
        cout << endl;
    }
    
    // object copy testing, with assignment after declaration
    {

        cout << "  Copying object with assignment after declaration..." << endl;
        Queue<string> copy; copy = q;
        
        cout << "  Testing .size() and .peek() (expect \"7\" and \"First\"): ";
        cout << copy.size() << ", ";
        cout << copy.peek();
        cout << endl;
    }
    
    // CONST object copy testing, with assignment upon declaration
    {

        cout << "  Copying CONST object with assignment upon declaration..." << endl;
        const Queue<string> copy = q;
        
        cout << "  Testing .size() and .peek() (expect \"7\" and \"First\"): ";
        cout << copy.size() << ", ";
        cout << copy.peek();
        cout << endl << endl;
        
    }
    

    cout << endl << endl << "Finally: popping all the way through the stack:" << endl;
    int listSize = q.size();
    
    for (int i = 0; i < listSize; i++)
    {
        cout << "  " << q.peek() << endl;
        q.pop();
    }
    

} // end main
