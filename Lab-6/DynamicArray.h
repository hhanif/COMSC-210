// Lab 6A, DVC Schedule Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>
#include <iomanip>
using namespace std;

template<class DataType>
class DynamicArray
{
    DataType* data;
    bool* inUse;
    DataType dummy;
    int capacity;
    
public:
    DynamicArray(int c);
    int size() const{return capacity;}
    int lsearch(const DataType& value);
    bool containsKey(int);
    void deleteKey(int index);
    void changeCapacity(int);
    DynamicArray<DataType>& operator=(const DynamicArray<DataType>& a);
    DataType& operator[](int);
    
    ~DynamicArray();
    
};

template<class DataType>
DynamicArray<DataType>::DynamicArray(int c):capacity(c)
{
    if(capacity<=0)
    {
        data = 0;
        inUse = 0;
    }
    data = new DataType[capacity];
    inUse = new bool[capacity];
    for(int i; i<capacity;i++)
    {
        inUse[i] = false;
    }
}

template<class DataType>
bool DynamicArray<DataType>::containsKey(int index)
{
    if(inUse[index]) return true;
    if(index<0) return false;
    if(index >= capacity) return false;
}

template<class DataType>
void DynamicArray<DataType>::deleteKey(int index)
{
    if(0>index || index >= capacity) return;
    inUse[index] = false;
}


template<class DataType>
int DynamicArray<DataType>::lsearch(const DataType& value)
{
    int result = -1;
    for(int i=0; i<capacity; i++)
    {
        if(inUse[i]&&data[i]==value)
            return i;
    }
    return result;
}

template <class DataType>
void DynamicArray<DataType>::changeCapacity(int newCap)
{
    DataType* newData = new DataType[newCap];
    for (int i = 0; i < capacity; i++) newData[i] = data[i];
    delete [] data; data = newData;
    
    capacity = newCap;
}

template <class DataType>
DataType& DynamicArray<DataType>::operator[](int index)
{
    if (index < 0 || index >= size())
        changeCapacity(index*2);
    return data[index];
}

template <class DataType>
DynamicArray<DataType>::~DynamicArray()
{
    delete [] data;
    delete [] inUse;
}

template <class DataType>
DynamicArray<DataType>& DynamicArray<DataType>::operator=(const DynamicArray<DataType>& a)
{
    if (this == &a) return *this;
    
    capacity = a.capacity;
    
    delete [] data;
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++) data[i] = a.data[i];
    

    delete [] inUse;
    inUse = new DataType[capacity];
    for(int x = 0; x < capacity; x++) inUse[x] = a.inUse[x];
    
    
    return *this;
}

#endif
