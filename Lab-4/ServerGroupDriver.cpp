// Lab 4A, Server Group
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
using namespace std;

#include <cassert>

#include "ServerGroup.h"
#include "ServerGroup.h"



int main(int argc, const char * argv[]) {
    
    // print my name and this assignment's title
    cout << "Lab 4A, Server Group \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //Testing
    cout<<"Start with a group of 4 normal servers and one special server."<<endl;
    ServerGroup servers(4);
    int client;
    int spClient;
    cout<<"A client arrives for 10 minutes of normal service."<<endl;
    client = 10;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"4 minutes elapse."<<endl;
    
    for(int i = 0;i<4;i++)
        servers.decServers();
    
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    
    cout<<"A client arrives for 4 minutes of normal service."<<endl;
    client = 4;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"2 minutes elapse."<<endl;
    
    for(int i = 0;i<4;i++)
        servers.decServers();
    
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"5 clients arrive, for 1, 2, 3, 4, and 5 minutes for normal service, respectively."<<endl;
    client = 1;
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    client = 2;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    client = 3;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    client = 4;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    client = 5;
    
    if(servers.ServerFree())
    {
        servers.userServer(client);
    }
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"1 client arrives for 20 minutes of special service."<<endl;
    spClient = 20;
    if (servers.spServerFree())
        servers.usespServer(spClient);
    
    cout<<"SP Servers Available: "<<servers.spServerFree()<<endl;
    
    
    cout<<"1 minute elapses."<<endl;
    for(int i = 0;i<1;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"1 minute elapses."<<endl;
    for(int i = 0;i<1;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"1 minute elapses."<<endl;
    for(int i = 0;i<1;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"1 client arrives for 10 minutes of special service."<<endl;
    spClient = 10;
    if (servers.spServerFree())
        servers.usespServer(spClient);
    cout<<"SP Servers Available: "<<servers.spServerFree()<<endl;
    
    cout<<"1 minute elapses."<<endl;
    for(int i = 0;i<1;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"10 minute elapses."<<endl;
    for(int i = 0;i<10;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl;
    
    cout<<"10 minute elapses."<<endl;
    for(int i = 0;i<10;i++)
        servers.decServers();
    cout<<"Servers Available: "<<servers.ServerFree()<<endl<<endl;
    
    
    
}
