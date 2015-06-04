// Lab 9C, Big Oh
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main()
{
    // print my name and this assignment's title
    cout << "Lab 9B, Big Oh \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    int n = 750000;
    int randMax = 1000;
    
    srand (time(0));
    double prime = (rand() % randMax + 1);
    

    string bigOh = "O(n log n)";
    
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    
    

    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
        double* randArray = new double[n];
        

        for (int i = 0; i < n; i++)
            randArray[i] = (rand() % randMax);
        

        assert( (bool)(randArray[n-1]) );
        assert( !(bool)(randArray[n+2]) );
        

        clock_t startTime = clock();
        

        sort(randArray, randArray+n);
        

        clock_t endTime = clock();
        

        for (int i = 1; i < n; i++)
            assert(randArray[i - 1] <= randArray[i]);
        

        
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
        {
            cout << " (expected ";
            cout << bigOh;
            cout << ')';
        }
        else
        {
            cout << " (expected ";
            cout << expectedTimeTicks;
            cout << ')';
        }
        cout << " for n=";
        cout << n << endl;
        
        delete [] randArray;

    }
}
