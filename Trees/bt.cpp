#include<iostream>
using namespace std ; 

class node 
{
    public:
    int data ; 
    node * left ; 
    node * right ; 
    node(int a)
    {
        this->data = a ; 
        left = nullptr ; 
        right = nullptr; 
    }
};

class bt 
{
public:
    int a = -1 ; 
    node* build_tree(int nodes[])
    { 
        a++ ; 
         
        if(nodes[a] == -1 )
        {
            return NULL ; 
        }
        node* newnode = new node(nodes[a]) ; 
        newnode->left = build_tree(nodes);
        newnode->right = build_tree(nodes) ; 
        return newnode ; 
    }
};
int main()
{
    bt b1 ; 
    int nodes[14] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,-1} ; 
    cout<<b1.build_tree(nodes)->data ; 
    return 0 ; 
}