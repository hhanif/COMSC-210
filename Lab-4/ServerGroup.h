// Lab 4A, Server Group
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef ServerGroup_h
#define ServerGroup_h

class ServerGroup {
public:
    ServerGroup(int);
    bool spServerFree();
    bool ServerFree();
    void userServer(int);
    void usespServer(int);
    void decServers();
    
private:
    int* servers;
    int spServer;
    int freeServer;
    int size;
    
};

#endif
