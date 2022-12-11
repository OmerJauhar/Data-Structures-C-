#include<iostream>
using namespace std ; 

class queue
{
private:
    int info ; 
    int counter ; 
    int size ; 
    int* arr ; 
    int* curr ; 
public:
    queue()
    {
        this->arr = new int[10] ; //by default the size of the queue will be 10 
        this->counter = 0 ; 
        this->size = 0 ;
        curr = arr ; 
    }
    queue(int n)
    {
        this->size = n ; 
        this->arr = new int[n] ; 
        this->counter = 0 ; 
        curr = arr ; 
    }
    void head()
    {
        curr = arr ; 
    }
    void tail()
    {
        curr = arr + counter -1 ; 
    }
    void enqueue(int n)
    {
        if (this->counter >= this->size)
        {
            cout<<"Queue if Full"<<endl ;
            return;  
        }
        head() ; 
        *(arr + counter ) = n ; 
        counter ++ ;               
    }
    void dequeue()
    {
        if (counter <= 0 )
        {
            cout<<"The queue is empty"<<endl ; 
            return ; 
        }
        int n = 0 ; 
        head() ; 
        n = *(arr + counter -1) ; 
        counter -- ;
        cout<<"Dequeue elements is "<<n<<endl ;           
    }
    bool isfull()
    {
        return (this->counter == this->size) ; 
    }
    bool isempty()
    {
        return (this->counter == 0 ) ; 
    }
    void peak()
    {
        if (this->counter <= 0 )
        {
            cout<<"EMPTY"<<endl ; 
            return ; 
        }
        head() ;
        cout<<"peak:"<<*(arr + counter -1) <<endl; 
        return ;

    } 
};

int main()
{
    queue q1(10) ; 
    q1.enqueue(1) ; 

    q1.enqueue(2) ;
 
    q1.enqueue(3) ;

    q1.enqueue(4) ;

    q1.enqueue(5) ;
    
    q1.enqueue(11) ; 

    q1.enqueue(12) ;
 
    q1.enqueue(13) ;

    q1.enqueue(14) ;

    q1.enqueue(15) ;
    
    // q1.enqueue(16) ; // queue is full at this point bcz it exceeds the value of 10 (initial size )  


    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    q1.dequeue() ; 
    // q1.dequeue() ; //queue is empty at this point because the counter is less than zero .  
    return 0 ; 
}
//  END!