#include<iostream>
using namespace std ; 

class stack
{
private:    
    int info ; 
    int count ; 
    int size ; 
    int* arr ; 
    int* curr ; 
public:
    stack()
    {
        this->count = 0 ; 
        this->size = 10 ; 
        arr = new int[size] ;
        curr = arr ;  
    }
    stack(int n)
    {
        this->count = 0 ;
        this->size = n ; 
        arr = new int[n] ;
        curr = arr ;  
    }
    ~stack()
    {
        delete[]arr ; 
        curr = nullptr ; 
        delete curr ;  
    }
    void head()
    {
        curr = arr ; 
    }
    void tail()
    {
        curr = arr + count -1 ; 
    }
    
    void push(int n)
    {
        if (this->count >= this->size)
        {
            cout<<"Stack overflow"<<endl ; 
        }
        head() ; 
        *(curr + count) = n ; 
        count++ ;  
    }
    int pop()
    {
        //will pop element from the end of the array
        if (count <= 0)
        {
            cout<<"Stack Underflow"<<endl ;  
        }
        int a  = 0 ;
        tail() ;
        a = *curr ;   
        // a = *(arr+count -1) ;
        count-- ; 
        return a ;  
    }
    void top()
    {
        if (count<=0)
        {
            
            cout<<"Top is empty"<<endl ; 
            return ; 
        }
        tail() ; 
        cout<<"Top: "<<*(curr) <<endl ; 
    }


};

int main()
{
    stack s1(10) ; 
    s1.push(1) ; 
    s1.push(3) ; 
    s1.push(2) ;
    s1.top() ; 
    s1.pop() ; 
    s1.top();
    s1.pop() ;  
    s1.top();

    return 0 ; 
}