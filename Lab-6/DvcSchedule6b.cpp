// Lab 6B, DVC Schedule Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>
#include <cassert>
#include <ctime>
#include <vector>

#include "DynamicArray.h"
#include "DynamicArray.h"

struct Course
{
    string name;
    int count =0;
};

struct SubjectCode
{
    string name;
    vector<Course> course;
};

struct SectionTracker
{
    string term;
    string section;
};

int main(int argc, const char * argv[]) {
    // print my name and this assignment's title
    cout << "Lab 6B, DVC Schedule Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    vector<SubjectCode> subjectCodes;
    DynamicArray<SectionTracker> SectionTrackera(2000000);

    ofstream fout;
    fout.open("DvcSchedule.xls");
    if(!fout.good()) throw "I/O Error";
    
    int courses;
    int subCount=0;
    int dupCount=0;
    bool courseInc = false;
    bool courseExists = false;
    bool cVect = false;
    int secCount = 1;
    int linecounter = 0;
    bool duplicatesCheckerResult = false;
    clock_t startTime = clock();
    double startTimer = (double)(clock() - startTime) / CLOCKS_PER_SEC;

    
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    double fileOpened = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    if (!fin.good()) throw "I/O error";
    double processFile = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    // read the input file
    while (fin.good())
    {
        courseExists = false;
        courseInc = false;
        duplicatesCheckerResult = false;
        cVect = false;
        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        courseInc = false;
        if (buf[0] == 0) continue;
        

        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        for(int i = 0; i < secCount; i++)
        {
            if(SectionTrackera[i].term == term && SectionTrackera[i].section == section)
            {
                duplicatesCheckerResult = true;
                dupCount++;
            }
        }

        for(int x = 0; x<subCount; x++)
        {
            if(subjectCodes[x].name == subjectCode && courseInc == false && duplicatesCheckerResult == false && cVect == false)
            {
                for(int c = 0; c<subjectCodes[x].course.size(); c++)
                {
                    if(subjectCodes[x].course[c].name == course)
                        cVect = true;
                }
                if(cVect == false)
                {
                    Course c;
                    c.name = course;
                    c.count++;
                    subjectCodes[x].course.push_back(c);
                    SectionTrackera[secCount].term = term;
                    SectionTrackera[secCount].section = section;
                    secCount++;
                    courseInc = true;
                    cVect = true;
                    continue;
                }
            }
        }
        
        //Adds to the course count if it extists
        for(int x = 0; x < subCount; x++)
        {
            if(subjectCodes[x].name == subjectCode && courseInc == false && duplicatesCheckerResult == false)
            {
                for(int a = 0; a<subjectCodes[x].course.size(); a++)
                {
                    if(courseInc==true)
                        break;
                    if(subjectCodes[x].course[a].name == course)
                    {
                        subjectCodes[x].course[a].count++;
                        courseInc = true;
                        SectionTrackera[secCount].term = term;
                        SectionTrackera[secCount].section = section;
                        secCount++;
                        continue;
                    }
                }
            }
        }
        

        for(int y = 0; y<subCount; y++)
        {
            if(subjectCodes[y].name == subjectCode)
                for(int z = 0; z<subjectCodes.size(); z++)
                {
                    if(subjectCodes[y].course[z].name == course)
                        courseExists = true;
                }
        }

        if(courseInc == false && courseExists != true)
        {
            SubjectCode s;
            Course c;
            s.name = subjectCode;
            c.name = course;
            c.count++;
            s.course.push_back(c);
            subjectCodes.push_back(s);
            subCount++;
            SectionTrackera[secCount].term = term;
            SectionTrackera[secCount].section = section;
            secCount++;
        }
        linecounter++;
        
        if(linecounter%1000==0)
        {
            cout<<". ";
            cout.flush();
        }
    }
    
    fin.close();

    double fileClosed = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    

    
    for(int j =1; j<subCount; j++){
        string key=subjectCodes[j].name;
        vector<Course> key2 = subjectCodes[j].course;
        

        int i = j-1;
        while(i>=0 && subjectCodes[i].name>key)
        {
            subjectCodes[i+1] = subjectCodes[i];
            i=i-1;
        }
        subjectCodes[i+1].name = key;
        subjectCodes[i+1].course = key2;
    }
    
    for(int k=0; k<subCount;k++)
    {

        for(int j =1; j<subjectCodes[k].course.size(); j++)
        {
            string coursekey = subjectCodes[k].course[j].name;
            int coursekey2 = subjectCodes[k].course[j].count;
            

            int i=j-1;
            while(i>=0 && subjectCodes[k].course[i].name>coursekey)
            {
                subjectCodes[k].course[i+1].name = subjectCodes[k].course[i].name;
                i=i-1;
            }
            subjectCodes[k].course[i+1].name = coursekey;
            subjectCodes[k].course[i+1].count = coursekey2;
        }
    }
    
    
    
    double fileSorted = (double)(clock() - startTime) / CLOCKS_PER_SEC;

    cout << endl;
    
    fout<<" Subject " << '\t' << "Courses" <<endl;
    for(int x = 0; x < subCount; x++)
    {
        cout <<subjectCodes[x].name;
        cout << ",";
        cout <<subjectCodes[x].course.size();
        cout <<" course (s)";
        cout <<endl;
        fout << subjectCodes[x].name;
        fout << '\t';
        fout << subjectCodes[x].course.size();
        fout << endl;
        for(int b = 0; b<subjectCodes[x].course.size();b++)
        {
            cout<<"   ";
            cout <<subjectCodes[x].course[b].name;
            cout << ", ";
            cout <<subjectCodes[x].course[b].count;
            cout << " class(es) ";
            cout <<endl;
            fout << subjectCodes[x].course[b].name;
            fout << '\t';
            fout << subjectCodes[x].course[b].count;
            fout << endl;
            
        }
    }
    double resultsPrinted = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    
    cout<<"The total number of duplicates found is: ";
    fout <<dupCount;
    fout <<endl;

    cout<<"Time taken for the following tasks:\nStart time: ";
    cout << startTimer;
    cout <<endl;
    cout <<"File opened: ";
    cout << fileOpened;
    cout <<endl;
    cout <<"Processed input file: ";
    cout << processFile;
    cout <<endl;
    cout <<"File Closed: ";
    cout << fileClosed;
    cout <<endl;
    cout <<"File sorted: ";
    cout << fileSorted;
    cout <<endl;
    cout <<"Results printed: ";
    cout << resultsPrinted;
    cout <<endl;
    
    
    
}
