// Lab 3c, Rectangle Program
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
    Rectangle();
    Rectangle(const DataType&, const DataType&);
    void setLength(const DataType&);
    void setWidth(const DataType&);
    bool Compare() const;
    DataType perimiter() const;
    DataType area() const;
    
};

template<class DataType>
Rectangle<DataType>::Rectangle()
{
}

template<class DataType>
Rectangle<DataType>::Rectangle(const DataType& w, const DataType& l)
{
    width = w;
    length = l;
}
template <class DataType>
void Rectangle<DataType>::setLength(const DataType& l)
{
    length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth(const DataType& w)
{
    width = w;
}
//Compares to see which is greater
template <class DataType>
bool Rectangle<DataType>::Compare() const
{
    if(length > width)
        return true;
    else
        return false;
}

template <class DataType>
DataType Rectangle<DataType>::perimiter() const
{
    return (2 * length) + (2 * width);
}

template <class DataType>
DataType Rectangle<DataType>::area() const
{
    return length * width;
}


#endif
