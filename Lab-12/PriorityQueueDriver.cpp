// Lab 12A, Priority Queue
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode
#include <iostream>
using namespace std;

#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h" //ifndef test

int main()
{
    // print my name and this assignment's title
    cout << "Lab 12A, Priority Queue \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    PriorityQueue<int> pq(101);
    // fill the PQ
    for(int i = 0; i < 100; ++i)
        pq.enqueue(i);
    
    
    cout << "Now testing empty" << endl;
    cout << "Expected: 0 (false)" << endl;
    cout << "Actual: ";
    cout << pq.empty() << endl;
    assert(pq.empty() == false);

    cout << "Now testing top" << endl;
    cout << "Expected: 99" << endl;
    cout << "Actual: ";
    cout << pq.top() << endl;
    assert(pq.top() == 99);

    pq.top();
    cout << "Now testing getSize()" << endl;
    cout << "Expected: 100" << endl;
    cout << "Actual: ";
    cout << pq.getSize() << endl;
    assert(pq.getSize() == 100);
    
    for(int i = 0; i < 80; ++i)
        pq.dequeue();
    
    int temp = pq.dequeue();
    cout << "Now testing dequeue" << endl;
    cout << "Expected: 20" << endl;
    cout << "Actual: ";
    cout << temp << endl;
    assert(temp == 20);
    
    cout << "Now testing getSize() again" << endl;
    cout << "Expected: 19" << endl;
    cout << "Actual: ";
    cout << pq.getSize() << endl;
    assert(pq.getSize() == 19);
    
    {
        const PriorityQueue<int> copy = pq;
        cout << "Object copy testing with assignment UPON declaration" << endl;
        cout << "Now testing size" << endl;
        cout << "Expected: 19" << endl;
        cout << "Actual: ";
        cout << pq.getSize() << endl;
        assert(copy.getSize() == 19);
        
        cout << "Now testing empty" << endl;
        cout << "Expected: 0 (false)" << endl;
        cout << "Actual: ";
        cout << pq.empty() << endl;
        assert(copy.empty() == false);
    }
    
    {
        PriorityQueue<int> copy(11); copy = pq;
        cout << "Object copy testing with assignment AFTER declaration" << endl;
        pq.clear();
        cout << "Now testing size" << endl;
        cout << "Expected: 0" << endl;
        cout << "Actual: ";
        cout << pq.getSize() << endl;
        assert(pq.getSize() == 0);
        
        cout << "Now testing empty" << endl;
        cout << "Expected: 1 (True)" << endl;
        cout << "Actual: ";
        cout << pq.empty() << endl;
        assert(pq.empty() == true);
    }
}
