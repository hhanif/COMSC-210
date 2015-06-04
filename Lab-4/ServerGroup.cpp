// Lab 4A, Server Group
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include "ServerGroup.h"

ServerGroup::ServerGroup(int s)
{
    size = s;
    servers = new int[s];
    spServer = 0;
    for(int i=0; i<s;i++)
        servers[i] =0;
}

bool ServerGroup::spServerFree()
{
    if (spServer == 0) {
        return true;
    }
    else
        return false;
    
}

bool ServerGroup::ServerFree()
{
    for(int i = 0; i<size; i++)
    {
        if(servers[i]==0)
        {
            freeServer = i;
            return true;
        }
        else
            
            return false;
    }
    return false;
}

void ServerGroup::userServer(int avTransTime)
{
    servers[freeServer] = avTransTime;
}

void ServerGroup::usespServer(int avTransTime)
{
    spServer = avTransTime;
}
void ServerGroup::decServers()
{
    if (spServer > 0)
    {
        spServer -= 1;
    }
    for(int i = 0;i<size;i++)
    {
        if(servers[i]!=0)
            servers[i] =servers[i]-1;
    }
}
