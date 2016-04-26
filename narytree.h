#ifndef NARYTREE_H_INCLUDED
#define NARYTREE_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

struct node{
    string name;
    node *superior = NULL;
    int ranking;
    vector<node* > subordinates;
    node(){};
    node(string in_name)
    {
        name = in_name;
    };

};

class narytree{
    public:
        narytree();
        ~narytree();
        void addCEO(string name);
        void printCEOS();
        void addemployee(string name);
    protected:
    private:
        int depth;
        vector<node* > CEOS;

};
#endif // NARYTREE_H_INCLUDED
