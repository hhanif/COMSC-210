// Term Project, Part 3
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include<algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include<sstream>
#include <string>
using namespace std;
#include <cctype>
#include <cstring>

class toUpper
{
    public:char operator()(char c) const
    {
        return toupper(c);
    }
};

int main()
{
    // print my name and this assignment's title
    cout << "Term Project, Part 3" << endl;
    cout << "Programmer: Haris Hanif" << endl;
    cout << "Editor(s) used: Sublime Text 2" << endl;
    cout << "Compiler(s) used: G++" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    char* token;
    char buf[1000];
    const char* const tab = "\t";
    map<string ,string>subjectCodes;

    string course_input;
    
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";

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
        if(subjectCodes.find(course)!=subjectCodes.end())
        {
            string year_one;
            string year_two;
            string term_one;
            string term_two;

            stringstream ss_one(term);
            term_two=subjectCodes[course];
            stringstream ss_two(term_two);
            ss_one>>term_one>>year_one;
            ss_two>>term_two>>year_two;
            
            int year_three=atoi(year_one.c_str());
            int year_four=atoi(year_two.c_str());
            
            if(year_three > year_four)
                subjectCodes[course]=term;
            else if(year_three==year_four)
            {
                if(term_one=="Summer" && (term_two=="Spring"|| term_two=="Fall"))
                    subjectCodes[course]=term;
                else if(term_one=="Spring" && term_two=="Fall")
                    subjectCodes[course]=term;
            }
            else
                continue;
        }
        else
            subjectCodes[course]=term;
    }

    fin.close();
    

    cout << "Enter the name of the course you would like to search for: " << endl;
    cout << "Enter Course name and Subject Code for the DVC course or enter X to exit" << endl;
    
    while(true)
    {

        cout << "Course: ";
        getline(cin,course_input);

        transform(course_input.begin(),course_input.end(),course_input.begin(),toUpper());

        if(course_input == "X")
        {
            cout << "Exiting program, GoodBye!" << endl;
            break;
        }

        if(subjectCodes.find(course_input) != subjectCodes.end()) {
            cout << course_input;
            cout << " was last offered in ";
            cout << subjectCodes[course_input] << "." << endl;
        }
        else {
            cout << " The course you entered was not found or has not been offered since the year 2000." << endl;
        }
    }
    
}
