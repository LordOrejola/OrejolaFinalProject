#include <iostream>
#include <vector>
#include "narytree.h"
#include <string.h>
#include <sstream>

using namespace std;
narytree::narytree(){};
narytree::~narytree(){};

void narytree::namecompany(string name){
        companyname = name;
}

string narytree::getcompanyname(){
    return companyname;
}

int narytree::getnumberofbranches(){
    return CEOS.size();
}
void narytree::addmanager(string CEOname){

    if(CEOname.empty()){
        cout<<"Nothing Entered. Please Enter a CEO Name"<<endl;
    }
    else{
        node *newCEO = new node(CEOname,"Manager");
        newCEO->ranking=1;
        CEOS.push_back(newCEO);
    }
};

void narytree::printCEOS(){
    if(CEOS.size()==0){
        cout<< "There are no Managers in the company" <<endl;
    }
    else{
        cout<< "Managers:" <<endl;
        for(int i=0; i<CEOS.size();i++){
            cout<<"Branch "<<i+1<<": "<< CEOS[i]->name <<endl;
        }
    }
}



void narytree::addemployee(){
    string name;
    cout << "Enter a new employee's name:" << endl;
    cin.ignore();
    getline(cin,name);
    if(CEOS.size()==0){
        cout<< "There are no CEOS in the company. Would you like to make "<< name <<" a CEO? (Y/N)"<<endl;
        string choice;
        cin >> choice;
        if(choice == "Y"){
            addmanager(name);
        }
    }
    else{
        cout << "Which branch does "<< name << " work for?"<<endl;
        int branch;
        cin >> branch;
    }

}
