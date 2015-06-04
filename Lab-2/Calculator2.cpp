// Lab 2C,Using Templated Classes
// Programmer: Haris Hanif (1392603)
// Editor(s) used: XCode
// Compiler(s) used: XCode
#include<iostream>
#include<string>
#include<stack>
using namespace std;

#include<cstdlib>

int main()
{
    
    // print my name and this assignment's title
    cout << "Lab 2C, Using Templated Classes (1392603)\n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: XCode\n";
    cout << "Compiler(s) used: XCode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    stack<float>s;
    string buf;
    cout<<"Enter a value followed by Enter and Q or q to exit: "<<endl;
    while(true)
    {
        cout<<"Enter: ";
        for(stack<float>copy =s;!copy.empty();copy.pop())
        {
            cout<<copy.top()<<" ";
        }
        getline(cin,buf);
        if(buf =="Q" ||buf =="q")break;
        
        if(buf[0]=='+')
        {
            if(s.size()<2)cout<<"Error needs two variables"<<endl;
            else
            {
                float a,b,result;
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                result=a+b;
                s.push(result);
            }
        }
        else if(buf[0]=='-')
        {
            if(s.size()<2)cout<<"Error needs two variables"<<endl;
            else
            {
                float a,b,result;
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                result=b-a;
                s.push(result);
            }
        }
        else if(buf[0]=='*')
        {
            if(s.size()<2)cout<<"Error needs two variables"<<endl;
            else
            {
                float a,b,result;
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                result=b*a;
                s.push(result);
            }
        }
        else if(buf[0]=='/')
        {
            if(s.size()<2)cout<<"error needs two variables"<<endl;
            else
            {
                float a,b,result;
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                result=b/a;
                s.push(result);
            }
        }
        else   
        {
            s.push(atof(buf.c_str())); 
        }
    }
}
