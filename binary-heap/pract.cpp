#include<iostream>
using namespace std ;

class maxheap
{
private:
    struct node
    {
        int key ;
    };
    node* arr;
    int capacity ; 
    int totalitems;

    void doublecapacity()
    {
        if (this->arr == NULL)
        {
            this->arr = new node[1] ; 
            this->capacity = 1 ; 
            return ; 
        }
        int newcapacity = this->capacity*2 ; 
        node* newarr = new node[newcapacity] ; 
        for (int i = 0; i < this->totalitems; i++)
        {
            newarr[i] = this->arr[i] ; 
        }
        delete this->arr ; 
        this->capacity = newcapacity ; 
        this->arr = newarr ;     
    } 
    void shiftup(int index)
    {
        if (index<1)
        {
            return ; 
        }
        int parent = (index-1) /2 ; 
        if (this->arr[index].key > this->arr[parent].key)
        {
            swap(this->arr[index],this->arr[parent]) ; 
            shiftup(parent) ; 
        }
        return ; 
    }
    void shiftdown(int index)
    {
        int maxindex = -1 ; 
        int lci = (index*2+1) ; 
        int rci = (index*2+2) ; 
        if (lci<this->totalitems)
        {
            if (this->arr[lci].key > this->arr[index].key )
            {
                maxindex = lci ; 
            }
            
        }
        if (rci < this->totalitems)
        {
            int newindex = (maxindex ==-1 ? index : maxindex) ; 
            if (this->arr[newindex].key < this->arr[rci].key)
            {
                maxindex = rci ; 
            }    
        }
        
        if (maxindex == -1)
        {
            return ;
        }
        swap(this->arr[index],this->arr[maxindex]) ; 
        shiftdown(maxindex) ; 
        
    }
    public:
    void insert(int  key )
    {
        if (this->totalitems == this->capacity)
        {
            this->doublecapacity() ; 
        }
        this->arr[totalitems].key = key ; 
        shiftup(totalitems) ; 
        totalitems++ ; 
        
    }
    void getmax()
    {
        if (this->totalitems!=0)
        {
            cout<<this->arr[totalitems].key<<endl;
        }
        else
        {
            cout<<"Empty"<<endl ; 
        }
        
    }
    void deletemax()
    {
        if (this->totalitems!=0)
        {
            swap(this->arr[0],this->arr[totalitems]) ;
            totalitems -- ; 
            shiftdown(0) ;  
        }
        
    }
    bool isempty()
    {
        return(totalitems == 0) ; 
    }
    void inorder(int index)
    {
        int lc = index *2+1 ; 
        int rc = index*2+2 ; 
        if (lc >= this->totalitems)
        {
            inorder(lc) ; 
        }
        cout<<this->arr[totalitems].key<<" --> " ; 
        if (rc >= this->totalitems)
        {
            inorder(rc) ; 
        }
        
    }
    void preorder(int index)
    {
        int lc = index *2+1 ; 
        int rc = index*2+2 ; 
        cout<<this->arr[totalitems].key<<" --> " ;
        if (lc >= this->totalitems)
        {
            preorder(lc) ; 
        } 
        if (rc >= this->totalitems)
        {
            preorder(rc) ; 
        }
        
    }
    void postorder(int index)
    {
        int lc = index *2+1 ; 
        int rc = index*2+2 ; 
        if (lc >= this->totalitems)
        {
            postorder(lc) ; 
        }
        if (rc >= this->totalitems)
        {
            postorder(rc) ; 
        }
        cout<<this->arr[totalitems].key<<" --> " ;
        
    }
    maxheap(int a)
    {
        arr = new node[a];
        this->capacity = a ;
        this->totalitems = 0 ; 
    }
};

int main()
{
    return 0 ; 
} 
