#include <iostream>
#include <vector>
#include "narytree.h"
#include <string.h>
#include <sstream>

using namespace std;
narytree::narytree(){};
narytree::~narytree(){};

void narytree::addCEO(string CEOname){
    if(CEOname.empty()){
        cout<<"Nothing Entered. Please Enter a CEO Name"<<endl;
    }
    else{
        node *newCEO = new node(CEOname);
        newCEO->ranking=1;
        CEOS.push_back(newCEO);
    }
};

void narytree::printCEOS(){
    if(CEOS.size()==0){
        cout<< "There are no CEOS in the company" <<endl;
    }
    else{
        cout<< "The CEOS are:" <<endl;
        for(int i=0; i<CEOS.size();i++){
            cout<< CEOS[i]->name <<endl;
        }
    }
}



void narytree::addemployee(string name){
    if(CEOS.size()==0){
        cout<< "There are no CEOS in the company. Would you like to make "<< name <<" a CEO? (Y/N)"<<endl;
        string choice;
        cin.ignore();
        cin >> choice;
        if(choice == "Y"){
            addCEO(name);
        }
    }
    else{
        string LIST;
        vector<string> Hierarchy;
        cout << "Write out the hierarchy for delimited by"<< '>' <<endl;
        getline(cin,LIST);
        istringstream ss(LIST);
        string token;
        while(getline(ss,token,'>')){
            Hierarchy.push_back(token);
        }
        node *walker;
        for(int j=0; j<CEOS.size();j++){
            if(CEOS[j]->name==Hierarchy.front()){
                walker=CEOS[j];
                break;
            }
        }
        for(int i=1; i<Hierarchy.size();i++){
            for(int k=0; k < walker->subordinates.size(); k++){
                if(walker->subordinates[k]->name==Hierarchy[i]){
                    break;
                }
            }

        }

    }

}
