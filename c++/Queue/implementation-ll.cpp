#include<iostream>
using namespace std ; 

class queue ; 
class node
{
private:
    friend class queue ; 
    int info ; 
    node* next ;
public:
    node()
    {
        this->info = 0 ; 
        this->next = nullptr ; 
    }
    node(int n)
    {
        this->info = n ; 
        this->next = nullptr ; 
    }

};

class queue
{
private:
    node* head ; 
    node* temp ; 
    node* tail ; 
    int counter  ; 
    int size ; 
public:
    queue()
    {
        this->size = 10 ; //by default the size will be 10 ; 
        this->counter = 0 ; 
        this->head = nullptr ; 
        this->temp = this->head ; 
    }
    queue(int n)
    {
        this->size = n ; 
        this->counter = 0 ; 
        this->head = nullptr ; 
        this->temp = this->head ; 
    }
    void enqueue(int n)
    {
        if (this->counter >= this->size )
        {
            cout<<"Queue is full"<<endl ; 
            return ; 
        }
        node * ptr = new node(n) ;
        temp = head ; 
        head = ptr ; 
        ptr->next = temp ; 
        this->counter ++ ; 
        return ;  
  
    }
    void dequeu()
    {
        if (this->counter <= 0 )
        {
            cout<<"Queue is empty"<<endl ; 
            return ; 
        }
        temp = head ; 
        tail = head ; 
        while(tail->next != nullptr)
        {
            tail = tail->next ; 
        }
        while(temp->next != tail)
        {
            temp = temp->next ; 
        }
        temp->next = nullptr ; 
        cout<<"Dequeue elements is "<<tail->info <<endl ; 
        tail->next == nullptr ;
        delete(tail) ; 
         
        
        
        return ;
    }

    // void peak()
    // {
    //     if(counter <= 0)
    //     {
    //         cout<<"EMPTY"<<endl ; 
    //     }
        

    // }

};

int main()
{
    queue q1(10) ; 
    q1.enqueue(12) ;
    q1.enqueue(13) ;
    q1.enqueue(13) ;
    q1.enqueue(13) ;
    q1.dequeu() ;  
    q1.dequeu() ;
    q1.dequeu() ;
    return 0 ; 
}