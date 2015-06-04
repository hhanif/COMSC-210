// Lab 14B, DVC Schedule Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <fstream>
#include <iostream>
#include <string>
#include "SortableArray.h"

using namespace std;
#include<ctime>
#include<cassert>
#include <cstring>
struct SubjectCode
{
    int count;
    string name;
    bool operator<(const SubjectCode& subject)
    {
        return name < subject.name;
    }
};

int main()
{
    // print my name and this assignment's title
    cout << "Lab 14B, DVC Schedule Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    SortableArray<SubjectCode,200>SubjectCodes;
    int size=0;
    int duplicates=0;
    int lines = 0;
    int i = 0;
    char* token;
    char buf[1000];
    const char* const space = "\t";
    string subject_found;


    clock_t startTime = clock();

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        throw "I/O error";
    

    while (fin.good())
    {

        if(++lines % 1000 == 0)
        {
            cout << ".";
            cout.flush();
        }

        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;
        

        const string term(token = strtok(buf, space));
        const string section(token = strtok(0, space));
        const string course((token = strtok(0, space)) ? token : "");
        const string instructor((token = strtok(0, space)) ? token : "");
        const string whenWhere((token = strtok(0, space)) ? token : "");
        if (course.find('-') == string::npos)
            continue; // invalid line
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        assert(size <= 60000);

        if(subject_found.find( term + section  ) != string::npos)
        {
            duplicates ++;

            continue;
        }
        subject_found =  term + section + subject_found;

        for(i = 0; i<size; i++)
            if(SubjectCodes[i].name == subjectCode)
                break;

        if(size == i)
        {
            SubjectCodes[i].name = subjectCode;
            SubjectCodes[i].count = 1;
            size++;
        }

        else
            SubjectCodes[i].count++;
    }
    cout<<endl;

    fin.close();

    

    SubjectCodes.sort(size);

    double elapsedSeconds = (double)(clock()-startTime) / CLOCKS_PER_SEC;

    for(i = 0; i<size;i++)
    {
        cout << SubjectCodes[i].name;
        cout << ", ";
        cout << SubjectCodes[i].count;
        cout << endl;
    }
    cout << "Number of Duplicate classes:";
    cout << duplicates << endl;
    cout << "Time elapsed in program: ";
    cout << elapsedSeconds;
    cout << " seconds ";
    cout << endl;
    
}
