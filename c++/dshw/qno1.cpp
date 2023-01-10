#include <assert.h>
#include<string>
#include<iostream>
using namespace std;
class MaxHeap
{
private: 
	struct Node
	{
		int key;
		char * array ; 
	};
	Node *arr;
	int capacity; // Size of Heap
	int totalItems; // 
	
	void doubleCapacity() // Increase the size
	{
		if (this->arr==NULL)
		{
			this->arr = new Node[1];
			this->capacity = 1;
			return;
		}
		
		int newCapacity = capacity*2;
		Node *newArr = new Node[newCapacity];
		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}
		//if (this->arr!=NULL)
			delete this->arr;
		this->capacity = newCapacity;
		this->arr = newArr;
	}
	void shiftUp(int index)
	{
		if (index < 1)
			return;
		int parent = (index-1) / 2;
		if (this->arr[index].key > this->arr[parent].key)
		{
		   swap(this->arr[index], this->arr[parent]);
		   shiftUp(parent);
		}
	        return;
	}
	void shiftDown(int index)
	{
		int maxIndex = -1;
		int lChildIndex = index * 2+1;  
		int rChildIndex = (index * 2) + 2;
		if (lChildIndex < totalItems)
		{
			if (arr[index].key < arr[lChildIndex].key)
			{
				maxIndex = lChildIndex;
			}
		}	
		if (rChildIndex < totalItems)
		{
			int newindex= (maxIndex == -1 ? index : maxIndex);
			if (arr[newindex].key < arr[rChildIndex].key)
			{
				maxIndex = rChildIndex;
			}
		}
		if (maxIndex == -1)
			return;
		swap(arr[index], arr[maxIndex]);
		shiftDown(maxIndex);
	}
public:
	MaxHeap()
	{
		this->arr = NULL;
		this->capacity = 0;
		this->totalItems = 0;
	}
	MaxHeap(int _capacity)
	{
		assert(_capacity >= 1);
		this->arr = new Node[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}
	void insert(int key, char sss[])
	{
		if (this->totalItems == this->capacity)
		{
			doubleCapacity();
		}
		// this->getMax() ; 
		this->arr[totalItems].key = key;
		this->arr[totalItems].array = sss; 
		shiftUp(totalItems);
		this->totalItems++;
		// this->getMax() ; 
	}
	void getMax()
	{
		//assert(totalItems != 0);
		// key = this->arr[0].key;
		if(totalItems != 0){
		// cout<<"getmax"<<endl ; 
		// cout<<this->arr[0].key<<endl ; 
		cout<<this->arr[0].array<<endl ; }
	}
	void deleteMax()
	{		
		assert(totalItems != 0);
		swap(arr[0], arr[this->totalItems-1]);
		totalItems--;
		shiftDown(0);
	}
	bool isEmpty() const
	{
		return (totalItems == 0);
	}
	void deleteAll()
	{
		if (this->arr != NULL)
		{
			delete[]arr;
			arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;
		}
	}
	~MaxHeap()
	{
		deleteAll();
	}
};
int main()
{
	MaxHeap user1 ; 
	MaxHeap user2 ; 
	int usercounter1  = 1 ; 
	int usercounter2 = 1  ;
	bool online_check_user1 ; 
	bool online_check_user2 ; 
	char msg[25] ; 
	char msg2[25] ;  
	char msg3[25] = {} ; 
	cout<<" Welcome to the program! "<<endl ; 
	char meow  = 'y' ; 
	int selector = 0 ; 
	while (selector != -1)
	{
		cout<<" 1  : Send User2 msgs "<<endl ; 
		cout<<" 2  : receive User1 msgs "<<endl ;
		cout<<" 3  : Send User1 msgs "<<endl ;
		cout<<" 4  : receive User2 msgs "<<endl ;
		cin>>selector  ;
		

		switch (selector)
		{
		case 1:
			cout<<"Enter message for user 2 "<<endl ; 
			cin>>msg ; 
			user1.insert(usercounter1,msg) ; 
			usercounter1++ ; 
			
			break;
		case 2:
			cout<<"Reciving messages for user 1  "<<endl ;
			cout<<"Press 1 to make user 1 online else press zero exit."<<endl ; 
			cin>>online_check_user1 ; 
			if(online_check_user1)
			{
				cout<<"RECEIVING Msgs ..."<<endl ; 
				while (!user2.isEmpty())
				{
					cout<<"\t\t";
					user2.getMax();
					user2.deleteMax() ; 
				}
				
			} 
			else
			{
				cout<<"User is offline try again later"<<endl ; 
			}
			break;

		case 3:
			cout<<"Enter mesage  for user 1 "<<endl ; 
			cin>>msg2 ; 
			user2.insert(usercounter2,msg) ; 
			usercounter2++ ;
			break ; 
		case 4:
			cout<<"Reciving messages for user 2  "<<endl ; 
			cout<<"Press 1 to make user 1 online else press zero exit."<<endl ; 
			cin>>online_check_user2;  
			if(online_check_user2)
			{
				cout<<"RECEIVING Msgs ..."<<endl ; 
				while (!user1.isEmpty())
				{
					cout<<"\t\t";user1.getMax();
					user1.deleteMax() ; 
				}
				
			} 
			else
			{
				cout<<"User is offline try again later"<<endl ; 
			}
			break ; 
		default:
			cout<<"Wrong input try again"<<endl ; 
			break;
		}
		cout<<"\n\n"<<endl ; 
		cout<<"-1  : to exit , 0 to continue "<<endl ; 
		cin>>selector  ; 

	}
	
	
}