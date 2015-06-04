// Lab 9A, Big Oh
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>

int main()
{
    // print my name and this assignment's title
    cout << "Lab 9A, Big Oh \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    int lineCount = 0;
    int assertInt = 0;
    

    ifstream fin;
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    int nAssignment = 5000;
    int n = nAssignment;
    string bigOh = "O(n)";
    
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {

        assertInt = (pow(2, cycle) * nAssignment);
        assert(assertInt == n);
        

        fin.open("dvc-schedule.txt");
        if (!fin.good()) throw "I/O error";
        

        lineCount = 0;
        

        clock_t startTime = clock();
        //File Read
        while (fin.good() && lineCount != n)
        {

            string line;
            getline(fin, line);
            strcpy(buf, line.c_str());
            if (buf[0] == 0) continue;
            

            const string term(token = strtok(buf, tab));
            const string section(token = strtok(0, tab));
            const string course((token = strtok(0, tab)) ? token : "");
            const string instructor((token = strtok(0, tab)) ? token : "");
            const string whenWhere((token = strtok(0, tab)) ? token : "");
            if (course.find('-') == string::npos) continue; // invalid line
            const string subjectCode(course.begin(), course.begin() + course.find('-'));
            
            
            lineCount++;
        }
        //End file read
        
        clock_t endTime = clock();
        

        assert(assertInt == lineCount);
        

        fin.close();
        

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
    
        
    }
}
