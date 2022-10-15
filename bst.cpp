#include<iostream>
using namespace std ; 
class bst ; 

class node
{
private:
    friend class bst ; 
    int data ; 
    node *left ; 
    node *right ; 
    node()
    {
        this->left  = nullptr ; 
        this->right = nullptr ; 
    }
    node(int a)
    {
        this->data = a ; 
        this->left  = nullptr ; 
        this->right = nullptr ; 
    }
};

class bst 
{
private:
    node* temp ; 

public:
    int number ; 
    node* root ;
    bst()
    {
        temp = root = nullptr ; 
    }
    void bst_insert()
    {

        if (root == nullptr)
        { 
            temp = new node(number);
            root = temp ; 
        }
        if(temp->info == number )
        {
            cout<<"Dublicates are not allowed "<<endl ; 
            return ; 
        }
        if (temp->data > number)
        {
            if (temp->left != nullptr)
            {
                bst(temp->left) ; 
                return ; 
            }
            else
            {
                temp->left = new node(number) ; 
                return ; 
            } 
        }
        if (temp->data < number)
        {
            bst_insert(temp->right) ; 
            return ; 
        }
        else
        {
            temp->right = new node(number) ; 
            return ;
        }   
    }
};

int main()
{
    return 0 ; 
}