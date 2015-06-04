// Lab 8B, Queue
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H


#ifdef NODE

template <class DataType>
struct Node
{
    DataType data;
    Node<DataType>* next;
};
#endif


template <class DataType>
class Queue
{
public:
    

    Queue() : front(0), end(0)
    {
        ;
    }
    Queue(const Queue<DataType>& qCopy);
    ~Queue();
    Queue<DataType>& operator=(const Queue<DataType>& qCopy);
    

    void push(const DataType& parameter);
    void makeEmpty();
    bool pop(DataType& parameter);
    bool pop();
    

    bool empty() const
    {
        return 0 == front;
    }
    bool peek(DataType& parameter) const;
    DataType peek() const
    {
        return (front->data);
    }
    int size() const;
    
private:
    Node<DataType>* front;
    Node<DataType>* end;
};


template <class DataType>
Queue<DataType>::~Queue()
{
    Node<DataType>* p;
    
    while (front)
    {
        p = front->next; delete front; front = p;
    }
}


template <class DataType>
Queue<DataType>::Queue(const Queue<DataType>& qCopy) : front(0), end(0)
{
    Node<DataType>* p;
    
    for (p = qCopy.front; p; p = p->next)
    {
        Node<DataType>* node = new Node<DataType>;
        node->data = p->data;
        node->next = 0;
        
        if (end) end->next = node;
        else front = node;
        
        end = node;
    }
}


template <class DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& qCopy)
{
    if (this != &qCopy)
    {
        Node<DataType>* p;
        

        end = 0;
        while (front)
        {
            p = front->next; delete front; front = p;
        }
        

        for (p = qCopy.front; p; p = p->next)
        {
            Node<DataType>* node = new Node<DataType>;
            node->data = p->data;
            node->next = 0;
            
            if (end) end->next = node;
            else front = node;
            
            end = node;
        }
    }
    
    return *this;
}


template <class DataType>
void Queue<DataType>::push(const DataType& parameter)
{
    Node<DataType>* node = new Node<DataType>;
    node->data = parameter;
    node->next = 0;
    if (end) end->next = node;
    else front = node;
    end = node;
}


template <class DataType>
bool Queue<DataType>::peek(DataType& parameter) const
{
    if (0 == front)
        return false;
    parameter = front->data;
    return true;
}


template <class DataType>
bool Queue<DataType>::pop(DataType& parameter)
{
    if (0 == front)
        return false;
    
    parameter = front->data;
    Node<DataType>* p = front->next;
    delete front;
    front = p;
    
    if (front == 0)
        end = 0;
    
    return true;
}


template <class DataType>
bool Queue<DataType>::pop()
{
    if (0 == front)
        return false;
    
    Node<DataType>* p = front->next;
    delete front;
    front = p;
    
    if (front == 0)
        end = 0;
    
    return true;
}


template <class DataType>
void Queue<DataType>::makeEmpty()
{
    end = 0;
    Node<DataType>* p;
    
    while (front)
    {
        p = front->next;
        delete front;
        front = p;
    }
}


template <class DataType>
int Queue<DataType>::size() const
{
    if (0 == front)
        return 0;
    
    int result = 0;
    Node<DataType>* p;
    
    for (p = front; p; p = p->next)
        result++;
    
    return result;
}


#endif
