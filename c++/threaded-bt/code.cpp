#include<iostream>
using namespace std ; 

class DTBT ; 

class node
{
private:
    int lbit , rbit ; 
    int value ; 
    friend class DTBT ;
    node* left , * right ; 
public:
    node()
    {
        this->lbit = 0 ; 
        this->rbit = 0 ;
        this->value = 0 ; 
        left = right = nullptr ;  
    }
};

class DTBT 
{
private:
node * root ; 
public:
    DTBT()
    {
        root = new node() ; 
        root ->value = 090 ; 
        //where 090 is dummy value 
        
        root->lbit = 0 ; 
        root->rbit = 1 ; 

        root->right = root ; 
        root->left = root ; 
    }
    void create() ; 
    void search(node * meow) ; 
    void insert(int value) ; 
    void preorder() ; 
    node* preorderSucessor(node *); 
    void inorder() ;  
    node* inordersuccessor(node *) ; 
};

void DTBT ::create()
{
    this->insert(6);
    this->insert(3);
    this->insert(1);
    this->insert(5);
    this->insert(8);
    this->insert(7);
    this->insert(11);
    this->insert(9);
    this->insert(13);
}

void DTBT:: insert(int value)
{
    if (root->left == root && root->right = root)
    {
        node * ptr = new node() ; 
        this->ptr->value = value ;
        ptr->left = root->left ; 
        ptr->lbit = root->lbit ; 
        ptr->rbit = 0 ; 
        ptr->right = root->right ;

        root->left = p ; 
        root->lbit = 1 ; 
        return ;  
    }
    node * meow = new node() ; 
    meow = root ->left ; 
    while (true)
    {
        if(meow->value < value )
        {
            node * ptr = new node() ; 
            ptr ->value = value ; 
            if (meow->rbit == 0)
            {
                ptr ->right = meow->right ; 
                ptr->rbit = meow->rbit ; 
                ptr->lbit = 0 
                ptr->left = meow ; 

                meow->rbit = 1 ; 
                meow->right = ptr ;
                return ; 
            }
            else
            {
                meow = meow->right ; 
            }
            
        }
        if (meow->value > value )
        {
            node * ptr = new node() ; 
            ptr ->value = value ; 
            if (meow->rbit == 0)
            {
                ptr ->left = meow->left ; 
                ptr->lbit = meow->lbit ; 
                ptr ->rbit = 0 
                ptr->right = meow  ; 
                meow->lbit = 1 ; 
                meow->left = ptr ;
                return ;  
                
            }
            else
            {
                meow = meow->left ; 
            }
        }
        
    }
} 
node* DTBT ::search(node* meow)
{
    while(meow = inordersuccessor(meow) != root)
    {

        cout<<meow->value ; 
    }
}
node DTBT::inordersuccessor(node * meow)
{
    if (meow->rbit == 0)
    {
        return meow->right ; 
    }
    else
    {
        meow = meow->right ; 
        while (meow->left == 1)
        {
            meow = meow->left ; 
        }
        return meow ; 
        
    }
}
node* DTBT::preorderSucessor(node * meow1)
{
    if (meow1->lbit = 0)
    {
        return meow->left ; 
    }
    else
    { 
        while(meow->rbit = 0)
        {
            meow = meow->right ; 
        }
        return meow->right ; 
    }
    
}

int main()
{
    return 0 ; 
}