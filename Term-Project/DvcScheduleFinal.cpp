// Term Project, Part 1
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include <fstream>
#include <iostream>
#include <string>
#include<map>
#include<set>
using namespace std;
#include<ctime>
#include <cstring>

int main()
{
    // print my name and this assignment's title
    cout << "Term Project, Part 1" << endl;
    cout << "Programmer: Haris Hanif" << endl;
    cout << "Editor(s) used: Sublime Text 2" << endl;
    cout << "Compiler(s) used: G++" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    int duplicates=0;
    
    set<string>track_duplicates;
    map<string, map<string,int> >Subject_Codes;
    map<string,map<string,int> >::iterator one;
    map<string,int>::iterator two;
    

    clock_t startTime = clock();

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        throw "I/O error";
    

    while (fin.good())
    {
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0)
            continue;
        

        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        if(track_duplicates.find(term+section)!=track_duplicates.end())
        {
            duplicates++;
            continue;
        }
        else
            track_duplicates.insert(term+section);

        Subject_Codes[subjectCode][course]++;
    }
    cout << endl << endl;

    fin.close();
    
    double elapsedSeconds = (double)(clock()-startTime) / CLOCKS_PER_SEC;

    for(one=Subject_Codes.begin();one!=Subject_Codes.end();one++)
    {
        cout <<one->first;
        cout <<", ";
        cout <<one->second.size();
        cout <<" course(s)"<<endl;
        for(two=one->second.begin();two!=one->second.end();two++) {
            cout <<" "<<two->first;
            cout <<", ";
            cout <<two->second;
            cout <<" class(es)"<<endl;
        }
    }
    cout << "\nNumber of Duplicate classes: ";
    cout << duplicates  << endl;
    cout << "Time elapsed in program: ";
    cout << elapsedSeconds;
    cout << " seconds." << endl;
}
