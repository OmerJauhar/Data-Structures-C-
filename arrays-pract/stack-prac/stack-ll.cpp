#include<iostream>
using namespace std ; 

class stackll ; 
class node
{
private:
    friend class stackll ; 
    int info ; 
    node* next ;

public:
    node(int n)
    {
        this->info = n ; 
        next = nullptr ; 
    }

};

class stackll
{
private:
    int counter ; 
    int size ; 
    node* top ; 

public:
    stackll(int n)
    {
        this->top = nullptr ; 
        this->counter = 0 ; 
        this->size = n ; 
    }
    ~stackll()
    {
        delete top ; 
    }
    void push(int key)
    {
        if (counter >= this->size)
        {
            cout<<"Stack overflow"<<endl; 
            return ; 
        }
        node* temp = new node(key) ;
        if (top==nullptr)
        {
            top = temp ; 
        }
        node* temp1 = top ; 
        temp->next = temp1 ; 
        top = temp ; 
        this->counter ++ ; 
        return ; 
    }

    void pop()
    {
        if (this->counter <= 0)
        {
            cout<<"Stack underflow"<<endl ; 
            return ; 
        }
        cout<<"POP element : "<<top->info<<endl ; 
        top = top->next ; 
        this->counter -- ; 
    }

    void peak()
    {
        if (this->counter <=0 )
        {
            cout<<"Top is empty"<<endl ; 
        }
        cout<<"Top"<<top->info <<endl ; 
        return ; 
        
    }

};

int main()
{
    stackll s1(5) ; 
    s1.push(4234) ; 
    s1.push(4234) ;
    s1.push(4234) ;
    s1.push(4234) ;
    s1.push(4234) ;
    s1.pop() ;
    s1.pop() ;  
    s1.pop() ; 
    s1.pop() ; 
    s1.pop() ; 
    s1.pop() ; 

    return 0 ; 
}