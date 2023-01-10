#include<iostream>
using namespace std ; 
class avl ; 
class node
{
private:
    friend class avl;
    int info ; 
    node* left ; 
    node* right ; 
    int height ;
public:
    node(int n)
    {
        this->info = n ; 
        left = nullptr ; 
        right = nullptr ;
        this->height = 0 ;  
    }
};
class avl
{
private:
    node* root ; 
    node* srr(node* &t)
    {
        node* u = t->left ;
        t->left = u->right ; 
        u->right  = t ;
        t->height = max(height(t->left),height(t->right)) + 1 ; 
        u->height = max(height(u->left),height(u->right)) + 1; 
        return u ; 
    }
    node* slr(node * &t)
    {
        node* u = t->right; 
        t->right = u->left ; 
        u->left = t ; 
        t->height = max(height(t->left),height(t->right)) + 1 ; 
        u->height = max(height(u->left),height(u->right)) + 1;
        return u ;  

    }
    node* insert(node* root , int key)
    {
        if (root == nullptr)
        {
            root = new node(key) ; 
        }
        else if (key < root->info)
        {
            root->left = insert(root->left , key) ; 
            int bf = height(root->left) - height(root->right) ; 
            if (bf ==2)
            {
                if (key <root->left->info)
                {
                    root = srr(root) ; 

                }
                else
                {
                    root = dlr(root) ; 
                }
            }
        }
        else if (key >root->info)
        {
            root->right = insert(root->right,key) ; 
            int bf = root->left->height - root->right->height ; 
            if (bf ==-2)
            {
                if (key > root->right ->info)
                {
                    root = slr(root) ; 
                }
                else 
                {
                    root = drl(root) ; 
                }
                
            }
            
        }
        root->height = max(root->left->height,root->right->height) ; 
        return root ;               
    }
    node* deletenode(node* root , int key)
    {
        if (root == nullptr)
        {
            return nullptr ;
        }
        else if (key<root->info)
        {
            root->left = deletenode(root->left,key) ; 
        }
        else if (key > root->info)
        {
            root->right = deletenode(root->right , key) ; 
        }
        else
        {
            if (root->left  == nullptr && root->right == nullptr)
            {
                delete root ; 
                root = nullptr ; 
                return nullptr ;  
            }
            else if (root->left == nullptr && root->right !=nullptr)
            {
                node* temp = root->right ; 
                delete root ; 
                // return temp ;
            }
            else if (root->right == nullptr && root->left !=nullptr)
            {
                node* temp = root->left ; 
                delete root ;
                // return root ; 
            }
            else
            {
                node* temp = root->right ; 
                while(temp->left!=nullptr)
                {
                    temp = temp->left ; 
                }
                root->info = temp->info ; 
                root->right = deletenode(root->right,temp->info) ; 
            }
            
            
        }
        if (root ==nullptr)
        {
            return root ;
        }
        
        
        
        
    }
    node* drl(node * &t)
    {
        t->right = srr(t->right) ; 
        return slr(t) ; 
    }
    node* dlr(node *&t)
    {
        t->left = slr(t->left) ; 
        return srr(t) ; 
    }
    int height(node* meow)
    {
        if (meow == nullptr)
        {
            return -1 ; 
        }    
        return meow->height ;  
    }
    int treeheight(node* root)
    {
        int lh = 0 ; 
        int rh = 0 ;
        if (root = nullptr)
        {
            return 0 ; 
        }
        else 
        {
            lh = treeheight(root->left) ; 
            rh = treeheight(root->right) ; 
            if (lh>rh)
            {
                return lh+1 ; 
            }
            else 
            {
                return rh + 1 ;
            }
            
        }
        
    }


};


int main()
{
    return 0 ; 
}