#include<iostream>
#include<assert.h>

using namespace std;

class MaxHeap{
	private:
		struct node{
			int key;
		};
		node *arr;
		int capacity;
		int totalItems;
		
		void doubleCapacity(){
			if(this->arr == NULL){
				this->arr = new node[1];
				this->capacity = 1;
				return;
			}
			
			int newCapacity = capacity * 2;
			node *newArr = new node[newCapacity];
			for(int i = 0; i < this->totalItems; i++){
				newArr[i] = this->arr[i];
			}
			
			delete this->arr;
			this->capacity = newCapacity;
			this->arr = newArr;
		}
		
		void shiftUp(int index){
			if(index < 1){
				return;
			}
			int parent = (index-1)/2;
			if(this->arr[index].key > this->arr[parent].key){
				swap(this->arr[index], this->arr[parent]);
				shiftUp(parent);
			}
			return;
		}
		
		void shiftDown(int index){
			int maxIndex = -1;
			
			int lChildIndex = index * 2+1;
			int rChildIndex = (index * 2) + 2;
			
			if(lChildIndex < totalItems){
				if(arr[index].key < arr[lChildIndex].key){
					maxIndex = lChildIndex;
				}
			}
			
			if(rChildIndex < totalItems){
				int newindex = (maxIndex == -1 ? index : maxIndex);
				if(arr[newindex].key < arr[rChildIndex].key){
					maxIndex = rChildIndex;
				}
			}
			
			if(maxIndex == -1){
				return;	
			}
			swap(arr[index], arr[maxIndex]);
			shiftDown(maxIndex);
		}

		void inorder_traversal(int a)
		{
			int li = (a*2) + 1 ; 
			int ri = (a*2) + 2 ; 
			cout<<this->arr[a].key <<" "; 
			if (li <this->totalItems)
			{
				inorder_traversal(li) ; 
			}
			
			if (ri<this->totalItems)
			{
				inorder_traversal(ri) ; 
			}
		}
	public:
		
		MaxHeap(){
			this->arr = NULL;
			this->capacity = 0;
			this->totalItems = 0;
		}
		
		MaxHeap(int _capacity){
			assert(_capacity >= 1);
			this->arr = new node[_capacity];
			this->capacity = _capacity;
			this->totalItems = 0;
		}
		void INORDERTRAVERSAL()
		{
			inorder_traversal(0) ; 
		}
		
		void insert(int key){
			if(this->totalItems == this->capacity){
				doubleCapacity();
			}
			this->arr[totalItems].key = key;
			shiftUp(totalItems);
			this->totalItems++;
		}
		
		void getMax(int &key){
			assert(totalItems != 0);
			key = this->arr[0].key;
		}
		
		void deleteMax(){
			assert(totalItems != 0);
			swap(arr[0], arr[this->totalItems-1]);
			totalItems--;
			shiftDown(0);
		}
		
		bool isEmpty() const{
			return (totalItems == 0);
		}
		
		void deleteAll(){
			if(this->arr != NULL){
				delete[]arr;
				arr = NULL;
				this->capacity = 0;
				this->totalItems = 0;
			}
		}
		~MaxHeap(){
			deleteAll();
		}
};

int main(){
	// MaxHeap heap;
	// for(int i = 1; i <= 200; i++){
	// 	heap.insert(i);
	// }
	// heap.deleteAll();
	
	// for(int i = 201; i <= 300; i++)
	// 	heap.insert(i);
	// heap.deleteMax();
	// while(!heap.isEmpty()){
	// 	int s;
	// 	heap.getMax(s);
	// 	cout << s << endl;
	// 	heap.deleteMax();
	// }
	MaxHeap h1 ; 
	for (int i = 0; i < 16; i+=2)
	{
		h1.insert(i) ; 
	}
	

	h1.INORDERTRAVERSAL() ; 
	cout<<"\n"<<endl ; 


	while (!h1.isEmpty())
	{
		int s ; 
		h1.getMax(s) ; 
		cout<<s<<endl;
		h1.deleteMax() ;  
	}

	
	

}
