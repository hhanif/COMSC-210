// Lab 10A, Linked List
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#define NODE
#include "LinkedList.h"
#include "LinkedList.h" // testing ifndef


int main(int argc, const char * argv[]) {
    // print my name and this assignment's title
    cout << "Lab 10A, Linked List \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    LinkedList<int>test;
    

    cout<<"Now Testing size()"<<endl;
    cout<<"expected: 0" << endl;
    cout << "Actual: ";
    cout <<test.size()<<endl;
    assert(test.size()==0);
    

    for(int i=0;i < 4;i++)
    {
        test[i]=i;
    }
    

    cout<<"Testing size() again"<<endl;
    cout<<"expected: 4" << endl;
    cout << "Actual: ";
    cout <<test.size()<<endl;
    assert(test.size()==4);
    
    cout<<"Now testing lsearch()"<<endl;
    cout<<"expected: 2 " << endl;
    cout << "Actual: ";
    cout <<test.lsearch(2)<<endl;
    assert(test.lsearch(2)==2);
    
    cout<<"Testing lsearch() again"<<endl;
    cout<<"expected: -1" << endl;
    cout << "Actual: ";
    cout <<test.lsearch(4)<<endl;
    assert(test.lsearch(4)==-1);
    
    
    cout<<"Now Testing containsKey()"<<endl;
    cout<<"expected: 1" << endl;
    cout << "Actual: ";
    cout <<test.containsKey(2)<<endl;
    assert(test.containsKey(2)==true);


    {
        const LinkedList<int>copy =test;
        cout<<"Now Testing CONST copy assignmet upon declaration"<<endl;
        cout<<"expected: 0 1 2 3" << endl;
        cout <<"Actual: ";
        for(int i=0;i<copy.size();i++)
            cout<<copy[i]<<" ";
        
        cout << endl;
        cout<<"Now testing size()"<<endl;
        cout<<"Expected: 4" << endl;
        cout << "Actual: ";
        cout << copy.size()<<endl;
        assert(copy.size()==4);
    }
    

    {
        LinkedList<int>copy;copy=test;
        cout<<"Now Testing copy assignment after declaration:"<<endl;
        cout<<"expected: 0 1 2 3" << endl;
        cout << "Actual: ";
        for(int i=0;i<copy.size();i++)
            cout<<copy[i]<<" ";
        
        cout << endl;
        cout<<"Now testing size()"<<endl;
        cout<<"expected: 4" << endl;
        cout << "Actual: ";
        cout <<copy.size()<<endl;
        assert(copy.size()==4);
    }
    
    cout<<"Now testing clear()"<<endl;
    test.clear();
    cout<<"Expected: 0" << endl;
    cout << "Actual: ";
    cout <<test.size()<<endl;
    
    
    cout<<"Now testing deleteKey()"<<endl;
    test.deleteKey(3);
    cout<<"Expected: 0" << endl;
    cout << "Actual: ";
    cout <<test.containsKey(3)<<endl;
    assert(test.containsKey(3)==0);
    
    
    
    cout<<"Now Testing inUse"<<endl;
    cout<<"expected: 0 0 0 0" << endl;
    cout << "Actual: ";
    for(int i=0;i<4;i++)
    {
        cout<<test.containsKey(i);
        cout <<" ";
        assert(test.containsKey(i)==0);
    }
    

}
