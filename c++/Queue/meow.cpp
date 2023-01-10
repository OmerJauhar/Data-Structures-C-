#include<iostream>
#include<iomanip>
using namespace std ; 

class Queue
{
private:
    int capacity ; 
    int front = -1 , rear = -1 ; 
    int * Arrayptr ; 
public:
    Queue()
    {
        //by default the capacity is going to be 100 
        this->capacity = 100 ; 
        Arrayptr = new int[capacity] ; 
    }
    Queue(int n)
    {
        this->capacity = n ; 
        Arrayptr = new int[n] ; 
    }
    ~Queue()
    {
        delete[] Arrayptr ; 
    }

    void Enqueue(int val)
    {
        if (rear == capacity - 1)
        {
            cout<<"Overflow "<<endl ; 
        }
        else
        {
            if (front == -1)
            {
                front = 0 ; 
            }
            rear ++ ; 
            *(Arrayptr + rear) =  val ; 
            
        }
        
    }

    void Dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout<<"Queue is empty "<<endl ;
        }
        else
        {
            cout<<*(Arrayptr + front) ; 
            front ++ ;  
        }
        
    }
    void display()
    {
        if (front == -1)
        {
            cout<<"Queue is empty "<<endl ;
        }
        else
        {
            cout<<"The elements of the array are"<<endl ; 
            for (int i = front; i < rear -1; i++)
            {   
                cout<<*(Arrayptr + i)<<setw(07); 
            }
            
        }
        
    }

};

int main()
{
    return 0 ; 
}