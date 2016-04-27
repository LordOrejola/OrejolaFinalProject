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
        char choice;
        cin >> choice;
        if(choice == 'Y'){
            addmanager(name);
        }
    }
    else{
        cout << "Which branch does "<< name << " work for?"<<endl;
        int branch;
        string title;
        cin >> branch;
        cout << "What is "<<name<<"'s job title?"<<endl;
        cin.ignore();
        getline(cin,title);
        node *newEmployee = new node(name,title);
        node *searcher = CEOS[branch-1];
        bool found = false;
        while(!found){
              /*  if(searcher->subordinates.size()==0)
                {
                found = true;
                newEmployee->ranking = searcher->ranking + 1;
                searcher->subordinates.push_back(newEmployee);
                }*/
               // else{
                    cout << "Does "<<name<<" work directly under "<< searcher->name<<"?(Y/N)"<<endl;
                    char choice;
                    cin >> choice;
                    if(choice == 'Y'){
                        newEmployee->ranking = searcher->ranking + 1;
                        searcher->subordinates.push_back(newEmployee);
                        found = true;
                    }
                    else{
                        cout<< "Who is superior to " << name <<"?"<<endl;
                        for(int i = 0; i < searcher->subordinates.size();i++){
                            cout<<searcher->subordinates[i]->name<<endl;
                        }
                        string who;
                        cin.ignore();
                        getline(cin,who);
                        for(int i = 0; i < searcher->subordinates.size();i++){
                            if(who==searcher->subordinates[i]->name){
                                searcher=searcher->subordinates[i];
                            }
                        }
                    }
        }
    }

}

void narytree::printBranch(){
    int branch;
    cout << "Enter the " <<companyname<<" branch."<<endl;
    cin >> branch;
    //cout <<"Name: "<< CEOS[branch-1]->name <<" Title: "<<CEOS[branch-1]->title<<endl;
    printBranch(CEOS[branch-1]);
    cout << "---" <<endl;
    printpeople();
    printpp.clear();
}

void narytree::printBranch(node *Enode){
    if(Enode->subordinates.size()==0){
        printpp.push_back(Enode);
       // cout <<"Rank: "<<Enode->ranking<<" Name: "<< Enode->name <<" Title: "<<Enode->title<<endl;
        return;
    }
    for(int i=0; i< Enode->subordinates.size(); i++){
        bool newpp = true;
        for(int j=0; j<printpp.size();j++)
        {
            if(printpp[j]==Enode){
                newpp = false;
                break;
            }
        }
        if(newpp){
           printpp.push_back(Enode);
        }
        printBranch(Enode->subordinates[i]);
       // cout <<"Rank: "<<Enode->ranking<<" Name: "<< Enode->name <<" Title: "<<Enode->title<<endl;
    }
}

void narytree::printpeople(){
    for(int i = 0; i <printpp.size() ; i++){
        cout <<"Rank: "<<printpp[i]->ranking<<" ";
        for(int j = 1; j<printpp[i]->ranking; j++){
            cout<<"---";
        }
        cout<<" Name: "<< printpp[i]->name <<" Title: "<<printpp[i]->title<<endl;
    }
}

void narytree::printAllbranches(){
    for(int i = 0; i < CEOS.size();i++){
        cout<<"===="<< companyname <<" Branch "<<i+1<<"===="<<endl;
        printBranch(CEOS[i]);
    }
}

