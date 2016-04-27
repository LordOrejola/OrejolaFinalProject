#ifndef NARYTREE_H_INCLUDED
#define NARYTREE_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

struct node{
    string name;
    string title;
    node *superior = NULL;
    int ranking;
    vector<node* > subordinates;
    node(){};
    node(string in_name, string in_title)
    {
        name = in_name;
        title = in_title;
    };

};

class narytree{
    public:
        narytree();
        ~narytree();
        void namecompany(string name);
        string getcompanyname();
        int getnumberofbranches();
        void addmanager(string name);
        void printCEOS();
        void addemployee();
        void printBranch();
        void printAllbranches();
    protected:
    private:
        void printBranch(node *Enode);
        void printpeople();
        int depth;
        string companyname;
        vector<node* > CEOS;
        vector<node* > printpp;

};
#endif // NARYTREE_H_INCLUDED
