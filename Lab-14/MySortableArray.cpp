// Lab 14A, Sortable Array
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include<iostream>
#include<string>
using namespace std;
#include<cstdlib>
#include "SortableArray.h"

int main()
{

    // print my name and this assignment's title
    cout << "Lab 14A, Sortable Array \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    int num;
    int array_size=0;
    string buf;
    SortableArray<int,100> SA;
    cout << "Welcome to the SortableArray generator. You will now create an Array of integers." << endl;

    for (int i=0; i < SA.getCapacity(); i++)
    {
        cout << endl <<  "Please enter ";
        cout << i+1;
        cout << " number or enter 'q' or ' Q' to exit: " << endl;
        cin >> buf;

        if (buf =="Q"||buf=="q")
        {
            cout << endl <<"The output size of the array is: ";
            cout <<array_size;
            cout <<endl;
            break;
        }
        else
        {
            num = atof (buf.c_str());
            cin.ignore (1000,10);
            SA[i] = num;
        }

        cout << endl << "Here is the list of entered values: " << endl;
        for (int x = 0; x<=i; x++)
        {
            cout << SA[x] << ' ';
        }
        array_size++;

    }
    
    cout << "Now Enter an integer to search for using linear search in the SortableArray (or 'q' or 'Q' to stop): " << endl;
    
    while (true)
    {
        cin >> buf;

        if (buf == "Q" || buf == "q") {
            cout << "Exiting the Linear Search function!" << endl;
            break;
        }
        else
        {
            num = atof (buf.c_str());
            cin.ignore (1000,10);
            cout << endl << "number: ";
            cout <<num;
            cout <<" in array, location is in : ";
            cout << SA.lsearch(num);
            cout <<" element" << endl;
            cout << "Now enter another number to search or enter 'q' or ' Q' to exit: ";
        }
    }
    SA.sort(SA.getSize());
    cout << endl << "The sorted values of your array: "<<endl;
    for(int i = 0; i < SA.getSize(); i++)
        cout << SA[i] << ' ';
    
    cout << endl;
    

    cout << "Now Enter an integer to search for using the binary search in the SortableArray (or 'q' or 'Q' to stop): ";
    while (true)
    {
        cin >> buf;

        if (buf == "Q" || buf == "q") {
            cout << "Exiting the Binary Search function, Goodbye!" << endl;
            break;

        }
        else
        {
            num = atof (buf.c_str());
            cin.ignore (1000,10);
            cout << endl << "number ";
            cout <<num;
            cout <<" in array, location is in : ";
            cout << SA.bsearch(SA.getSize(),num);
            cout <<" element" << endl;
            cout << "Now enter another number to search or enter 'q' or ' Q' to exit: ";
        }
    }
    
}
