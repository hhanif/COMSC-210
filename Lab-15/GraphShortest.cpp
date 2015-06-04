// Lab 15B, Graph Shortest
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
#include<algorithm>
using namespace std;

#include <cstdlib>

struct Vertex
{
    string name;
    
    bool isVisited;
    list<pair<int, double> > adjacentVertices;
    int prev;
    double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it;

    for(int i=0;i<database.size();i++)
    {
        database[i].cost=0;
        database[i].prev= -1;
        database[i].isVisited=false;
    }
    queue<int>Q;
    database[iStart].isVisited=true;
    Q.push(iStart);
    while(!Q.empty())
    {
        int a = Q.front();
        Q.pop();
        for(it=database[a].adjacentVertices.begin();it!=database[a].adjacentVertices.end();it++)
        {
            if(!database[it->first].isVisited)
            {
                database[it->first].isVisited =true;
                database[it->first].cost= database[a].cost+1;
                database[it->first].prev=a;
                Q.push(it->first);
            }
            if(it->first==iEnd)
            {
                while(!Q.empty())
                    Q.pop();
                break;
            }
        }
    }
    result.second = database[iEnd].cost;
    for(int svertex=iEnd;svertex >=0;svertex=database[svertex].prev)
        result.first.push(svertex);
    return result;
}

int main()
{
    // print my name and this assignment's title
    cout << "Lab 15B, Graph Shortest" << endl;
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
    while (fin.good()) // EOF loop
    {
        string fromCity, toCity, cost;
        
        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10); // skip the separator
        
        fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
        toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
        
        
        int iToVertex = -1, iFromVertex = -1, i;
        for (i = 0; i < database.size(); i++) // seek "to" city
            if (database[i].name == fromCity)
                break;
        if (i == database.size()) // not in database yet
        {
            Vertex fromVertex;
            fromVertex.name = fromCity;
            database.push_back(fromVertex);
        }
        iFromVertex = i;
        
        for (i = 0; i < database.size(); i++) // seek "from" city
            if (database[i].name == toCity)
                break;
        if (i == database.size()) // not in vector yet
        {
            Vertex toVertex;
            toVertex.name = toCity;
            database.push_back(toVertex);
        }
        iToVertex = i;
        
        double edgeCost = atof(cost.c_str());
        database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
        database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
    }
    fin.close();
    cout << "Input file processed\n\n";
    
    while (true)
    {
        string fromCity, toCity;
        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, fromCity);
        if (fromCity.length() == 0) break;
        
        int iFrom;
        bool from=false;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == fromCity)
            {
                from=true;
                break;
            }
        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, toCity);
        if (toCity.length() == 0)
            break;
        
        int iTo;
        bool to = false;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
            {
                to =true;
                break;
            }
        if(from && to)
        {
            pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
            cout << "\nTotal edges: " << result.second;  
            while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
            cout<<endl;
        }
        else
        {
            if(!from && !to)
                cout<<"\nNo start city and end city was found in the database"<<endl;
            else if(!from && to)
                cout<<"\nNo start city was found in the database"<<endl;
            else
                cout<<"\nNo end city was found in the database"<<endl;
        }
        
    }
}
