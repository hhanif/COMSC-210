// Lab 8C, Pre Processor
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include <cstdlib>
#include <cstring>

#include "Stack.h"
#include "Stack.h"
struct Brackets
{
    char front;
    char end;
    int loc;
};


int main()
{
    int currentline = 0;
    Stack<Brackets>operators(2);
    string filename;
    // print my name and this assignment's title
    cout << "Lab 8C, Stack Driver \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    cout<<"Please enter a file name: "<<endl;
    cin>>filename;
    
    
    
    // open the input file
    ifstream fin;
    fin.open(filename);
    if (!fin.good()) throw "I/O error";
    // read the input file
    char buf[1000];
    
    while (fin.good())
    {
        currentline++;
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;
        
        for (int i = 0; i < strlen(buf); i++)
        {
            if(buf[i] == '{')
            {
                Brackets b;
                b.front = '{';
                b.loc = currentline;
                operators.push(b);
            }
            if(buf[i] == '}')
            {
                if(operators.peek().front != '{')
                {
                    cout<<"Closing bracket can be found at ";
                    cout <<currentline;
                    cout << " of ";
                    cout <<filename;
                    cout <<endl;
                    cout <<" But no matching bracket was found.";
                    cout <<endl;
                    return 0;
                }
                else if(operators.peek().front == '{')
                    operators.pop();
            }
            if(buf[i] == '(')
            {
                Brackets b;
                b.front = '(';
                b.loc = currentline;
                operators.push(b);
            }
            if(buf[i] == ')')
            {
                if(operators.peek().front != '(')
                {
                    cout<<"Closing Parantheses can be found at ";
                    cout <<currentline;
                    cout << " of ";
                    cout <<filename;
                    cout << endl;
                    cout <<" But no matching bracket was found.";
                    cout <<endl;
                    return 0;
                }
                else if(operators.peek().front == '(')
                    operators.pop();
            }
            if(buf[i] == '[')
            {
                Brackets b;
                b.front = '[';
                b.loc = currentline;
                operators.push(b);
            }
            if(buf[i] == ']')
            {
                if(operators.peek().front != '[')
                {
                    cout<<"Square bracket can be found at ";
                    cout <<currentline;
                    cout << " of ";
                    cout <<filename;
                    cout << endl;
                    cout <<" But no matching bracket was found.";
                    cout <<endl;
                    return 0;
                }
                else if(operators.peek().front == '[')
                    operators.pop();
            }
            if(buf[i] == '/' && buf[i+1] == '*')
            {
                Brackets b;
                b.front = '/';
                b.end = '*';
                b.loc = currentline;
                operators.push(b);
            }
            if(buf[i] == '*' && buf[i+1] == '/')
            {
                if(operators.peek().end != '*' && operators.peek().front !='/')
                {
                    cout<<"Comment Offset can be found at ";
                    cout <<currentline;
                    cout << " of ";
                    cout <<filename;
                    cout << endl;
                    cout << "But no matching bracket was found.";
                    cout <<endl;
                    return 0;
                }
                else if(operators.peek().end == '*' && operators.peek().front == '/')
                    operators.pop();
            }
        }
    }
    if(operators.isEmpty())
    {
        cout << "No mismatches found by preprocessor in ";
        cout << filename;
        cout <<endl;
        return 0;
    }
    while(!operators.isEmpty())
    {
        if(operators.peek().front == '{')
        {
            cout<<"Opening Curly brace can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching closing brace was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == '}')
        {
            cout<<"Closing Curly brace can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching Opening brace was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == '(')
        {
            cout<<"Opening Parantheses can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching closing Parantheses was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == ')')
        {
            cout<<"Closing Parantheses can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching opening Parantheses was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == '[')
        {
            cout<<"Opening square bracket can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching closing bracket was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == ']')
        {
            cout<<"Closing square bracket can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching opening bracket was found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == '*' && operators.peek().end == '/')
        {
            cout<<"Closing comment offsets can be found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching comment offsets found.";
            cout <<endl;
            operators.pop();
        }
        if(operators.peek().front == '/' && operators.peek().end == '*')
        {
            cout<<"Opening comment offsets found at ";
            cout << operators.peek().loc;
            cout <<endl;
            cout << " But no matching closing comment offsets found.";
            cout <<endl;
            operators.pop();
        }
    }
    return 0;
}
