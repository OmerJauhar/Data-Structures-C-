#include<iostream>
using namespace std ;

class node
{
public:
    int info ; 
    node * next ; 

    node()
    {
        info = 0 ; 
        this->next = nullptr ; 
    }
    node(int a)
    {
        this->info = a ; 
    }
    ~node()
    {
        delete next ; 
    }
};

class stack 
{
private:
    node* top ; 
    int length ; 
public:
    stack()
    {
        this->top = nullptr ; 
    }
    ~stack()
    {
        delete top ; 
    }
    void pop()
    {
        if(top == nullptr)
        {
            cout<<"Stack underflow"<<endl ; 
        }
        else
        {
            node * ptr ; 
            ptr = top ; 
            cout<<"The poped element is "<<top->info<<endl ; 
            top = top->next ;
            delete ptr ; 
        }
    }
    void push(int a)
    {
        node *push_node = new node(a) ; 
        push_node->next = top ; 
        top = push_node ; 
    }

    void display()
    {
        node* temp ; 
        if(top == nullptr)
        {
            cout<<"The stack is empty"<<endl ; 
        }

        else
        {
            temp = top ; 
            while(temp!=nullptr)
            {
                cout<<temp->info<<endl ; 
                temp= temp->next ; 
            }
        }


    }

};

int main()
{

    stack s1 ; 
    s1.display() ; 
    s1.push(10); 
    s1.push(20); 
    s1.push(30); 
    s1.push(40);

    s1.display();
    s1.pop();
    s1.pop();

    s1.display(); 


    return 0 ; 
}