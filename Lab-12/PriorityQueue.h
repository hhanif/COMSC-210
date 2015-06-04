// Lab 12A, Priority Queue
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <utility>
using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class DataType>
class PriorityQueue
{
private:
    DataType* data;
    DataType root;
    int size;
    int capacity;
    
public:
    PriorityQueue(int n = 2);
    void enqueue(const DataType&);
    DataType dequeue();
    DataType top() const
    {
        return data[0];
    }
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void changeCapacity(int);
    void clear();
    ~PriorityQueue()
    {
        delete [] data;
    }
    bool empty() const
    {
        if(size>0)
            return false;
        else
            return true;
    }
    PriorityQueue(const PriorityQueue<DataType>&);
    PriorityQueue<DataType>& operator=(const PriorityQueue<DataType>&);
    
};

template<class DataType>
PriorityQueue<DataType>::PriorityQueue(int a)
{
    capacity = a;
    size = 0;
    if(capacity<=0)
        data=0;
    else data = new DataType[capacity];
}

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue<DataType>& a)
{
    capacity = a.getCapacity();
    size = a.getSize();
    data = 0;
    if (capacity > 0)
    {
        data = new DataType[capacity];
        for (int i = 0; i < capacity; i++)
            data[i] = a.data[i];
    }
}

template <class DataType>
void PriorityQueue<DataType>::clear()
{
    for(int i=0;i<size;i++)
        data[i]=0;
    size=0;
}

template <class DataType>
void PriorityQueue<DataType>::changeCapacity(int newCapacity)
{
    if (newCapacity <= 0)
    {
        delete [] data;
        data = 0;
        capacity = newCapacity;
    }
    else
    {
        DataType* newData = new DataType[newCapacity];
        int limit = newCapacity > capacity ? capacity : newCapacity;
        for (int i = 0; i < limit; i++)
            newData[i] = data[i];
        delete [] data;
        data = newData;
        capacity = newCapacity;
    }
}

template <class DataType>
PriorityQueue<DataType>& PriorityQueue<DataType>::operator=(const PriorityQueue<DataType>& x)
{
    if (this != &x)
    {
        delete [] data;
        data = 0;
        capacity = x.getCapacity();
        if (capacity > 0)
            data = new DataType[capacity];
        for (int i = 0; i < capacity; i++)
            data[i] = x.data[i];
        size = x.getSize();;
    }
    return *this;
}

template<class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& value)
{
    
    int index = size;
    
    if(index>=capacity)
        changeCapacity(2 * capacity);
    
    data[index] = value;
    
    while(true)
    {
        
        int parentIndex = ((index+1)/2) - 1;
        
        if(data[parentIndex]>=data[index])
            break;
        
        swap(data[parentIndex],data[index]);
        
        index = parentIndex;
    }
    
    size++;
}

template <class DataType>
DataType PriorityQueue<DataType>::dequeue()
{
    
    root = data[0];
    
    int index = 0;
    
    while(true)
    {
        
        int leftChild = 2*index+1;
        
        int rightChild = 2*index+2;
        
        if(leftChild>=size)
            break;
        
        if((leftChild = (size-1)) || (data[leftChild]>= data[rightChild]))
        {
            
            data[index] = leftChild;
            
            index = leftChild;
        }
        
        else
        {
            
            data[index] = rightChild;
            
            index = rightChild;
        }
    }
    
    size--;
    
    if(size<(capacity/4))
        capacity = capacity/2;
    
    data[index] = data[size];
    
    while(true)
    {
        
        int parentIndex = (index+1)/2 - 1;
        
        if(parentIndex<0)
            break;
        
        if(data[parentIndex]>=data[index])
            break;
        
        swap(data[parentIndex], data[index]);
        
        index = parentIndex;
    }
    
    return root;
    
}

#endif
