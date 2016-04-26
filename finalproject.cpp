#include <iostream>
#include "narytree.h"
#include <sstream>
using namespace std;
// Final Project: CSCI 2270
// Oliver Orejola

void printMenuAndGetInput(int &userinput,narytree input)
{
    cout <<" "<<endl;
	cout << "======"<< input.getcompanyname() <<" Menu======" << endl;
	cout << "There are " << input.getnumberofbranches()<<" "<<input.getcompanyname()<< " Branches." <<endl;
	cout << "   "<<"1. Add Branch Manager" <<endl;
	cout << "   "<<"2. Print Branch Managers names" << endl;
	cout << "   "<<"3. Add employee" << endl;
	cout << "   "<<"100. Quit" << endl;

	cin >> userinput;
}

void namethecompany(narytree &input){
    cout << "Hello User!"<<endl;
    cout << "What would you like to name the company?" <<endl;
    string newname;
    getline(cin,newname);
    input.namecompany(newname);
    cout << "Congratulations! You have named the company "<< input.getcompanyname()<<"!"<<endl;
}

int main()
{
    int input;
    narytree tree;
    namethecompany(tree);
    cout <<tree.getcompanyname()<<endl;
    while(input!=100){
        printMenuAndGetInput(input,tree);
        if(input==1){
            string CEOname;
            cin.ignore();
            cout << "Enter the Branch Manager's name:" << endl;
            getline(cin,CEOname);
            tree.addCEO(CEOname);
        }
        else if(input==2){
            tree.printCEOS();
        }
        else if(input==3){
           /* string Employeename;
            cout << "Enter a new employee's name:" << endl;
            cin.ignore();
            getline(cin,Employeename);
            tree.addemployee(Employeename);*/
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
