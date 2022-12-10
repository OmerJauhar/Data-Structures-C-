// Binary Search Tree Implementation..
#include<iostream>
using namespace std;
class node
{
public:
int data;
node* left, *right;
node(int data)
{
this->data = data;
left = right = NULL;
}
};
class BinarySearchTree
{
private:
node* Insert(node* root, int val);
node* DeleteNodeInBST(node* root, int data);
void InOrderTraversal(node* root);
void PreOrderTraversal(node* root);
void PostOrderTraversal(node* root);
void Merge(node* r1, node* r2);
node* FindMax(node* root);
int leafCount(node* root);
int treeHeight(node* root);
public:

node* root;
BinarySearchTree()
{
root = NULL;
}
int count = 0;
void countNode(node* r)
{
if (r == NULL)
return ;
count++;
countNode(r->left);
countNode(r->right);
}
int x = 1;
int y = 1;
void Odd(node* r, int count)
{
if (r == NULL)
return ;
Odd(r->left, count);
if (x == count)
{
cout << "Mode: " << r->data;
}
x++;
Odd(r->right, count);
}
int sum = 0;
void Even(node* r, int count)
{
if (r == NULL)
return ;
Even(r->left, count);
if (y == count)
{
sum = sum + r->data;
}
if (y == count + 1)
{
sum = sum + r->data;
cout << "Mode: " << sum / 2;
}
y++;
Even(r->right, count);
}
void Mode()
{
countNode(this->root);
if (count % 2 == 0)
{
Even(this->root, count / 2);
}
else
{
Odd(this->root, (count + 1) / 2);
}
}
void Insert(int val)
{
Insert(this->root, val);
}
void Delete(int val)
{
DeleteNodeInBST(this->root, val);
}
void InOrderTraversal()
{
InOrderTraversal(this->root);
}
void PreOrderTraversal()
{
PreOrderTraversal(this->root);
}
void PostOrderTraversal()
{
PostOrderTraversal(this->root);
}
void Merge(BinarySearchTree bst1, BinarySearchTree bst2)
{
Merge(bst1.root, bst2.root);
}
void FindMax()
{
FindMax(this->root);
}
int leafCount()
{
return leafCount(this->root);
}
int treeHeight()
{
return treeHeight(this->root);
}
int getCount()
{
return count;
}
};
int main()
{
BinarySearchTree tree1, tree2;
tree1.Insert(6);
tree1.Insert(3);
tree1.Insert(4);
tree1.Insert(8);
tree1.Insert(9);
// tree1.Insert(2);
tree1.Mode();
return 0;
}
node* BinarySearchTree::FindMax(node* r)
{
while (r->right != NULL)
{
r = r->right;
}
return r;
}
node* BinarySearchTree::Insert(node* r, int val)
{
if (r == NULL)
{
node* t = new node(val);
if (r == root)
root = r = t;
else
r = t;
return r;
}
// else if (r->data== val){
// //cout<<"Duplicate Record "<<val;
// return r;
// }
else if (val < r->data)
{
r->left = Insert(r->left, val);

}
else if (val > r->data)
{
r->right = Insert(r->right, val);

}
return r ; 
}
node* BinarySearchTree::DeleteNodeInBST(node* root, int data)
{
if (root == NULL)
return root;
else if (data < root->data)
root->left = DeleteNodeInBST(root->left, data);
else if (data > root->data)
root->right = DeleteNodeInBST(root->right, data);
else
{
//No child
if (root->right == NULL && root->left == NULL)
{
delete root;
root = NULL;
return root;
}
//One child on left
else if (root->right == NULL)
{
node* temp = root;
root = root->left;
delete temp;
}
//One child on right
else if (root->left == NULL)
{
node* temp = root;
root = root->right;
delete temp;
}
//two child
else
{
node* temp = FindMax(root->left);
root->data = temp->data;
root->left = DeleteNodeInBST(root->left, temp->data);
}
}
return root;
}
void BinarySearchTree::InOrderTraversal(node* r)
{
if (r == NULL)
return ;
/* first recur on left child */
InOrderTraversal(r->left);
/* then print the data of node */
cout << " " << r->data << " -> ";
/* now recur on right child */
InOrderTraversal(r->right);
}
void BinarySearchTree::PreOrderTraversal(node* r)
{
if (r == NULL)
return;
cout << " " << r->data << " -> ";
PreOrderTraversal(r->left);
PreOrderTraversal(r->right);
}
void BinarySearchTree::PostOrderTraversal(node* r)
{
if (r == NULL)
return ;
PostOrderTraversal(r->left);
PostOrderTraversal(r->right);
cout << " " << r->data << " -> ";
}
int BinarySearchTree::leafCount(node* r)
{
int static count= 0;
if (r == NULL)
return 0;
else if (r->left == NULL && r->right == NULL)
return 1;
return count + leafCount(r->left) + leafCount(r->right);
}
int BinarySearchTree::treeHeight(node* root)
{
int static l_height= 0;
int static r_height= 0;
if (root == NULL)
return -1;
else
{
l_height = treeHeight(root->left);
r_height = treeHeight(root->right);
if (l_height > r_height)
return (l_height + 1);
else
return (r_height + 1);
}
}
// This method will merge tree1 into tree2
void BinarySearchTree::Merge(node* r1, node* r2)
{
if (r1 == NULL)
return ;
/* first recur on left child */
Merge(r1->left, r2);
Insert(r2, r1->data);
/* now recur on right child */
Merge(r1->right, r2);
}