#include <assert.h>
#include <iostream>

using namespace std;
class bst{
	private:
		struct node
        {
			int data;
		};
    
		node * arr;
		int size;
		
		int totalItems;
		
	public:
		int a = 0 ;
		int b  = 0 ; 
		bst()
        {
			//this->arr=NULL;
			this->arr=NULL;
			this->size=0;
			this->totalItems=0;
		}
		bst(int _size)
        {
			assert(_size>=1);
		//this->arr=NULL;
			this->a=0;
			this->arr=new node [_size];
			this->size=_size;
			this->totalItems=0;
		//	cout<<"size= "<<size<<endl;
			//initially data of all = 0
			for(int i=0; i<size; i++){
				this->arr[i].data=-1;
			}
			
		}
		
		
		void doubleCapacity() // Increase the size
		{
		if (this->arr==NULL)
		{
			this->arr = new node[1];
			this->size = 1;
			return;
		}
		
		int newCapacity = size*2;
		node *newArr = new node[newCapacity];
		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}
		//if (this->arr!=NULL)
			delete this->arr;
		this->size = newCapacity;
		this->arr = newArr;
		}
	void deletenode(int index , int key)
	{
		if (arr[index].data == -1)
		{
			return ; 
		}
		if (key<arr[index].data)
		{
			deletenode(index*2+1,key) ; 
		}
		else if (key>arr[index].data)
		{
			deletenode(index*2+2,key) ; 
		}
		
		if (arr[index*2+2].data== -1 && arr[index*2+1].data == -1)
		{
			arr[index].data = -1 ; 
			
		}
		
		else if (arr[index*2+1].data== -1 && arr[index*2+2].data != -1)
		{
			
				swap(arr[index],arr[index*2+2]) ; 
				arr[index*2+2].data = -1 ;
			
			 
		}
		else if (arr[index*2+2].data== -1 && arr[index*2+1].data != -1)
		{
			
				swap(arr[index],arr[index*2+1]) ; 
			arr[index*2+1].data = -1 ; 
			
		}
		else
		{
			//when node has two childs 
		}
		return ; 
	}
		

    void insert(int index, int key)
        {
            if (arr[index].data == -1)
            {
                arr[index].data = key;
                totalItems++;
            }

            else if (arr[index].data == key)
                cout << "Duplictae!" << endl;
            else if (key < arr[index].data)
                insert(2 * index + 1, key);
            else if (key > arr[index].data)
                insert(2 * index + 2, key);
            return;
        }

		void search(int index , int key)
		{
			if (arr[index].data == -1)
			{
				return ; 
			}
			if (arr[index].data == key)
			{
				cout<<"Value found at index "<<index<<endl ; 
			}
			
			if (key<arr[index].data)
			{
				search(index*2+1,key) ; 
			}
			else if (key>arr[index].data)
			{
				search(index*2+2,key) ; 
			}
		}
		int height(int index)
		{
			if(arr[index].data == -1)
			{
				return 0 ; 
			}
			int lh  = height(index*2+1) ; 
			int rh = height(index*2+2) ; 
			return max(lh,rh) + 1 ; 
		}
		void leavenodes(int index)
		{
			if (arr[index].data == -1)
			{
				return  ; 
			}
			if (arr[index*2+1].data ==-1 && arr[index*2+2].data == -1 )
			{
				a++ ; 
			}
			leavenodes(index*2+1) ; 
			leavenodes(index*2+2) ; 

			
			
		}
		void nodesatspecificheight(int index ,int  height,int current  )
		{
			if (arr[index].data == -1)
			{
				return ; 
			}
			if (current == height)
			{
				b++; 
			}
			if (index*2+1<totalItems)
			{
				nodesatspecificheight(index*2+1,height,current+1) ;
			}

			if (index*2+2<totalItems)
			{
				nodesatspecificheight(index*2+2,height,current+1) ;
			}
			
			
		}

		void inorder_traversal(int a)
		{
			int li = (a*2) + 1 ; 
			int ri = (a*2) + 2 ; 
			
			if (li <this->totalItems)
			{
				inorder_traversal(li) ; 
			}
			if (true)
			{
				cout<<this->arr[a].data <<" -->"; 
			}
			if (ri<this->totalItems)
			{
				inorder_traversal(ri) ; 
			}
		}

		void preorder_traversal(int a)
		{
			int li = (a*2) + 1 ; 
			int ri = (a*2) + 2 ; 
			if (true)
			{
				cout<<this->arr[a].data <<" -->"; 
			}
			if (li <this->totalItems)
			{
				preorder_traversal(li) ; 
			}
			if (ri<this->totalItems)
			{
				preorder_traversal(ri) ; 
			}
		}

        void postorder_traversal(int a)
		{
			int li = (a*2) + 1 ; 
			int ri = (a*2) + 2 ; 
			if (li <this->totalItems)
			{
				postorder_traversal(li) ; 
			}
			
			if (ri<this->totalItems)
			{
				postorder_traversal(ri) ; 
			}
			if (true)
			{
				cout<<this->arr[a].data <<" -->"; 
			}
		}

};

int main(){


	bst obj(60);
	int index=0;
	
	obj.insert(index, 20);
	obj.insert(index, 10);
	obj.insert(index, 5);
	obj.insert(index, 25);
	obj.insert(index, 15);
	obj.insert(index, 22);
	obj.insert(index, 30);
	obj.insert(index , 33); 
	cout<<"Inorder traversal"<<endl ; 
	obj.inorder_traversal(0);
	cout<<endl;
    cout<<"Preorder traversal"<<endl ; 
    obj.preorder_traversal(0); 
	cout<<endl;
    cout<<"Postorder traversal"<<endl ; 
    obj.postorder_traversal(0);
	cout<<endl;
	cout<<endl;
	cout<<"Search Function : " ; 
	int search = 5 ;   //edit this for searching 
	obj.search(0,search); 
	cout<<"Height of the trees is "<<obj.height(0)<<endl ; 
	obj.leavenodes(0) ; 
	cout<<"Leave nodes "<<obj.a <<endl; 
	int height = 2 ; //edit this for nodes at specific height 
	obj.nodesatspecificheight(0,height,0) ; 
	cout<<"Nodes at a Specific Height "<<obj.b<<endl ; 

	
	

	return 0;
}