// Lab 3c, Rectangle Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
using namespace std;

#include <cassert>

#include "Rectangle.h"
#include "Rectangle.h" //ifndef testing
#include "Fraction.h"


int main(int argc, const char * argv[]) {
    
    // print my name and this assignment's title
    cout << "Lab 3c, Rectangle Program \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    //Testing
    Fraction Rectangle_Width={1,2};
    Fraction Rectangle_Length={1,4};
    Rectangle<Fraction>Fraction_Rectangle(Rectangle_Width,Rectangle_Length);
    
    cout<<"\n\nThe value of the Fraction Rectangle should be Width: 1/2 and Length: 1/4"<<endl;
    cout<<"Should get a perimiter of 12/8 and an area of 1/8."<<endl;
    cout<<"The width should also be larger than length."<<endl;
    
    Fraction Perimeter_1 = Fraction_Rectangle.perimiter();
    cout<<"The actual perimiter of the fraction is: ";
    cout<<Perimeter_1.numer;
    cout<<"/";
    cout<<Perimeter_1.denom;
    cout<<endl;
    assert(Perimeter_1.numer==12 && Perimeter_1.denom==8);
    
    Fraction Area_1 = Fraction_Rectangle.area();
    cout<<"The actual area of the fraction rectangle is: ";
    cout<<Area_1.numer;
    cout<<"/";
    cout<<Area_1.denom;
    cout<<endl;
    assert(Area_1.numer==1 && Area_1.denom==8);
    
    cout<<"Now testing if the length is greater than width. "<<endl;
    cout<<"It is: "<<endl;
    assert(Fraction_Rectangle.Compare() == false);
    if(Fraction_Rectangle.Compare() == true)
        cout<<" greater than the width."<<endl;
    else
        cout<<" less than the width."<<endl;
    
    //More testing
    
    cout<<"We are now testing float values."<<endl;
    cout<<"Length will be 10.5 and Width will be 12.5."<<endl;
    cout<<"Expected values for Perimiter are: 46 & Area are: 131.25. "<<endl;
    cout<<"The Length should also be greater than the width."<<endl;
    Rectangle<float> Float_Rectangle(10.5,12.5);
    cout<<"The actual Perimiter is: ";
    cout<<Float_Rectangle.perimiter()<<endl;
    cout<<".The actual Area is: ";
    cout<<Float_Rectangle.area()<<endl;
    assert(Float_Rectangle.perimiter() == 46 && Float_Rectangle.area()== 131.25);
    
    cout<<"Again testing if the length is greater than width. "<<endl;
    cout<<"It is: "<<endl;
    assert(Float_Rectangle.Compare() == true);
    if(Float_Rectangle.Compare() == true)
        cout<<" greater than the width."<<endl;
    else
        cout<<" less than the width."<<endl;
    
    
    //object copy testing
    
    cout<<"\n\nWe will now do object copy testing on the Fraction"<<endl;
    const Rectangle<Fraction> copy = Fraction_Rectangle;
    cout<<"We should expect the same values as before"<<endl;
    Fraction copyPerimiter = copy.perimiter();
    Fraction copyArea = copy.area();
    
    assert(copyPerimiter.numer == Perimeter_1.numer && copyPerimiter.denom == copyPerimiter.denom);
    assert(copyArea.numer == Area_1.numer && copyArea.denom == Area_1.denom);
    cout<<"Should get a perimiter of 12/8 and an area of 1/8."<<endl;

    cout<<"The copy perimiter is: ";
    cout<<copyPerimiter.numer;
    cout<<"/";
    cout<<copyPerimiter.denom;
    cout<< " & The area is: ";
    cout<<copyArea.numer;
    cout<<"/";
    cout<<copyArea.denom<<endl;
    cout<<"Again testing if the length is greater than width. "<<endl;
    cout<<"It is: "<<endl;
    assert(Fraction_Rectangle.Compare() == copy.Compare());
    if(copy.Compare() == true)
        cout<<" greater than the width."<<endl;
    else
        cout<<" less than the width."<<endl;
    
    
    //object assignment testing
    
    cout<<"Now do object assignment testing"<<endl;
    Fraction x = {2,2};
    Fraction y = {4,4};
    Rectangle<Fraction> copy2(x,y); copy2 = Fraction_Rectangle;
    
    cout<<"Should be expecting the same values as before"<<endl;
    Fraction copyPerimeter2 = copy2.perimiter();
    Fraction copyArea2 = copy2.area();
    
    assert(copyPerimeter2.numer == Perimeter_1.numer && copyPerimeter2.denom == Perimeter_1.denom);
    assert(copyArea2.numer == Area_1.numer && copyArea.denom == Area_1.denom);
    cout<<"Should get a perimiter of 12/8 and an area of 1/8."<<endl;

    cout<<"The copy perimiter is: ";
    cout<<copyPerimeter2.numer;
    cout<<"/"<<copyPerimeter2.denom;
    cout<< " and the area is: ";
    cout<<copyArea2.numer;
    cout<<"/"<<copyArea2.denom;
    cout<<endl;
    cout<<"Again testing if the length is greater than width. "<<endl;
    cout<<"It is: "<<endl;
    assert(Fraction_Rectangle.Compare() == copy2.Compare());
    if(copy2.Compare() == true)
        cout<<" greater than the width."<<endl;
    else
        cout<<" less than the width."<<endl;
}
