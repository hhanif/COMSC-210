// Lab 13, Simulation
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


#include <ctime>
#include <cmath>
#include <cstdlib>

struct ServiceEvent
{
    int clockTime;
    int serverNumber;
};

struct Customer
{
    int arrivalTime;
    int serviceTime;
    int completionTime;
    char ID;
};


int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
    int requests = 0;
    double probOfnRequests = exp(-averageRequestsPerTimeStep);
    for (double randomValue = (double)rand() / RAND_MAX;
         (randomValue -= probOfnRequests) > 0.0;
         probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
    return requests;
}


bool operator<(const ServiceEvent& Event_1, const ServiceEvent& Event_2)
{
    bool result = true;
    if (Event_1.clockTime < Event_2.clockTime)
        return false;
    return result;
}

int main()
{
    // print my name and this assignment's title
    cout << "Lab 13, Simulation " << endl;
    cout << "Programmer: Haris Hanif" << endl;
    cout << "Editor(s) used: Sublime Text 2" << endl;
    cout << "Compiler(s) used: G++" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    ifstream fin;
    fin.open("simulation.txt");
    if (!fin.good()) throw "I/O Error";
    
    int numServers = 0;
    double arrivalRate = 0;
    int maxQueueLength = 0;
    int minServiceTime = 0;
    int maxServiceTime = 0;
    int closingTime = 0;
    double turnAwayRate;

    fin >> numServers;
    fin >> arrivalRate;
    fin >> maxQueueLength;
    fin >> minServiceTime;
    fin >> maxServiceTime;
    fin >> closingTime;
    
    fin.close();
    srand(time(0));
    
    cout << "Number of Servers: ";
    cout << numServers << endl;
    cout << "The Customer arrival rate: ";
    cout << arrivalRate;
    cout << " Per minute, for a total of ";
    cout << closingTime;
    cout << " minutes" << endl;
    cout << "Maximum queue length:  ";
    cout << maxQueueLength << endl;
    cout << "Minimum service time:  ";
    cout << minServiceTime;
    cout << " minutes" << endl;
    cout << "Maximum service time:  ";
    cout << maxServiceTime;
    cout << " minutes" << endl;
    turnAwayRate = arrivalRate - (numServers / ((double)(maxServiceTime - minServiceTime) / 2));
    cout << "Expected turn away rate: ";
    cout << turnAwayRate;
    cout << " per minute, while full" << endl;
    
    vector<Customer> servers(numServers);
    vector<bool> busyServer(numServers);
    vector<Customer> completed;
    queue<Customer> waiting;
    priority_queue<ServiceEvent> serviceEvent;
    int Number_turned_Away=0;
    int numberID = 0;
    double Average_Turned_Away = 0;
    
    for (int time = 0;; time++) // the clock time
    {
        while(serviceEvent.size() !=0 && time == serviceEvent.top().clockTime)
        {
            int service = serviceEvent.top().serverNumber;
            serviceEvent.pop();
            servers[service].completionTime = time;
            completed.push_back(servers[service]);
            busyServer[service] = false;
        }

        if(time<closingTime)
        {
            int numberofArrivals = getRandomNumberOfServiceRequests(arrivalRate);
            for(int i=0; i< numberofArrivals ;i++)
            {
                if(waiting.size()>= maxQueueLength)
                    Number_turned_Away++;

                else
                {
                    Customer newCust; newCust.arrivalTime = time;
                    if (numberID>25)
                        newCust.ID = (char)('A' + (numberID++%26));
                    else
                        newCust.ID = (char)('A' + numberID++);
                    waiting.push(newCust);
                }
            }
        }

        for(int j = 0; j< numServers ; j++)
        {
            if(busyServer[j] == false && waiting.empty() == false)
            {
                servers[j] = waiting.front();
                busyServer[j] = true;
                waiting.pop();
                servers[j].serviceTime = time;
                servers[j].completionTime = time + (rand() %(maxServiceTime- minServiceTime +1) +minServiceTime);
                ServiceEvent newServ; newServ.clockTime = servers[j].completionTime; newServ.serverNumber=j;
                serviceEvent.push(newServ);
            }
        }

        cout << "Time: " << time << endl;
        cout << "------------------------------------------\n";
        cout << " Line | Now Serving | Waiting Queue " << endl;
        cout << "---------------------------------" << endl;
        for(int i=0; i <numServers; i++)
        {
            cout << " "<<i;
            if(busyServer[i]  == true )
                cout<< "        " << servers[i].ID<<"        ";
            if(i==0 && waiting.size()>0)
            {
                queue<Customer> copy = waiting;
                int tempsize = copy.size();
                for(int a =0; a < tempsize;a++)
                {
                    Customer temp = copy.front();
                    copy.pop();
                    cout << temp.ID;
                }
            }
            cout<<endl;
        }

        if(time>0)
        {
            double total=0;
            for(int i=0; i<completed.size(); i++)
                total += completed[i].completionTime-completed[i].arrivalTime;
            double AverageTime = 0;
            if(completed.size() >0)
                AverageTime = total/completed.size();
            cout << "Average Time: " << AverageTime << endl;
            if(time!=0 && time < 50)
                Average_Turned_Away = Number_turned_Away/(double)time;
            cout<< endl << "Average Number of Customers Turned away per minute: " << Average_Turned_Away <<endl;
        }
        
        cout << "\nPress ENTER to continue, X-ENTER to exit...";
        char exit;
        cin.get(exit);
        if(exit=='x' || exit =='X')
            break;
        else
            continue;
    }
}
