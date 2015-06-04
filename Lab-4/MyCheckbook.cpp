// Lab 4B, Checkbook
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: Xcode

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>

#include "Checkbook.h"
#include "Checkbook.h"

int main(int argc, const char * argv[]) {
    
    // print my name and this assignment's title
    cout << "Lab 4B, Checkbook \n";
    cout << "Programmer: Haris Hanif\n";
    cout << "Editor(s) used: Xcode\n";
    cout << "Compiler(s) used: Xcode\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    int option;
    string buff;
    double balance = 0;
    Checkbook<double> checks(balance);
    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);
    
    while(option !=5){
        cout << "Options:" << endl;
        cout << "1. Get Balance "<< endl;
        cout << "2. Write a Check" << endl;
        cout << "3. Make a Deposit" << endl;
        cout << "4. Output all Checks" << endl;
        cout << "5. Quit" << endl;
        cout << "Please select one of the options between 1-5" << endl;
        cin >> buff;
        option = atof(buff.c_str());
        
        if(option == 1)
        {
            cout<<"Your balance is $"<<checks.getBalance()<<endl;
        }
        
        else if(option == 2 )
        {
            int check;
            cout<<"How much do you want to write a check for?"<<endl;
            cin >> buff;
            check = atof(buff.c_str());
            if(checks.writeCheck(check))
            {
                cout << "A check for $"<<check<< " has been written." << endl;
                cout << "Balance is now $"<<checks.getBalance()<<endl;
            }
            else
                cout<<"Not enough funds to withdraw check." << endl;
                cout << "Current balance is $"<<checks.getBalance()<<endl;
        }
        
        else if(option == 3)
        {
            int Deposit;
            cout<<"Please enter the ammount you want to make a deposit for."<<endl;
            cin >> buff;
            Deposit = atof(buff.c_str());
            checks.deposit(Deposit);
            cout<<"Check successfuly deposited." << endl;
            cout << "New Balance is now $"<<checks.getBalance()<<endl;
        }
        else if(option == 4)
        {
            cout<<"Outputing all checks in the system"<<endl;
            double* allChecks = checks.getChecks();
            for(int i = 0; i < checks.numberOfChecks();i++)
            {
                cout<<"Check #"<<i<<" $"<<allChecks[i]<<endl;
            }
            delete [] allChecks;
            
        }
        
    }
   
}
