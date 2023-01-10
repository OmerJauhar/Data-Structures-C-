#include<iostream>
#include <assert.h>
using namespace std ; 
class maxheap
{
private:
    struct node 
    {
        int key; 
    }; 
    node * arr  ; 
    int capacity ; 
    int totalitems ; 

    void doublecapacity()
    {
        if(this->arr == nullptr)
        {
            this->arr = new node[1] ; 
            this->capacity = 1 ;
            return ; 
        }
        int newcapacity = capacity*2 ;
        node* newarr = new node[newcapacity] ; 
        for(int i = 0; i < this->totalitems; i++)
        {
            newarr[i] = this->arr[i] ; 
        }
        delete this->arr ; 
        this->capacity = newcapacity ; 
        this->arr = newarr ; 
    }

    void shiftup(int index)
    {
        if(index <1)
        {
            return ; 
        }
        int parent = (index-1) /2 ; 
        if(this->arr[index].key > this->arr[parent].key)
        {
            swap(this->arr[index], this->arr[parent]) ; 
            shiftup(parent) ; 
        }
        return ; 
        
        
    }

    void shiftdown(int index )
    {
        int maxindex = -1 ; 
        int lchildindex = index*2 +1 ; 
        int rchildindex = index*2 + 2 ; 
        if(lchildindex <totalitems)
        {
            if(arr[index].key < arr[lchildindex].key)
            {
                maxindex = lchildindex ; 
            }
            
        }

        if(rchildindex <totalitems)
        {
            int newindex = (maxindex == -1 ?index :maxindex) ; 

            if(arr[newindex].key <arr[rchildindex].key)
            {
                maxindex = rchildindex ; 
            }
            
        }
        if(maxindex == -1 )
        {
            return ; 
        }
        swap(arr[index] , arr[maxindex]) ; 
        shiftdown(maxindex) ; 
         
    }

    public:
        maxheap()
        {
            this->arr = nullptr ; 
            this->capacity = 0 ; 
            this->totalitems = 0 ; 
        }

        maxheap(int _capacity)
        {
            assert(_capacity >= 1) ; 
            this->arr = new node[_capacity] ; 
            this->capacity = _capacity ; 
            this->totalitems = 0 ; 
        }

        void insert(int key )
        {
            if(this->totalitems == this->capacity)
            {
                doublecapacity() ; 
            }
            this->arr[totalitems].key = key ; 
            shiftup(totalitems) ; 
            this->totalitems++ ; 
            
        }
        void getMax(int &key)
        {
            assert(totalitems!= 0 ); 
            key = this->arr[0].key ; 
        }

        node printmax()
        {
            return this->arr[0] ; 
        }
        void deletemax()
        {
            assert(totalitems!=0) ; 
            swap(arr[0] , arr[this->totalitems -1]) ; 
            totalitems -- ; 
            shiftdown(0) ; 
        }

        bool isempty() const
        {
            return (totalitems==0) ; 
        }

        void deleteAll()
        {
            if(this->arr != nullptr)
            {
                delete[] arr ; 
                arr = nullptr  ; 
                this->capacity = 0 ; 
                this->totalitems = 0 ; 
            }
            
        }
        ~maxheap()
        {
            deleteAll() ; 
        }
    
};

int main()
{
    maxheap a ; 
    for(int i = 0; i < 200; i++)
    {
        a.insert(i) ; 

    }
    

    while (!a.isempty())
    {
        cout<<a.printmax().key<<endl ;  
        a.deletemax() ; 
    }
    


    
    return 0 ; 
}
