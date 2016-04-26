#include <iostream>
#include "narytree.h"
#include <sstream>
using namespace std;
// Final Project: CSCI 2270
// Oliver Orejola

void printMenuAndGetInput(int &userinput)
{
	cout << "======Main Menu======" << endl;
	cout << "1. Add CEO" << endl;
	cout << "2. Print CEOS names" << endl;
	cout << "3. Add employee" << endl;
	cout << "100. Quit" << endl;

	cin >> userinput;
}

int main()
{
    int input;
    narytree workertree;
    while(input!=100){
        printMenuAndGetInput(input);
        if(input==1){
            string CEOname;
            cin.ignore();
            cout << "Enter a CEOS name:" << endl;
            getline(cin,CEOname);
            workertree.addCEO(CEOname);
        }
        else if(input==2){
            workertree.printCEOS();
        }
        else if(input==3){
            string Employeename;
            cout << "Enter a new employee's name:" << endl;
            cin.ignore();
            getline(cin,Employeename);
            workertree.addemployee(Employeename);
        }
        else if(input == 4){
            string test;
            cin.ignore();
            getline(cin,test);
            istringstream ss(test);
            string token;
            while(getline(ss,token,'>')){
            cout << token <<endl;
            }

        }
    }

    return 0;
}
