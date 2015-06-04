// Lab 12B, Priority Queue Big Oh
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode
#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include <cmath>
#include <ctime>

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
    // print my name and this assignment's title
    cout << "Lab 12B, Priority Queue Big Oh \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

    int n = 4000;
    string bigOh = "O(log n)";
    const int REPS = 1000;
    
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    cout<<"Enqueue, O(log n):"<<endl;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {

        PriorityQueue<int> pq(n);
        for(int i = 0; i < n; i++)
        {
            pq.enqueue(n - 1);
        }
        assert(pq.getSize() == n);
        clock_t startTime = clock();
        int x;
        for(x = 0; x< REPS;x++)
        {
            pq.enqueue(x);
        }

        clock_t endTime = clock();
        assert(pq.getSize() == (n + x));
        


        long elapsedTimeTicks = (long)(endTime - startTime);
        double factor = pow(2.0, cycle);
        if (cycle == 0)
            elapsedTimeTicksNorm = elapsedTimeTicks;
        else if (bigOh == "O(1)")
            expectedTimeTicks = elapsedTimeTicksNorm;
        else if (bigOh == "O(log n)")
            expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
        else if (bigOh == "O(n)")
            expectedTimeTicks = factor * elapsedTimeTicksNorm;
        else if (bigOh == "O(n log n)")
            expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
        else if (bigOh == "O(n squared)")
            expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
        

        cout << elapsedTimeTicks;;
        if (cycle == 0)
            cout << " (expected " << bigOh << ')';
        else
            cout << " (expected " << expectedTimeTicks << ')';
        cout << " for n = ";
        cout << n << endl;
    }
    cout<<"Dequeue, O(log n):"<<endl;
    
    bigOh = "O(log n)";
    n = 500000;
    const int Reps_Change = 5000;
    
    elapsedTimeTicksNorm = 0;
    expectedTimeTicks = 0;
    
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {

        PriorityQueue<int> pq(n);
        for(int i = 0; i < n;i++) {
            pq.enqueue(n - 1);
        }
        assert(pq.getSize() == n);
        clock_t startTime = clock();

        
        for(int a = 0; a < Reps_Change; a++)
        {
            pq.dequeue();
        }
        
        clock_t endTime = clock();
        assert(pq.getSize() == (n - Reps_Change));
        
        for(int a = 0; a < Reps_Change; a++)
        {
            int bigOh = pq.dequeue();
        }

        long elapsedTimeTicks = (long)(endTime - startTime);
        double factor = pow(2.0, cycle);
        if (cycle == 0)
            elapsedTimeTicksNorm = elapsedTimeTicks;
        else if (bigOh == "O(1)")
            expectedTimeTicks = elapsedTimeTicksNorm;
        else if (bigOh == "O(log n)")
            expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
        else if (bigOh == "O(n)")
            expectedTimeTicks = factor * elapsedTimeTicksNorm;
        else if (bigOh == "O(n log n)")
            expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
        else if (bigOh == "O(n squared)")
            expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
        

        cout << elapsedTimeTicks;;
        if (cycle == 0)
            cout << " (expected " << bigOh << ')';
        else
            cout << " (expected " << expectedTimeTicks << ')';
        cout << " for n = ";
        cout << n << endl;
    } 
    
    
}
