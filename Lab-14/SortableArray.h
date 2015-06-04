// Lab 14A, Sortable Array
// Programmer: Haris Hanif
// Editor(s) used: Sublime Text 2
// Compiler(s) used: G++
#ifndef SortableArray_h
#define SortableArray_h

#include<string>
#include <stack>
#include<algorithm>
using namespace std;

template<class DataType,int CAPACITY>
class SortableArray
{
private:
    bool inUse[CAPACITY];
    DataType dummy;
    DataType data[CAPACITY];
public:
    SortableArray();
    DataType& operator[](int index);
    DataType operator[](int) const;
    int getSize()const;
    int getCapacity()const
    {
        return CAPACITY;
    }
    int lsearch(const DataType& data)const;
    int bsearch(int, const DataType&);
    void sort(int);
    bool containsKey(int index);
    void deleteKey(int index);

};

template <class DataType, int CAPACITY>
SortableArray<DataType,CAPACITY>::SortableArray()
{
    for(int i=0; i<CAPACITY; i++)
    {
        inUse[i]=false;
    }
    
}
template <class DataType, int CAPACITY>
int SortableArray<DataType,CAPACITY>::getSize()const
{
    int counter=0;
    for(int i=0;i<CAPACITY;i++)
        if(inUse[i])
            counter++;
    return counter;
}
template <class DataType, int CAPACITY>
bool SortableArray<DataType,CAPACITY>::containsKey(int index)
{
    if(index<0)
        return false;
    if(index>=CAPACITY)
        return false;
    if(inUse[index])
        return true;
}
template <class DataType, int CAPACITY>
void SortableArray<DataType,CAPACITY>::deleteKey(int index)
{
    if(0>=index ||index>=CAPACITY)
        return;
    inUse[index]=false;
}
template <class DataType, int CAPACITY>
DataType& SortableArray<DataType,CAPACITY>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= CAPACITY)
        return dummy;
    inUse[index]=true;
    return data[index];
}

template <class DataType,int CAPACITY>
DataType SortableArray<DataType, CAPACITY>::operator[](int index) const
{
    
    if (index < 0)
        return dummy;
    if (index >= CAPACITY)
        return dummy;
    if(inUse[index]==false)
        return dummy;
    return data[index];
}
template<class DataType,int CAPACITY>
void SortableArray<DataType,CAPACITY>::sort(int parameter)
{
    
    int s=0;
    int e=parameter;
    pair<int,int>put(s,e);
    stack<pair<int,int> >Cycle;
    Cycle.push(put);
    while(!Cycle.empty())
    {
        put = Cycle.top();
        Cycle.pop();
        s= put.first;
        e= put.second;
        if (s >= e - 1)
            continue;
        int pivot = (s + e - 1) / 2;
        int left = s;
        int right = e - 1;
        
        while (true)
        {
            while(left < pivot)
            {
                if (data[pivot] < data[left])
                    break;
                else
                    ++left;
            }
            while(pivot < right)
            {
                if (data[right] < data[pivot])
                    break;
                else
                    --right;
            }
            
            if (left == right)
            {
                put.first=s;
                put.second=pivot;
                Cycle.push(put);
                put.first=pivot+1;
                put.second=e;
                Cycle.push(put);
                break;
            }
            else if (left == pivot)
            {
                swap(data[pivot], data[right]);
                pivot = right;
                ++left;
            }
            else if (pivot == right)
            {
                swap(data[pivot],data[left]);
                pivot = left;
                --right;
            }
            else
            {
                swap(data[left],data[right]);
                ++left;
                --right;
            }
        }
    }
}
template <class DataType, int CAPACITY>
int SortableArray<DataType, CAPACITY>::lsearch(const DataType& value) const
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
int SortableArray<DataType,CAPACITY>::bsearch(int i,const DataType& value)
{

    int s=0;

    int e=i;
    
    while(true)
    {
        int m = (s + e - 1) / 2;
        if (value == data[m])
            return m;
        else if (s == e - 1)
            return -1;
        else if (value < data[m])
        {
            if (s == m)
                return -1;
            else
            {
                e = m ; continue;
            }
        }
        else
        {
            if (m == e - 1)
                return -1;
            else
            {
                s = m + 1; continue;
            }
        }
    }
    
}
#endif
