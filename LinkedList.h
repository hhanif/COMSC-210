// Lab 10A, Linked List
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef LinkedList_H
#define LinkedList_H

#include<cassert>

template<class DataType>
class LinkedList
{
    struct Node
    {
        DataType data;
        bool inUse;
        Node*next;
    };
    
    Node*start;
    DataType dummy;
    int capacity;
    int size_1;
    mutable int lastIndex;
    mutable Node* lastNode;
    void changeCapacity(int);
public:
    int size() const
    {
        return size_1;
    }
    int lsearch(const DataType&)const;
    void clear();
    bool containsKey(int)const;
    void deleteKey(int);
    DataType& operator[](int);
    DataType operator[](int)const;
    
    LinkedList():size_1(0),start(0),capacity(0),lastIndex(-1),lastNode(0){}
    LinkedList<DataType>& operator=(const LinkedList<DataType>&);
    LinkedList(const LinkedList<DataType>&);
    ~LinkedList();
};
template<class DataType>
int LinkedList<DataType>::lsearch(const DataType& parameter)const
{
    int i;
    Node*p;
    for(i=0,p=start;p;p=p->next,i++)
        if(p->inUse &&p->data==parameter)
            break;
    
    if(p==0)
        return -1;
    else
        return i;
}

template<class DataType>
void LinkedList<DataType>::clear()
{
    Node*p;
    while(start)
    {
        p=start->next;
        delete start;
        start=p;
    }
    capacity=0;
    size_1=0;
    lastNode=0;
    lastIndex=-1;
}

template<class DataType>
bool LinkedList<DataType>::containsKey(int index)const
{
    int i;
    Node*p;
    for(i=0,p=start;p;p=p->next,i++)
        if(i==index && p->inUse)
            break;
    
    if(p==0)
        return false;
    else
        return true;
}

template<class DataType>
void LinkedList<DataType>::deleteKey(int index)
{
    Node*p;
    int i;
    for(i=0,p=start;p;p=p->next,i++)
        if(i==index && p->inUse)
            break;
    
    if(p==0)
        return;
    else
    {
        if(p->inUse)
        {
            size_1--;
            p->inUse=false;
        }
    }
}

template<class DataType>
void LinkedList<DataType>::changeCapacity(int newCapacity)
{
    Node*p;
    Node*prev;
    for(prev=0,p=start;p;prev=p,p=p->next);
    
    for(int i=capacity;i<newCapacity;i++)
    {
        Node*node=new Node;
        node->inUse=false;
        node->next=0;
        if(prev)
            prev->next=node;
        else
            start=node;
        prev=node;
    }
    capacity=newCapacity;
}

template<class DataType>
DataType& LinkedList<DataType>::operator[](int index)
{
    if(index<0)
        return dummy;
    if(capacity<=index)
        this->changeCapacity(index+1);
    
    Node*p=start;
    int i=0;
    if(lastIndex>=0 && lastIndex <=index)
    {
        i=lastIndex;
        p=lastNode;
    }
    
    for(;p;p=p->next,i++)
        if(i==index)
            break;
    
    if(!p->inUse)
    {
        size_1++;
        p->inUse=true;
    }
    lastIndex = index;
    lastNode = p;
    if(!lastNode)
        assert(lastIndex== -1);
    return p->data;
}

template<class DataType>
DataType LinkedList<DataType>::operator[](int index)const
{
    if(index<0)
        return dummy;
    
    Node*p=start;
    int i=0;
    if(lastIndex>=0 && lastIndex<=index)
    {
        i=lastIndex;
        p=lastNode;
    }
    
    for(;p;p=p->next,i++)
        if(i==index)
            break;
    
    lastIndex=index;
    lastNode=p;
    if(!lastNode)
        assert(lastIndex== -1);
    return p->data;
}


template<class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>&a)
:start(0),lastNode(0),lastIndex(a.lastIndex),size_1(a.size_1),capacity(a.capacity)
{
    Node*p=0;
    Node*end=0;
    for(p=a.start;p;p=p->next)
    {
        Node*node = new Node;
        node->data=p->data;
        node->next=0;
        if(end)
            end->next =node;
        else
            start = node;
        end = node;
        if(p==a.lastNode)
            lastNode=node;
    }
}

template<class DataType>
LinkedList<DataType>::~LinkedList()
{
    Node*p;
    while(start)
    {
        p=start->next;
        delete start;
        start=p;
    }
}

template<class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>&a)
{
    if(this!=&a)
    {
        lastNode=0;
        lastIndex=a.lastIndex;
        size_1=a.size_1;
        capacity=a.capacity;
        
        Node*p;
        Node*end =0;
        while(start)
        {
            p=start->next;
            delete start;
            start=p;
        }
        
        for(p=a.start;p;p=p->next)
        {
            Node*node = new Node;
            node->data=p->data;
            node->inUse=p->inUse;
            node->next=0;
            if(end)
                end->next =node;
            else
                start = node;
            end = node;
            if(p==a.lastNode)
                lastNode=node;
        }
    }
    return* this;
}
#endif
