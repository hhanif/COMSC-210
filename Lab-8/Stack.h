// Lab 8A, Stack
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <iomanip>
using namespace std;

template<class DataType>
class Stack
{
private:
    int top;
    int size;
    int capacity;
    DataType* elements;
    DataType dummy;
public:
    Stack(int);
    void push(const DataType&);
    DataType& pop();
    DataType& peek();
    int cap() const{return capacity;}
    bool isEmpty(){return top == -1;}
    void makeEmpty();
    void changeCapacity(int);
    
};

template<class DataType>
Stack<DataType>::Stack(int cap)
{
    capacity = cap;
    top = -1;
    size = 0;
    if(capacity<=0)
        elements = 0;
    else
        elements = new DataType[capacity];
}

template<class DataType>
void Stack<DataType>::push(const DataType& value)
{
    top++;
    if(top == capacity)
        changeCapacity(capacity+1);
    elements[top] = value;
}

template<class DataType>
DataType& Stack<DataType>::pop()
{
    if(top == -1) return dummy;
    
    return elements[top--];
    
}

template<class DataType>
DataType& Stack<DataType>::peek()
{
    if(top == -1) return dummy;
    return elements[top];
}

template <class DataType>
void Stack<DataType>::changeCapacity(int newCap)
{
    DataType* newData = new DataType[newCap];
    for (int i = 0; i < capacity; i++) newData[i] = elements[i];
    delete [] elements; elements = newData;
    
    capacity = newCap;
}

template<class DataType>
void Stack<DataType>::makeEmpty()
{
    top=-1;
    changeCapacity(2);
}

#endif
