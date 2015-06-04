// Lab 10B, Linked List
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include<iostream>
#include<string>
using namespace std;

#include<cstdlib>

#include "LinkedList.h"

int main()
{
    // print my name and this assignment's title
    cout << "Lab 10B, Linked List \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    int number;
    
    int i = 0;
    string buffer;
    LinkedList<int> testArray;
    
    while (true)
    {
        cout << "Enter ";
        cout << i+1;
        cout << " number";
        cout << " or enter 'q' or  'Q' to exit: ";
        cin >> buffer;

        if (buffer =="Q"||buffer=="q")
        {
            cout<<"Data Structure size: ";
            cout <<testArray.size()<<endl;
            break;
        }
        else
        {
            number = atof (buffer.c_str());
            cin.ignore (1000,10);
            testArray[i] = number;
        }

        cout << "Here is the list of entered values: " << endl;
        for (int x = 0; x <= i; x++)
        {
            cout << testArray[x] << ' ';
        }
        i++;
        cout << endl;
    }

    cout << "Now Implementing Linear Search"<<endl;
    cout << "Enter a number to search";
    cout << " Or enter  'q' or 'Q' to exit:";
    
    while (true)
    {
        cin >> buffer;
        if (buffer == "Q" || buffer == "q")
            break;
        else
        {
            number = atof (buffer.c_str());
            cin.ignore (1000,10);
            cout << "Number: ";
            cout << number;
            cout <<" in the array, ";
            cout << "Location is:";
            cout << testArray.lsearch(number);
            cout <<" element" << endl;
            cout << "Enter a number to search";
            cout << "Or enter  'q' or 'Q' to exit:";
        }
    }
}
