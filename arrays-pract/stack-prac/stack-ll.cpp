#include<iostream>
using namespace std ; 


class stack
{

private:
class node
{
public:
    int info ; 
    node* next ; 

    node(int n)
    {
        this->info = n ; 
        next  =  nullptr ; 
    }
};
    node* top ;
    int counter ; 
    int size ;
    node* curr ;  
public:
    stack()
    {
        top = nullptr ;
        this->counter = 0 ;  
        this->size = 10 ; 
        //by default the size of the stack will be 10 ;
    }
    stack(int n)
    {
        top = nullptr ; 
        this->counter = 0 ; 
        this->size = n ; 
    }
    void push(int val )
    {
        if (counter >= size)
        {
            cout<<"Stack overflow"<<endl;
            return ; 
        }
        node* ptr = new node(val) ; 
        curr = top ; 
        top = ptr ; 
        top->next = curr ; 
        counter++ ; 
        return ;         
    }
    void pop()
    {
        if (counter <= 0)
        {
            cout<<"Stack Underflow"<<endl ; 
            return ; 
        }
        curr = top ; 
        top = top->next ; 
        counter-- ; 
        // cout<<""<<curr->info<<endl ; 
        
    }
    void peak()
    {
        if (!counter <= size)
        {
            cout<<"TOP: "<<top->info <<endl ; 
        }
        
    }

};
int main()
{
    stack s1(10) ; //10 limit is given in the start
    s1.push(12) ; 
    s1.push(13) ; 
    s1.push(11) ; 
    s1.push(14) ; 
    s1.push(10) ; 
    s1.push(15) ; 
    s1.push(18) ; 
    s1.push(19) ; 
    s1.push(51) ; 
    s1.push(99) ; 
    s1.push(22) ; //limit of 10 exceeded 
    s1.peak() ;
    s1.pop() ;
    s1.peak() ;
    s1.pop() ; 
    s1.peak() ;
    s1.pop() ; 
    s1.peak() ;  
    s1.pop() ;
    s1.peak() ;
    s1.pop() ; 
    s1.peak() ;
    s1.pop() ; 
    s1.peak() ;  
    s1.pop() ;
    s1.peak() ;
    s1.pop() ; 
    s1.pop() ; 
  
    return 0 ; 
}