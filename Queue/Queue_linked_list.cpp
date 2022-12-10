#include<iostream>
using namespace std ; 

class node
{
public:
    int info ; 
    node* next ; 
public:
    node()
    {
        next = nullptr ; 
        info = 0 ; 
    }
    node(int a)
    {
        this->info = a ; 
        next = nullptr ; 
    }
    ~node()
    {
        delete next ; 
    }

};

class queue
{
private:
    node* head ; 
    node* tail ; 
    node* temp ; 
    node* temp1 ; 

public:
    queue()
    {
        head = tail = nullptr ; 
    }
    ~queue()
    {
        delete tail ,head ; 
    }
    void enqueue(int a )
    {
        temp1 = new node(a) ; 
        if(head==nullptr)
        {
            head = temp1 ; 
            tail = temp1 ; 
        }
        else
        {
            tail->next = temp1 ; 
            tail = temp1 ; 
        }
    }

    void dequeue()
    {
        if(head = tail = nullptr )
        {
            cout<<"The queue is empty "<<endl ; 
        }
        if(head ==tail)
        {
            head = nullptr ; 
            tail = nullptr ; 
        }
        temp1 = head ; 
        head = head->next ; 
        delete temp1 ; 
    }

    void display()
    {
        if(head==nullptr )
        {
            cout<<"The queue is empty"<<endl; 
        }
        else
        {
            temp = head ; 
            while(temp !=nullptr )
            {
                cout<<temp->info <<endl; 
                temp = temp->next ; 
            }

        }
    }
};

int main()
{
    queue q1 ; 
    q1.enqueue(10) ; 
    q1.enqueue(30) ; 
    q1.enqueue(40) ; 
    q1.enqueue(50) ; 
    q1.display() ; 

    q1.dequeue();

    q1.display() ; 
    return 0 ; 
}