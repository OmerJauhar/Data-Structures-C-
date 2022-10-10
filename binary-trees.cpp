#include<iostream>
using namespace std  ;
class bt ; 
class node
{
public:
// private:
    int data ; 
    node * left ;
    node * right ;

    friend class bt ; 
public:
    node()
    {
        this->data = 0 ; 
        left  = nullptr ; 
        right = nullptr ; 

    }
    node(int n)
    {
        this->data = n ; 
        left = nullptr ; 
        right = nullptr ; 
    }
};

int main()
{
    node * root = new node(23) ; 
    root->left  = new node(243) ; 
    root->right = new node(8434) ; 
    root->left->left = new node(22) ; 



    return 0 ; 
}