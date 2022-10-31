#include<iostream>
#include<iomanip>
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
	node* InOrderTraversal( node* root);
	node* PreOrderTraversal( node* root);
	node* PostOrderTraversal( node* root);
	node* FindMax(node* root);
    void print_level_order(node* root)
    {
        int a = max_deapth(root) ; 
        for (int i = 0; i < a +1; i++)
        {
            printcurrentlevel(root , i);
            cout<<endl ;  
        }
        
    }
    void printcurrentlevel(node* root , int level)
    {
        if (root == nullptr)
        {
            return ; 
        }
        else if (level == 1 )
        {
            cout<<root->data<<" " ;
        }
        else if (level>1)
        {
            printcurrentlevel(root->left, level -1) ; 
            printcurrentlevel(root->right , level -1) ; 
        }
        
        
        
    }
    
public:
    void PRINTLEVELORDER()
    {
        print_level_order(this->root) ; 
    }
    int max_deapth(node* root) ; 
	BinarySearchTree(){
		root= NULL;
	}
	void	Insert(int val){
		
   	Insert(this->root,  val);
   }
   
    void	Delete(int val){
   Delete(this->root, val);
   }
    int MAX_DEAPTH()
    {
        return (max_deapth(this->root)) ; 
    } 
	void InOrderTraversal(){
        InOrderTraversal( this->root);
	}
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
	}
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
	}
    node* buildtree (int preorder[], int inorder[] , int start , int end) ; 
    int search(int inorder[], int start , int end , int curr) ; 
    {
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == curr)
            {
                return i ; 
            }
            
        }
        
    }
};
int  search(int inorder[], int start , int end , int curr)
    {
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == curr)
            {
                return i ; 
            }
            
        }
        
    }
node* buildtree (int preorder[], int inorder[] , int start , int end) 
{
    static int idx = 0 ; 
    if (start>end)
    {
        return nullptr ; 
    }
    
    int curr = preorder[idx] ; 
    idx++ ; 
    node* node = new node(curr) ; 
    if (start==end)
    {
        return node ; 
    }
    
    int pos = search(inorder,start , end, curr) ; 
    node->left = buildtree(preorder, inorder , start , pos-1) ; 
    node->right = buildtree(preorder, inorder , pos+1 , end ); 
}
int BinarySearchTree::max_deapth(node* temp)
{
    if (temp==nullptr)
    {
        return 0 ; 
    }
    else
    {
        int ld = max_deapth(temp->left) ;
        int rd = max_deapth(temp->right) ;
        if (ld>rd)
        {
            return ld+ 1 ; 
        }
        else
        {
            return rd + 1 ; 
        }
         
    }
    
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
//	node * r= root1;
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
            node* temp = FindMax(root->right);
            root->data = temp->data;
            r->right = Delete(root->right, temp->data);
        }
    }
    return r;
}
node * BinarySearchTree::InOrderTraversal( node* r){
	 if (r == NULL)
        return NULL;
    //first recur on left child 
    InOrderTraversal(r->left);
   //then print the data of node 
    cout << " "<< r->data << " -> ";
  // now recur on right child 
    InOrderTraversal(r->right);
}

node* BinarySearchTree::FindMax(node* r){	
	while(r->left!=NULL){
		r= r->left;
	}
	return r;	
}
node* BinarySearchTree::PreOrderTraversal( node* r){
	 if (r == NULL)
        return NULL;
    
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);	
}
node* BinarySearchTree::PostOrderTraversal( node* r){
	 if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);	
    cout << " "<< r->data << " -> ";
}
int main (){
	BinarySearchTree tree1, tree2;
  	tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
	// tree1.Delete(10);
    cout<<tree1.MAX_DEAPTH() ; 
	cout<<"In Order Print (left--Root--Right)"<<endl;
	tree1.InOrderTraversal();
	cout<<"\n-----------------------"<<endl;
	cout<<"Pre Order Print (Root--left--Right)"<<endl;
	tree1.PreOrderTraversal();	
	cout<<"\n-----------------------"<<endl;
	cout<<"Post Order Print (left--Right--Root)"<<endl;
	tree1.PostOrderTraversal();

    cout<<"\nThe height of the tree is "<<tree1.MAX_DEAPTH()<<endl  ;

    cout<<"Level order print"<<endl ; 
    tree1.PRINTLEVELORDER() ;  

    
	return 0;
}

