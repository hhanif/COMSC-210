// Lab 11A, Hash Table
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

#include<cstring>
#include<cassert>

#include "HashTable.h"
#include "HashTable.h"

struct Course
{
    string course;
    string term;
    string section;
    string instructor;
    bool operator==(const Course& C)const
    {
        return course==C.course && term==C.term && section==C.section;
    }
};

int hashCode(const Course& C)
{
    int index=0;
    string theKey=C.term + C.section + C.course;
    for(int i=0;i<theKey.length();i++)
        index+=(int)theKey[i];
    return index;
}


int main()
{
    // print my name and this assignment's title
    cout << "Lab 11A, Hash Table \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    

    HashTable<Course,int ,1009>hash(hashCode);
    Course test;
    vector<Course>keys;

    const int lines_break=100;
    int lines=0;
    int duplicates=0;
    

    cout<<"Test: "<<endl;
    Course s1;
    s1.course="ENG";
    s1.term="Fall 2011";
    s1.section="1122";
    s1.instructor="Plato";
    
    Course s2;
    s2.course="COMSC400";
    s2.term="Spring 2012";
    s2.section="2233";
    s2.instructor="Jobs";
    
    cout<<"testing size()"<<endl;
    cout<<"expected: 0, actual: ";
    cout <<hash.size()<<endl;
    cout<<"Testing operator[] setter" <<endl;
    hash[s1]=1;
    hash[s2]=2;
    cout<<"expected: 1 2 ,actual: ";
    cout <<hash[s1];
    cout <<" ";
    cout <<hash[s2];
    cout <<endl;
    assert(hash[s1]==1 && hash[s2]==2);
    cout<<"Testing containsKey()"<<endl;
    cout<<"expected: 1 1,actual: ";
    cout <<hash.containsKey(s1);
    cout <<" ";
    cout <<hash.containsKey(s2);
    cout <<endl;
    assert(hash.containsKey(s1)==1 && hash.containsKey(s2) ==1);
    cout<<"Testing deleteKey"<<endl;
    hash.deleteKey(s1);
    cout<<"expected: 0 1,actual: ";
    cout <<hash.containsKey(s1);
    cout <<" ";
    cout <<hash.containsKey(s2);
    cout <<endl;
    assert(hash.containsKey(s1)==0 && hash.containsKey(s2)==1);
    
    
    //object copy testing assignment after declaration
    {
        cout<<"Object copy testing after declaration"<<endl;
        HashTable<Course,int,1009>copy(hashCode);
        copy=hash;
        cout<<"expected: 0 2,actual: ";
        cout <<copy[s1];
        cout <<" ";
        cout <<copy[s2];
        cout <<endl;
        assert(copy[s1]==0 && copy[s2]==2);
    }
    
    //const object copy testing
    {
        cout<<"CONST object copy testing upon declaration"<<endl;
        const HashTable<Course,int,1009>copy=hash;
        cout<<"expected: 0 2,actual: ";
        cout <<copy[s1];
        cout <<" ";
        cout <<copy[s2];
        cout <<endl;
        
    }
    

    hash.deleteKey(s2);
    
    cout<<"Now testing DVC schedule"<<endl;

    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good())throw "I/O error";
    
    while (fin.good())
    {
        if(lines == lines_break)
            break;

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

        lines++;
        
        test.course = course;
        test.term = term;
        test.section = section;
        test.instructor = instructor;
        
        if(hash.containsKey(test))
            hash[test]++;
        else
            hash[test] = 1;
    }

    fin.close();
    keys=hash.keys();
    cout<<"Testing keys() && size():"<<endl;
    cout<<"Expected: ";
    cout <<hash.size();
    cout <<" Actual: ";
    cout <<keys.size();
    cout <<endl;
    assert(keys.size() ==hash.size());

    for(int i=0; i < keys.size();i++)
    {

        assert(hash.containsKey(keys[i]));
        if(hash[keys[i]]>1)
            duplicates++;
    }
    cout<<"# of Duplicates found: ";
    cout <<duplicates;
    cout <<endl;
    cout<<"testing size()"<<endl;
    cout<<"expected: ";
    cout <<lines-duplicates;
    cout <<" Actual: ";
    cout <<hash.size();
    cout <<endl;
    assert(lines-duplicates ==hash.size());
    cout<<"Now Testing capacity()"<<endl;
    cout<<"Expected: ";
    cout <<int(1009*.8);
    cout <<" Actual: ";
    cout <<hash.capacity();
    cout <<endl;
    assert(hash.capacity()==int(1009*.8));
    
    //const object copy testing
    {
        cout<<"Now on to Const object copy testing"<<endl;
        const HashTable<Course,int,1009>copy=hash;
        cout<<"testing size()"<<endl;
        cout<<"expected: ";
        cout <<hash.size();
        cout <<" Actual: ";
        cout <<copy.size();
        cout <<endl;
        assert(hash.size()==copy.size());
        vector<Course>copyKeys;
        copyKeys=copy.keys();
        for(int i=0;i<keys.size();i++)
            assert(copyKeys[i]==keys[i]);
        
    }
    
    //object copy testing assignment after declaration
    {
        cout << "Now onto object assignment test after declaration" << endl;
        HashTable<Course, int, 1009> copy(hashCode);
        copy = hash;
        cout << "Testing size():" << endl;
        cout << "Expected: ";
        cout << hash.size();
        cout <<" Actual: ";
        cout << copy.size();
        cout << endl;
        assert(hash.size() == copy.size());
        for(int i = 0; i < keys.size(); i++)
        {
            assert(copy.containsKey(keys[i]));
        }
        lines= 0;
        fin.open("dvc-schedule.txt");
        if (!fin.good()) throw "I/O error";
        while (fin.good())
        {
            if(lines == lines_break)
                break;

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

            lines++;
            
            test.course = course;
            test.term = term;
            test.section = section;
            test.instructor = instructor;
            assert(copy.containsKey(test));
        }

        fin.close();

        cout<<"Now testing the deleteKey()"<<endl;
        copy.deleteKey(keys[0]);
        copy.deleteKey(keys[1]);
        cout<<"Expected: 97. Actual: ";
        cout <<copy.size();
        cout <<endl;

        cout<<"Finally, test clear()"<<endl;
        copy.clear();
        for(int i=0;i<keys.size();i++)
            copy.deleteKey(keys[i]);
        cout<<"expected: 0. Actual: ";
        cout <<copy.size();
        cout <<endl;
        cout<<"End of test, Goodbye."<<endl;
    }    
}
