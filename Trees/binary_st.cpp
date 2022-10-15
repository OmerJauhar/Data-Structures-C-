#include<iostream>
using  namespace std ;
class bst ; 
class node
{
private:
    friend class bst ; 
    int info ; 
    node* left ; 
    node* right ; 
public:
    node()
    {
        this->left = nullptr ; 
        this->right = nullptr ; 
    }
    node(int a)
    {
        this->info = a ; 
        this->left = nullptr ; 
        this->right = nullptr ; 
    }
    ~node()
    {
        delete left , right ; 
    }

} ;

class bst
{
private: 
    node* temp ; 
public: 
    void inorder_print(node* root)
    {
        if (!root)
        {
            return ; 
        }
        inorder_print(root->left);
        cout<<root->info <<endl ; 
        inorder_print(root->right) ; 
        return ;
    }
    node* insert(node* root,int value)
    {
        if (root == nullptr )
        {
            return new node(value) ;   
        }
        if (root->info < value )
        {
            root->right = insert(root->right , value) ; 
        }
        else if (root->info > value)
        {
            root->left = insert(root->left, value ) ; 
        }
        /*if non of the conditions are executed than it means that there is a dublicate */
        return root  ; 
    }
};

int main()
{
    bst b1 ; 
    node* root = nullptr ; 
    root = b1.insert(root,10) ; 
    b1.insert(root , 20) ; 
    b1.insert(root , 30) ; 
    b1.insert(root , 50) ; 
    b1.insert(root , 05) ;
    b1.insert(root , 07) ;  
    b1.inorder_print(root) ; 
    return 0 ; 
}