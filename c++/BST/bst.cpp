// Binary Search Tree Implementation..  
#include<iostream>

using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data=  data;
        left= right= NULL;
        }
    };
   
class BinarySearchTree{
    private:
    node* root;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    void InOrderTraversal( node* root);
    void PreOrderTraversal( node* root);
    void PostOrderTraversal( node* root);
    int functionmeow(node* root) ; 
    node* FindMax(node* root);
    public:
    BinarySearchTree(){
        root= NULL;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   
    void    Delete(int val){
   Delete(this->root, val);
   }
    void InOrderTraversal(){
        InOrderTraversal( this->root);
    }
    int FUNCTIONMEOW()
    {
       return  functionmeow(this->root) ; 
    }
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
    }
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
    }
};
int main (){
    BinarySearchTree tree1, tree2;
      tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
    tree1.Delete(10);
    cout<<"In Order Print (left--Root--Right)"<<endl;
    tree1.InOrderTraversal();
    cout<<"\n-----------------------"<<endl;
    cout<<"Pre Order Print (Root--left--Right)"<<endl;
    tree1.PreOrderTraversal();    
    cout<<"\n-----------------------"<<endl;
    cout<<"Post Order Print (left--Right--Root)"<<endl;
    tree1.PostOrderTraversal();
    cout<<endl; 
    cout<<tree1.FUNCTIONMEOW() ; 

    
    return 0;
}
int BinarySearchTree::functionmeow(node* root)
{
    int meow = 0   ; 
    if (root==nullptr)
    {
        return 0 ; 
    }
    if (root->left!=nullptr && root->right == nullptr)
    {
        meow++ ;    
        cout<<meow<<endl ;  
    }
    else if (root->left == nullptr && root->right !=nullptr)
    {
        meow++ ; 
        cout<<meow<<endl ; 
    }
    return meow + functionmeow(root->left) + functionmeow(root->right) ;   
}
node* BinarySearchTree::Insert(node* r, int val ){
 if (r==NULL)
    {
        node* t= new node(val);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}
node * BinarySearchTree::Delete(node* r, int data)
{
//    node * r= root1;
    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        //No child
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        //One child on left
        else if(r->right == NULL)
        {
            node* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
void BinarySearchTree::InOrderTraversal( node* r){ 
     if (r == NULL)
        return ;
    //first recur on left child
    InOrderTraversal(r->left);
    cout<<r->data<<"->" ; 
   //then print the data of node
//    *(arry + meow) = r->data;
    // meow ++ ; 
  // now recur on right child
    InOrderTraversal(r->right);
}

node* BinarySearchTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}
void BinarySearchTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return ;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
void BinarySearchTree::PostOrderTraversal( node* r){
     if (r == NULL)
        return ;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
    
}