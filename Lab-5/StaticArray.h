// Lab 5A, Static Array Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef StaticArray_h
#define StaticArray_h

#include<string>
using namespace std;

template<class DataType,int CAPACITY>
class StaticArray
{
public:

    StaticArray();
    DataType& operator[](int index);
    DataType operator[](int) const;
    int getCapacity()const{ return CAPACITY;}
    int getSize()const;
    bool constainsKey(int index);
    void deleteKey(int index);
    int lsearch(const DataType& data)const;
    
private:

    DataType dummy;
    bool inUse[CAPACITY];
    DataType data[CAPACITY];
};


template <class DataType, int CAPACITY>
StaticArray<DataType,CAPACITY>::StaticArray()
{
    for(int i=0; i<CAPACITY; i++)
    {
        inUse[i]=false;
    }
    
}

template <class DataType, int CAPACITY>
int StaticArray<DataType,CAPACITY>::getSize()const
{
    int counter=0;
    for(int i=0;i<CAPACITY;i++)
        if(inUse[i])
            counter++;
    return counter;
}

template <class DataType, int CAPACITY>
int StaticArray<DataType, CAPACITY>::lsearch(const DataType& value) const
{
    int result = -1;
    
    for (int i = 0; i < CAPACITY; i++)
    {
        
        if (data[i]==value)
        {
            result  = i;
            break;
        }
    }
    return result;
}

template <class DataType, int CAPACITY>
bool StaticArray<DataType,CAPACITY>::constainsKey(int index)
{
    if(index<0)
        return false;
    if(index>=CAPACITY)
        return false;
    if(inUse[index])
        return true;
}

template <class DataType, int CAPACITY>
void StaticArray<DataType,CAPACITY>::deleteKey(int index)
{
    if(0>=index ||index>=CAPACITY)
        return;
    inUse[index]=false;
}

template <class DataType, int CAPACITY>
DataType& StaticArray<DataType,CAPACITY>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= CAPACITY)
        return dummy;
    inUse[index]=true;
    return data[index];
}

template <class DataType,int CAPACITY>
DataType StaticArray<DataType, CAPACITY>::operator[](int index) const
{
    
    if (index < 0)
        return dummy;
    if (index >= CAPACITY)
        return dummy;
    if(inUse[index]==false)
        return dummy;
    return data[index];
}

#endif
