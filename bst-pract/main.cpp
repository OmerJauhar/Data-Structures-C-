#include<iostream>
using namespace std ; 

class bst ; 
class node
{
private:
    friend class bst ;
    int info ; 
    node* left ;
    node* right ;  
public:
    node(int n)
    {
        this->info = n ; 
        left  = nullptr ;
        right = nullptr ; 
    }
};

class bst
{
private:
    node* root ;
public:
 
    void INSERT(int key)
    {
         insert(this->root , key) ; 
    }
    node* DELETE(int key)
    {
        return deletefunction(this->root , key) ; 
    }
    node* insert(node* r , int key)
    {
   if (r==NULL)
    {
        node* t= new node(key);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->info== key){
        cout<<"Record already exist"<<key;
    }
    else if (key < r->info) // insert on left s
    r->left = insert(r->left , key );
    else if (key > r->info)
        r->right= insert( r->right,key);
    return r;

    }
    node* deletefunction(node* root , int key)
    {
        if (root== nullptr)
        {
            return nullptr ; 
        }
        else if (key < root->info)
        {
            root->left = deletefunction(root->left , key) ; 
        }
        else if (key > root->info)
        {
            root->right = deletefunction(root->right ,key) ; 
        }
        else 
        {
            if (root->left == nullptr && root->right ==nullptr)
            {
                return nullptr ; 
            }
            else if (root->left == nullptr && root->right!=nullptr)
            {
                node* temp = root->right ; 
                free(root) ; 
                return temp ; 
            }
            else if (root->right == nullptr && root->left !=nullptr)
            {
                node* temp = root->left ; 
                free(root) ; 
                return temp ; 
            }
            else 
            {
                node* meow = root->right ; 
                while(meow->left !=nullptr)
                {
                    meow = meow->left ; 
                }
                root->info = meow->info ; 
                root->right = deletefunction(root->right,meow->info) ; 
            }
            return root ; 
        }
        }
        void inorder(node* root)
        {
            if (root==nullptr)
            {
                return ;
            }
            if (root->left !=nullptr)
            {
                inorder(root->left ) ;
            }
             
            cout<<root->info<<" -> " ; 
            if (root->right !=nullptr)
            {
                inorder(root->right) ; 
            }
            
            
        }
        void INORDER()
        {
            inorder(this->root) ; 
        }
};

int main()
{
    bst b1 ; 
    b1.INSERT(15) ; 
    b1.INSERT(25) ; 
    b1.INSERT(55);
    b1.INORDER() ; 
    b1.DELETE(15);


    return 0 ; 
}