// Lab 15A, Graph Search
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include<stack>
#include<algorithm>
using namespace std;

struct Vertex
{
    string name;
    bool isVisited;
    list<int> Adj_Vertices;
};

queue<int> BFS(int Origin, vector<Vertex>& database)
{
    

    queue<int> Search;
    queue<int>Q;
    for(int i=0;i<database.size();i++)
        database[i].isVisited=false;
    database[Origin].isVisited=true;
    Search.push(Origin);
    Q.push(Origin);
    list<int>::const_iterator it;
    
    while(!Q.empty())
    {
        int a = Q.front();
        Q.pop();
        for(it=database[a].Adj_Vertices.begin();it!=database[a].Adj_Vertices.end();it++)
        {
            if(database[*it].isVisited==false)
            {
                database[*it].isVisited=true;
                Search.push(*it);
                Q.push(*it);
            }
        }
    }
    return Search;
}

queue<int> DFS(int Origin, vector<Vertex>& database)
{

    queue<int> Search;
    stack<int>Q;
    for(int i=0;i<database.size();i++)
        database[i].isVisited=false;
    Q.push(Origin);
    while(!Q.empty())
    {
        int a = Q.top();
        Q.pop();
        if(!database[a].isVisited)
        {
            database[a].isVisited=true;
            Search.push(a);
            list<int>::const_reverse_iterator it;
            for(it=database[a].Adj_Vertices.rbegin();it!=database[a].Adj_Vertices.rend();it++)
            {
                if(!database[*it].isVisited)
                {
                    Q.push(*it);
                }
            }
        }
    }
    return Search;
}

int main()
{
    // print my name and this assignment's title
    cout << "Lab 15A, Graph Search" << endl;
    cout << "Programmer: Haris Hanif" << endl;
    cout << "Editor(s) used: Sublime Text 2" << endl;
    cout << "Compiler(s) used: G++" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good())
        throw "I/O error";
    
    vector<Vertex> database;
    while (fin.good())
    {
        string fromCity;
        string toCity;
        
        getline(fin, fromCity);
        getline(fin, toCity);
        
        fin.ignore(1000, 10);
        fin.ignore(1000, 10);

        fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
        toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
        

        int To = -1;
        int From = -1;
        int i;
        for (i = 0; i < database.size(); i++)
            if (database[i].name == fromCity)
                break;
        if (i == database.size())
        {
            Vertex fromVertex;
            fromVertex.name = fromCity;
            database.push_back(fromVertex);
        }
        From = i;
        
        for (i = 0; i < database.size(); i++)
            if (database[i].name == toCity)
                break;
        if (i == database.size())
        {
            Vertex toVertex;
            toVertex.name = toCity;
            database.push_back(toVertex);
        }
        To = i;
        
        database[From].Adj_Vertices.push_back(To);
        database[To].Adj_Vertices.push_back(From);
    }
    fin.close();
    cout << "The Input file was processed" << endl;
    
    while (true)
    {
        string Start_City;
        cout << "Enter the city you would like to start with or press ENTER exit: ";
        getline(cin, Start_City);
        if (Start_City.length() == 0)
            break;
        
        int i;
        bool found = false;
        
        for (i = 0; i < database.size(); i++)
            if (database[i].name == Start_City)
            {
                found=true;
                break;
            }
        if(found)
        {
            cout << "BFS";
            queue<int> a = BFS(i, database);
            while(!a.empty())
            {
                cout  << '-'<< database[a.front()].name;
                a.pop();
            }
            cout << endl;
            
            cout << "DFS";
            a = DFS(i, database);
            while(!a.empty())
            {
                cout  << '-'<< database[a.front()].name;
                a.pop();
            }
            cout << endl;
        }  
        else
            cout<< endl << "No city was found in the database"<<endl;
    }
    
}
