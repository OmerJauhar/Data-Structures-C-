#include<iostream>
using namespace std ; 
class node 
{
public:
    int data ; 
    node * left ; 
    node * right; 
    node()
    {
        this->data = 0 ;
        this->left = nullptr ; 
        this->right = nullptr ; 
    }
    node(int data )
    {
        this->data = data ; 
        this->left = nullptr ; 
        this->right = nullptr ; 
    }

}; 

int countNode(node *head)
{
    int counter = 0 ; 
    node* temp = head ; 
    while(temp->next!=nullptr)
    {
        count++ ; 
        temp = temp->next ; 
    }
    return counter ; 
}