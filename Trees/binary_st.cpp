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

    node* pre_order_successor(node* temp )
    {
        node* curr = temp ; 
        while (curr && curr->left != nullptr)
        {
            curr = curr->left ; 
        }
        return curr ;
        
    }
    node* delete_node(node* root , int value)
    {
        if(root == nullptr)
        {
            return root ; 
        }
        if (value < root->info ) 
        {
            root->left = delete_node(root->left , value) ; 
        }
        else if(value > root->info )
        {
            root->right = delete_node(root->right , value) ; 
        }
        else
        {
            if (root->right == nullptr && root->left == nullptr)
            {
                return nullptr ; 
            }
            else if (root->right == nullptr)
            {
                node* temp  = root->left ; 
                free(root) ; 
                return temp ; 
            }
            else if (root->left = nullptr)
            {
                node* temp = root->right ; 
                free(root) ; 
                return temp ; 
            }
            else
            {
                node* meow = pre_order_successor(root->right) ; 
                root->info = temp->info ; 

                root->right = delete_node(root->right , temp->info ) ; 
            }
            
            
            
        }
        return root ; 
        
        
        
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
    cout<<"meow"<<endl ; 
    b1.delete_node(root,50) ; 
    b1.inorder_print(root) ; 
    return 0 ; 
}