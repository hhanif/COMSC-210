// Term Project, Part 2
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#include <cstring>

int main()
{
    // print my name and this assignment's title
    cout << "Term Project, Part 2" << endl;
    cout << "Programmer: Haris Hanif" << endl;
    cout << "Editor(s) used: Sublime Text 2" << endl;
    cout << "Compiler(s) used: G++" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    int duplicates=0;
    
    map<string, map<string,string> >Subject_Codes;
    map<string,map<string,string> >::iterator one;
    map<string,string>::iterator two;
    
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

        string str1=term + " Section: " + section;

        string str2=course + section + term;
        
        Subject_Codes[str1][str2] = course + "-" + section;
    }
    

    fin.close();
    

    for(one = Subject_Codes.begin(); one != Subject_Codes.end(); one++)
        if(one->second.size() > 1)
            duplicates++;
    

    if(duplicates>0)
    {
        cout << "There were a total number of: ";
        cout << duplicates;
        cout << " duplicates found of the section number repeating in the same term found for the sec!" << endl;
        for(one = Subject_Codes.begin(); one != Subject_Codes.end(); one++)
        {
            if(one->second.size() > 1)
            {
                cout << one->first << endl;
                for(two = one->second.begin(); two != one->second.end(); two++) {
                    cout << " ";
                    cout << two->second;
                    cout << endl;
                }
            }
        }
    }
    else
        cout<<"\n No term and section duplicates were found in the database."<<endl;
}
