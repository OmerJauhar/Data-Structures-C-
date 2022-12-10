#include<iostream>
using namespace std ; 

class node
{
public:
    int info ;
    node* left ; 
    node* right ; 
    node()
    {
        this->info = 0 ; 
        left = nullptr ; 
        right = nullptr ; 
    }
    node(int n)
    {
        this->info = n ; 
        left = nullptr ; 
        right = nullptr ; 
    }
};
class bst 
{
private:
    node head ; 
    node temp ; 
public:
    bst()
    {
        head = nullptr ; 
        temp = nullptr ; 
    }
    node* insert(node * root, int key)
    {
        if (root == nullptr )
        {
            return new node(key) ; 
        }
        if (key<root->info)
        {
            root->left = insert(root->left,key) ; 
        }
        else if (key > root->info)
        {
            root->right = insert(root->right , key) ; 
        }
        return root ;   
    }

    void deletefunction(node* root, int key)
    {
        if (root == nullptr)
        {
            return NULL ; 
        }
        else if (key < root->info)
        {
            root->left = deletefunction(root->left,int key) ; 
        }
        else if (key > root->info)
        {
            root->right = deletefunction(root->right,int key) ; 
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root ; 
                root = nullptr ; 
                return root ;                 
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                node* temp = root->right ;
                free(root) ; 
                delete temp ;  
            }
            else if (root->right == nullptr && root->left!= nullptr)
            {
                node* temp = root->left ;
                free(root) ; 
                delete temp ;  
            }
            else 
            {
                node * temp = findmax(root->left) ;
                root->data = temp->data ; 
                root->left = deletefunction(root->left , temp->data) ;  
            }
        }    
        return root ;     
         
        
        
    }
    ~bst()
    {
        delete head ; 
        delete temp ; 
    }

} 



int main()
{
    return 0 ; 
}