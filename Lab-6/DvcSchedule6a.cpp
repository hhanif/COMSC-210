// Lab 6A, DVC Schedule Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

struct Subject
{
    string term;
    string section;
};

struct SubjectCode
{
    string name;
    int count;
};

int main(int argc, const char * argv[]) {
    // print my name and this assignment's title
    cout << "Lab 6A, DVC Schedule Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    vector<Subject> Subjects;
    vector<SubjectCode> SubjectCodes;
    string line, term, section, course, instructor, whenWhere;
    
    size_t found = -1;
    

    const char* const tab = "\t";
    
    int line_count = 0;
    

    clock_t startTime = clock();
    

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";
    
    getline(fin, line);
    

    while (!fin.eof())
    {
        if(++line_count % 1000 == 0)
        {
            cout << ".";
            cout.flush();
        }
        

        getline(fin, line);
        
        term = string(strtok((char *)line.c_str(), tab));
        section = string(strtok(NULL, tab));
        course = string(strtok(NULL, tab));
        instructor = string(strtok(NULL, tab));
        whenWhere = string(strtok(NULL, tab));
        
        if (course.find('-') == string::npos) continue;
        

        bool check = true;
        
        for(int i = 0; i < Subjects.size(); i++)
        {
            if( Subjects[i].term.compare(term) == 0 && Subjects[i].section.compare(section) == 0 )
            {
                check = false;
                break;
            }
        }
        
        if(!check)
        {
            continue;
        }
        else
        {
            Subject temp;
            temp.term = term;
            temp.section = section;
            Subjects.push_back(temp);
            
            found = course.find("-");
            course = course.substr(0, found);
            check = true;
            
            for(int i = 0; i < SubjectCodes.size(); i++)
            {
                if( SubjectCodes[i].name.compare(course) == 0 )
                {
                    SubjectCodes[i].count++;
                    check = false;
                    break;
                }
            }
            
            if(check)
            {
                SubjectCode temp;
                temp.name = course;
                temp.count = 1;
                SubjectCodes.push_back(temp);
            }
        }
    }
    fin.close();
    

    for(int i = 0; i < SubjectCodes.size(); i++)
    {
        for(int j = 0; j < SubjectCodes.size() - i - 1; j++)
        {
            for(int a = 0; a < SubjectCodes[j].name.length() || a < SubjectCodes[j + 1].name.length(); a++)
            {
                if(SubjectCodes[j].name.at(a) < SubjectCodes[j + 1].name.at(a)) break;
                

                if(SubjectCodes[j].name.at(a) > SubjectCodes[j + 1].name.at(a))
                {
                    SubjectCode temp = SubjectCodes[j];
                    SubjectCodes[j] = SubjectCodes[j + 1];
                    SubjectCodes[j + 1] = temp;
                    break;
                }
            }
        }
    }
    
    double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    
    for(int i = 0; i < SubjectCodes.size(); i++)
    {
        cout << SubjectCodes[i].name << ", " << SubjectCodes[i].count << " classes" << endl;
        cout.flush();
    }
    
    cout << "ElapsedSeconds: " << elapsedSeconds << endl;
}
