#include<iostream>
using namespace std ; 

class queue
{
private:    
    int size ; 
    int front ; 
    int rear ; 
    int* arrayholder  ;
public:
    queue(int n)
    {
        this->size = n ; 
        arrayholder = new int[this->size] ; 
        this->front = -1 ; 
        this->rear = -1 ; 
    }
    ~queue()
    {
        delete[]arrayholder ; 
    }
    void enqueue(int data)
    {
        if (this->isfull())
        {
            cout<<"circular queue is full "<<endl; 
        }
        else
        {
            if (this->isempty())
            {
                front++ ; 
            }
            
            rear = (rear+1)% this->size ; 
            arrayholder[rear] = data ; 
        }
    
    }
    void dequeue()
    {
        if (this->isempty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            int temp = arrayholder[front] ;   
        
        if (front == rear)
        {
            front = rear = -1 ; 
        }
        else
        {
            front = front+1 %this->size ; 
        } 
        cout<<"The value is "<<temp ; 
        }
        
        
    }
    bool isfull()
    {
        return ((rear+1)%this->size == front) ; 
    }
    bool isempty()
    {
        return front == -1 ; 
    }
};

using namespace std ; 
int main()
{
    return 0 ; 
}