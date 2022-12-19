#include<iostream>
using namespace std ;

class queue
{
private:
    int counter ; 
    int size ; 
    int* arrayholder ;
    int* curr ; 
public:
    void head()
    {
        curr = arrayholder  ; 
    }
    void tail()
    {
        curr = arrayholder + counter -1 ; 
    }
    queue(int n)
    {
        this->size = n ; 
        this->counter = 0 ; 
        arrayholder = new int[this->size] ; 
    }
    void endqueue(int n)
    {
        if (counter>= this->size)
        {
            cout<<"Queue is full"<<endl;
            return ; 
        }
        head();
        *(curr+counter) = n ; 
        counter++ ;
        return ; 
    }
    void dequeue()
    {
        if (counter <=0)
        {
            cout<<"Queue is empty"<<endl;
            return ; 
        }
        tail();
        cout<<"Element is"<<*(curr)<<endl;
        this->counter -- ;
        return ; 
    }
    void peak()
    {
        if (counter <= 0)
        {
            cout<<"Empty"<<endl ; 
            return ; 
        }
        head() ; 
        cout<<*(curr)<<endl;
        
    }
};

int main()
{
    queue q1(5) ; 
    q1.endqueue(23) ; 
    q1.peak();
    q1.dequeue() ; 
    q1.peak() ; 
    return 0 ; 
}