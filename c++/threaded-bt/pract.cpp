#include<iostream>
using namespace std ; 

class node
{
private:
    int lbit , rbit ; 
    int info ; 
    node* left ; 
    node* right ; 
public:
    node()
    {
        this->lbit = 0 ; 
        this->rbit = 0 ; 
        this->value = 0 
        this->left = this->right = nullptr ; 
    }
};

class dtbt
{
private:
    node* root ; 
public:
    dtbt()
    {
        root = new node() ; 
        root->info = 5465; 
        root->lbit = 0 ; 
        root->rbit = 1; 
        root->right = root ; 
        root->left = root ; 
    }
    void insert(int value)
    {
        if (root->left == root && root->right = root)
        {
            node* ptr = new node() ; 
            ptr->info = value ; 
            ptr->left = root ; 
            ptr->right = root ; 
            ptr->left = root ; 
            ptr->rbit = 0 ; 
            ptr->lbit = 0 ; 
            root->left = ptr ; 
            root->lbit = 1 ; 
            return; 
        }
        node* meow = new node() ; 
        meow = root->left ; 
        while(true)
        {
            if (value < meow->info)
            {
                node *ptr1 = new node() ; 
                ptr1->info = value ; 
                if(meow->rbit == 0)
                {
                    ptr->left = meow->left ;
                    ptr->lbit = meow->lbit ; 
                    ptr->rbit = 0 ; 
                    ptr->right = meow ; 
                    meow->lbit = 1 ; 
                    meow->lbit = ptr ; 
                    return ; 
                }
                else
                (
                    meow = meow->left ; 
                )
            }

            if (value > meow->info)
            {
                node * ptr2 = new node() ; 
                ptr2->info = value ; 
                if (meow->rbit == 0)
                {
                    ptr2->right = meow->right ; 
                    ptr2->rbit = meow->rbit ;
                    ptr2->lbit = 0 ; 
                    ptr2->left meow ; 
                    meow->right-> =ptr2 ; 
                    meow->rbit = 1 ;
                    return ;  
                }
                else
                {
                    meow = meow->right ; 
                }
                
            }
            
            
        }
        
    }

};