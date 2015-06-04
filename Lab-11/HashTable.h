// Lab 11A, Hash Table
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Hastable_h
#define Hastable_h
#include<list>
#include<algorithm>
#include<vector>
template<class KEY,class VALUE,int CAPACITY>
class HashTable
{
    struct Node
    {
        KEY key;
        VALUE value;
        bool operator==(const Node&node)const
        {
            return key==node.key;
        }
        void operator=(const VALUE& v)
        {
            value=v;
        }
    };
    list<Node>data[CAPACITY];
    int n;
    int(*hc)(const KEY&);
    int getWrappedIndex(const KEY&)const;
public:
    HashTable(int(*hc) (const KEY&)):hc(hc),n(0)
    {
    };
    int size()const
    {
        return n;
    }
    int capacity()const
    {
        return 0.8*CAPACITY;
    }
    bool containsKey(const KEY&)const;
    void clear();
    void deleteKey(const KEY&);
    VALUE& operator[](const KEY&);
    VALUE operator[](const KEY&)const;
    vector<KEY>keys()const;
};


template<class KEY,class VALUE, int CAPACITY>
int HashTable<KEY,VALUE,CAPACITY>::getWrappedIndex(const KEY& parameter)const
{

    int WrappedIndex=hc(parameter)% CAPACITY;
    if(WrappedIndex < 0)WrappedIndex += CAPACITY;
    return WrappedIndex;
}


template<class KEY,class VALUE, int CAPACITY>
bool HashTable<KEY,VALUE,CAPACITY>::containsKey(const KEY& parameter)const
{
    int WrappedIndex=getWrappedIndex(parameter);
    Node node;
    node.key=parameter;
    typename list<Node>::const_iterator it=find(data[WrappedIndex].begin(),data[WrappedIndex].end(),node);
    if(it !=data[WrappedIndex].end())
        return true;
    return false;
}


template<class KEY,class VALUE, int CAPACITY>
void HashTable<KEY,VALUE,CAPACITY>::clear()
{
    for(int i=0;i<CAPACITY;i++)
        data[i].clear();
    n=0;
}


template<class KEY,class VALUE, int CAPACITY>
void HashTable<KEY,VALUE,CAPACITY>::deleteKey(const KEY& parameter)
{
    int WrappedIndex=getWrappedIndex(parameter);
    Node node;
    node.key=parameter;
    typename list<Node>::iterator it=find(data[WrappedIndex].begin(),data[WrappedIndex].end(),node);
    if(it !=data[WrappedIndex].end())
    {
        data[WrappedIndex].erase(it);
        n--;
    }
}


template<class KEY,class VALUE, int CAPACITY>
VALUE& HashTable<KEY,VALUE,CAPACITY>::operator[](const KEY& parameter)
{
    int WrappedIndex = getWrappedIndex(parameter);
    Node node;
    node.key=parameter;
    typename list<Node>::iterator it = find(data[WrappedIndex].begin(), data[WrappedIndex].end(), node);

    if(it==data[WrappedIndex].end())
    {
        data[WrappedIndex].push_back(node);
        n++;
        return data[WrappedIndex].back().value;
    }
    else
        return it->value;
}


template<class KEY,class VALUE, int CAPACITY>
VALUE HashTable<KEY,VALUE,CAPACITY>::operator[](const KEY& parameter)const
{
    int WrappedIndex=getWrappedIndex(parameter);
    Node node;
    node.key=parameter;
    typename list<Node>::const_iterator it=find(data[WrappedIndex].begin(),data[WrappedIndex].end(),node);
    if(it==data[WrappedIndex].end())
        return node.value;
    else
        return it->value;
}


template<class KEY,class VALUE, int CAPACITY>
vector<KEY>HashTable<KEY,VALUE,CAPACITY>::keys()const
{
    vector<KEY>keyS;
    typename list<Node>::const_iterator it;
    for(int i=0;i<CAPACITY;i++)
    {
        for(it=data[i].begin();it!=data[i].end();it++)
            keyS.push_back(it->key);
    }
    return keyS;
}

#endif
