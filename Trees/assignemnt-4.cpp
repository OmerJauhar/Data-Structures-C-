#include<iostream>
using namespace std ; 
class bst ; 
class node
{
private:
    friend class bst ; 
    int info ; 
    int count ;
    node* left ;
    node* right  ;   
public: 
    node()
    {
        this->left = this->right = nullptr ; 
        this->info = 0 ; 
        this->count = 0 ; 
    }
    node(int n , int a)
    {
        this->info = n ; 
        this->count = a ; 
        this->left = this->right = nullptr ; 
    }

};


class bst
{
public:
    node* left_most(node* root)
    {
        node* curr = root ;  
        while (curr && curr->left != nullptr)
        {
            curr = curr->left ; 
        }
        return curr ; 
        
        
    }
    node* insert_node(node* root , int value, int count = 0 )
    {
        if (root == nullptr)
        {
            return new node(value,count) ; 
        }
        if (root->info < value)
        {
            root->right = insert_node(root->right,value, count) ; 
        }
        else if (root->info > value )
        {
            root->left  = insert_node(root->left , value , count) ; 
        }
        /* no condition will be exectuted when there is a dublicate*/
        if (root->info ==value)
        {
            root->count ++ ; 
        }
                
        return root ; 
    }
    node * delete_node(node* root , int value)
    {
        if (root == nullptr)
        {
            return root ; 
        }
        if (value < root->info)
        {
            root->left = delete_node(root , value) ;  
        }
        else if (value > root->info)
        {
            root->right = delete_node(root , value) ;  
        }
        else
        {
            if (root->right == nullptr && root->left == nullptr )
            {
                return nullptr ;
            }
            else if (root->left == nullptr)
            {
                node * temp = root->right ; 
                delete root  ;  
                return temp  ; 
            }
            else if (root->right == nullptr)
            {
                node * temp = root->left ; 
                delete root ; 
                return temp  ; 
            }
            node* temp = left_most(root->right); 

            root->info = temp->info ; 
            // root->count = temp->count ; 

            root->right = delete_node(root->right,temp->info) ;    
        }
        return root ; 
        
        
        
    }
    void inorder_print(node* root)
    {
        if(!root)
        {
            return ; 
        }
        else
        {
            inorder_print(root->left); 
            cout<<root->info<<"("<<root->count<<")"<<endl ; 
            inorder_print(root->right) ; 
        }
    }
};



int main()
{
    node* root = nullptr ; 
    bst b1 ; 
    root = b1.insert_node(root , 20 ) ; 
    root = b1.insert_node(root , 15) ; 
    root = b1.insert_node(root , 07) ;
    root = b1.insert_node(root , 16) ;
    root = b1.insert_node(root , 30) ;
    root = b1.insert_node(root , 25) ;
    root = b1.insert_node(root , 35) ;
    root = b1.delete_node(root , 15) ;
 
    b1.inorder_print(root) ; 
    return 0 ; 
}