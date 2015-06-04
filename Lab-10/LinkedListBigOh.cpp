// Lab 10C, Linked List
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include <cmath>
#include <ctime>
#include "LinkedList.h"

int main()
{
    // print my name and this assignment's title
    cout << "Lab 10C, Linked List \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    {
        cout<<"operator[] assignment at zeroth index, O(1)"<<endl;

        int n = 2000;
        string bigOh = "O(1)";
        const int sets = 100000000;
        
        int elapsedTimeTicksNorm = 0;
        double expectedTimeTicks = 0;
        
        for (int cycle = 0; cycle < 4; cycle++, n*= 2)
        {

            srand(time(0));
            
            LinkedList<double>test;
            for(int i=0;i<n;i++)
                test[i]= rand()%2000;
            
            assert(test.size() == n);
            

            clock_t startTime = clock();

            for(int j=0;j<sets;j++)
            {
                test[0]=2.0;
            }
            clock_t endTime = clock();
            

            assert(test[0]==2.0);
            

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
    
    {
        cout<<"operator[] assignment at 100th index, O(1)"<<endl;

        int n = 2000;
        string bigOh = "O(1)";
        const int sets = 100000000;
        
        int elapsedTimeTicksNorm = 0;
        double expectedTimeTicks = 0;
        for (int cycle = 0; cycle < 4; cycle++, n*= 2)
        {

            srand(time(0));
            LinkedList<double>test;
            for(int i=0;i<n;i++)
                test[i]= rand()%2000;
            

            assert(test.size() == n);
            

            clock_t startTime = clock();

            for(int j=0;j<sets;j++)
            {
                test[100]=2.0;
            }
            clock_t endTime = clock();
            

            assert(test[100]==2.0);
            

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
    
    {
        cout<<"Iteration from the first to the last using operator[], O(n)"<<endl;

        int n = 500;
        string bigOh = "O(n)";
        const int sets = 10000;
        
        int elapsedTimeTicksNorm = 0;
        double expectedTimeTicks = 0;
        for (int cycle = 0; cycle < 4; cycle++, n*= 2)
        {

            srand(time(0));
            LinkedList<double>test;
            for(int i=0;i<n;i++)
                test[i]= rand()%2000;
            

            assert(test.size() == n);
            

            clock_t startTime = clock();

            for(int j=0;j<sets;j++)
                for(int k=0;k<test.size();test[k],k++);
            clock_t endTime = clock();
            

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
    
    {
        cout<<"size(), O(1)"<<endl;
        int n = 5000;
        string bigOh = "O(1)";
        const int sets = 100000000;
        
        int elapsedTimeTicksNorm = 0;
        double expectedTimeTicks = 0;
        for (int cycle = 0; cycle < 4; cycle++, n*= 2)
        {

            srand(time(0));
            LinkedList<double>test;
            for(int i=0;i<n;i++)
                test[i]= rand()%2000;
            

            assert(test.size() == n);
            

            clock_t startTime = clock();

            for(int j=0;j<sets;j++)
                test.size();
            clock_t endTime = clock(); 
            

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
}
