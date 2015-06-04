// Lab 5B, DVC Schedule Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode
    
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <cstring>
using namespace std;
#include "StaticArray.h"

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
    
  int main()
  {
        
  // print my name and this assignment's title
  cout << "Lab 5B, DVC Schedule Program \n";
  cout << "Programmer: Haris Hanif\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
      
      StaticArray <Subject, 70000> Subjects;
      StaticArray <SubjectCode, 70000> SubjectCodes;
      string line, term, section, course, instructor, whenWhere;
      
      size_t found = -1;
      
      // for parsing the input file
      const char* const tab = "\t";
      
      int count = 0, sc_count = 0, line_count = 0;
      
      

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
          
          assert(count <= 70000);
          assert(sc_count <= 70000);
          

          bool check = true;
          for(int i = 0; i < count; i++)
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
              Subjects[count].term = term;
              Subjects[count].section = section;
              count++;
              
              found = course.find("-");
              course = course.substr(0, found);
              
              check = true;
              for(int i = 0; i < sc_count; i++)
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
                  SubjectCodes[sc_count].name = course;
                  SubjectCodes[sc_count].count = 1;
                  sc_count++;
              }
          }
      }
      fin.close();
      
      for(int i = 0; i < sc_count; i++)
      {
          for(int j = 0; j < sc_count - i - 1; j++)
          {
              for(int a = 0; a < SubjectCodes[j].name.length() && a < SubjectCodes[j + 1].name.length(); a++)
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
      
      for(int i = 0; i < sc_count; i++)
      {
          cout << SubjectCodes[i].name << ", " << SubjectCodes[i].count << " classes" << endl;
          cout.flush();
      }
      
      cout << "ElapsedSeconds: " << elapsedSeconds << endl;
  }
