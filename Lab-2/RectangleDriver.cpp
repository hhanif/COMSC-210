// Lab 2B, Rectangle Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
using namespace std;

#include <cassert>

#include "Rectangle.h"
#include "Rectangle.h" //ifndef testing
#include "Fraction.h" //ifndef testing



int main(int argc, const char * argv[]) {
    
    // print my name and this assignment's title
    cout << "Lab 2b, Rectangle Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //test all getters and setters
    Rectangle<float>r1;
    r1.setLength(5.12F);
    r1.setWidth(6.23F);
    cout<<"\nTesting the object with a float: "<<endl;
    cout<<"r1 perimeter: 22.7, actual: "<<r1.perimiter()<<endl;
    cout<<"r1 area : 31.8976, actual: "<<r1.area()<<endl;
    cout<<"Testing if length > width  expected: 0 (false), actual: "<<r1.Compare()<<endl;
    assert(22.6 < r1.perimiter() && 22.8 > r1.perimiter() );
    assert(31.8975<r1.area() && 31.8978 > r1.area() );
    
    Rectangle<Fraction>rect;
    Fraction x={1,2};
    Fraction y={3,4};
    rect.setLength(x);
    rect.setWidth(y);
    cout<<"\nTesting the object with the Fraction Datatype: "<<endl;
    cout<<"Testing if length is greater than width:expected: 0 (false), actual: "<<rect.Compare()<<endl;
    Fraction area=rect.area();
    cout<<"area expected: 3/8 ,actual:"<<area.numer<<"/"<<area.denom<<endl;
    Fraction perimeter=rect.perimiter();
    cout<<"Perimeter expected: 20/8, actual:  "<<perimeter.numer<<"/"<<perimeter.denom<<endl;
    
    //object copy testing
    {
        cout<<"Testing copy assignment upon declaration: "<<endl;
        Rectangle<float>copy=r1;
        cout<<"Testing the object copy with float: "<<endl;
        cout<<"copy perimeter expected: 22.7, actual: "<<copy.perimiter()<<endl;
        cout<<"copy area expected: 31.8976, actual:  "<<copy.area()<<endl;
        cout<<"Testing if length is greater than width expected: 0 (false),actual: "<<copy.Compare()<<endl;
        assert(22.6 < copy.perimiter() && 22.8 > copy.perimiter() );
        assert(31.8975<copy.area() && 31.8978 > copy.area() );
        
        Rectangle<Fraction>copyrect=rect;
        cout<<"\nTesting the object copy with a Fraction Datatype: "<<endl;
        cout<<"Testing if length is greater than width expected: 0(false),actual: "<<copyrect.Compare()<<endl;
        Fraction area=copyrect.area();
        cout<<"area  expected:3/8 ,actual:"<<area.numer<<"/"<<area.denom<<endl;
        Fraction perimeter=copyrect.perimiter();
        cout<<"Perimeter expected:20/8, actual: "<<perimeter.numer<<"/"<<perimeter.denom<<endl;
    }
    

    {
        cout<<"Testing copy assignment after declaration: "<<endl;
        Rectangle<float>copy;copy=r1;
        cout<<"Testing the object copy with float: "<<endl;
        cout<<"copy perimeter expected: 22.7, actual: "<<copy.perimiter()<<endl;
        cout<<"copy area expected: 31.8976, actual:  "<<copy.area()<<endl;
        cout<<"Testing if length is greater than width expected: 0 (false),actual: "<<copy.Compare()<<endl;
        assert(22.6 < copy.perimiter() && 22.8 > copy.perimiter() );
        assert(31.8975<copy.area() && 31.8978 > copy.area() );
        
        Rectangle<Fraction>copyrect;copyrect=rect;
        cout<<"\nTesting the object copy with a Fraction Datatype: "<<endl;
        cout<<"Testing if length is greater than width:expected: 0(false),actual: "<<copyrect.Compare()<<endl;
        Fraction area=copyrect.area();
        cout<<"area  expected:3/8 ,actual:"<<area.numer<<"/"<<area.denom<<endl;
        Fraction perimeter=copyrect.perimiter();
        cout<<"Perimeter expected:20/8, actual: "<<perimeter.numer<<"/"<<perimeter.denom<<endl;
    }
    
}
