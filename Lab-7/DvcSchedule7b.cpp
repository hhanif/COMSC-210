// Lab 7b, The "Applying Advanced Linked-List Techniques" Program
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

struct Node
{
    SubjectCode data;
    Node* next;
};

int main()
{
    // print my name and this assignment's title
    cout << " // Lab 7b, The Applying Advanced Linked-List Techniques Program\n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    vector<Subject> Subjects;
    Node* start = NULL;
    
    int duplicate_count = 0;
    string line, term, section, course, instructor, whenWhere;
    
    size_t found = -1;
    
    // for parsing the input file
    char buf[1000];
    const char* const tab = "\t";
    
    int line_count = 0;
    
    //Start timer
    clock_t startTime = clock();
    
    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";
    
    getline(fin, line);
    
    // read the input file
    while (!fin.eof())
    {
        if(++line_count % 1000 == 0)
        {
            cout << ".";
            cout.flush();
        }
        
        //read the line
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;
        
        term = string(strtok((char *)line.c_str(), tab));
        section = string(strtok(NULL, tab));
        course = string(strtok(NULL, tab));
        instructor = string(strtok(NULL, tab));
        whenWhere = string(strtok(NULL, tab));
        
        if (course.find('-') == string::npos) continue; // invalid line
        
        //Check duplicate data
        bool check = true;
        
        for(int i = 0; i < Subjects.size(); i++)
        {
            if( Subjects[i].term.compare(term) == 0 && Subjects[i].section.compare(section) == 0 )
            {
                duplicate_count++;;
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
            
            Node* cur = start, *prev = NULL;
            
            while(cur != NULL)
            {
                if(cur->data.name.compare(course) == 0)
                {
                    cur->data.count++;
                    check = false;
                    break;
                }
                prev = cur;
                cur = cur->next;
            }
            
            // Add new Node
            if(check)
            {
                Node* temp = new Node();
                temp->data.name = course;
                temp->data.count = 1;
                temp->next = NULL;
                
                Node* p, *prev = NULL;
                
                for (p = start; p; p = p->next)
                {
                    if(p->data.name.compare(course) > 0)
                        break;
                    prev = p;
                }
                
                if(prev == NULL)
                {
                    if(start != NULL)
                        temp->next = p;
                    
                    start = temp;
                }
                else
                {
                    prev->next = temp;
                    temp->next = p;
                }
            }
        }
    }
    fin.close();
    
    double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    
    cout << endl;
    cout<< "Duplicate size: ";
    cout<< duplicate_count;
    cout<< endl;
    
    for (Node* p = start; p; p = p->next)
    {
        cout << p->data.name;
        cout << ", ";
        cout << p->data.count;
        cout << " classes";
        cout << endl;
        cout.flush();
    }
    
    cout << "ElapsedSeconds: ";
    cout << elapsedSeconds;
    cout << endl;
}
