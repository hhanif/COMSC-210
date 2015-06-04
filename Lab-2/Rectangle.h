// Lab 2B, Rectangle Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#ifndef Rectangle_h
#define Rectangle_h
template <class DataType>

class Rectangle {
private:
    DataType length;
    DataType width;
    
public:
    void setLength(DataType);
    void setWidth(DataType);
    bool Compare();
    DataType perimiter();
    DataType area();
    
};

template <class DataType>
void Rectangle<DataType>::setLength(DataType l)
{
    length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth(DataType w)
{
    width = w;
}
//Compares to see which is greater
template <class DataType>
bool Rectangle<DataType>::Compare()
{
    if(length > width)
        return true;
    else
        return false;
}

template <class DataType>
DataType Rectangle<DataType>::perimiter()
{
    return (2 * length) + (2 * width);
}

template <class DataType>
DataType Rectangle<DataType>::area()
{
    return length * width;
}


#endif
