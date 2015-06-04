// Lab 4B, Checkbook
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Checkbook_h
#define Checkbook_h

#include <iostream>
#include <iomanip>
using namespace std;

template<class DataType>
class Checkbook
{
    DataType* checkbook;
    int numChecks;
    double balance;
    void doubleArray();
    double lastdeposit;
    
public:
    int arrSize;
    Checkbook(double);
    DataType* getChecks() const;
    bool writeCheck(const DataType & amount);
    void deposit(double amount);
    double getBalance() const;
    int numberOfChecks() const{return numChecks;}
};
//constructor
template <class DataType>
Checkbook<DataType>::Checkbook(double b)
{
    balance = b;
    arrSize = 2;
    checkbook = new DataType[arrSize];
}

template<class DataType>
DataType* Checkbook<DataType>::getChecks() const
{
    DataType* newPtr = new DataType[arrSize];
    for(int i = 0; i<arrSize; i++)
    {
        newPtr[i] = checkbook[i];
    }
    return newPtr;
}

template<class DataType>
bool Checkbook<DataType>::writeCheck(const DataType & amount)
{
    if(amount>balance)
        return false;
    balance -= amount;
    
    if(numChecks == arrSize)
        doubleArray();
    checkbook[numChecks]=amount;
    numChecks++;
    return true;
}

template<class DataType>
void Checkbook<DataType>::deposit(double amount)
{
    balance += amount;
    lastdeposit = amount;
}

template<class DataType>
double Checkbook<DataType>::getBalance() const
{
    return balance;
}

template<class DataType>
void Checkbook<DataType>::doubleArray()
{
    DataType* doubleA = new DataType[arrSize * 2];
    for(int i = 0; i<arrSize; i++)
    {
        doubleA[i]=checkbook[i];
    }
    delete [] checkbook;
    checkbook = doubleA;
    arrSize *=2;
}

#endif
