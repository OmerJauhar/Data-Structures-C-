#include<iostream>
using namespace std ; 
class node
{
public:
    int info; 
    node* next ; 
    node()
    {
        next = nullptr ; 
    }
    node(int n)
    {
        this->info = n ; 
        next = nullptr ; 
    }
    ~node()
    {
        delete next ; 
    }
};

class sll
{
public:
    node* head ; 
    node* temp ; 
    node* temp1 ;
public:
    sll()
    {
        head = nullptr , temp = nullptr , temp1 = nullptr ; 
    }
    ~sll()
    {
        delete head , delete temp ,delete temp1 ; 
    }
    void insert_At_end(int a )
    {
        temp1 = new node(a) ; 
        temp1->next = nullptr ; 
        if (head== nullptr)
        {
            head = temp1 ; 
        }
        else
        {
            temp = head ; 
            while(temp->next != nullptr)
            {
                temp= temp->next ; 
            }

                temp->next = temp1 ;
        }
        
 
    }

    void insert_at_key(int val , int key)
    {
        if(head == nullptr)
        {
            cout<<"linked list not set"<<endl ; 
        }
        else
        {
            temp = head ; 
            while(temp!=nullptr)
            {
                if(temp->info == key )
                {
                    temp1 = new node() ; 
                    temp1->info = val ; 
                    temp1->next = temp->next ; 
                    temp->next = temp1 ; 
                    
                }

                temp = temp->next ; 
            }
        }
        
    }
    void display()
    {
        if(head== nullptr)
        {
            cout<<"linked list is empty"<<endl ; 
        }
        else
        {
        temp = head ; 
        while(temp!=nullptr)
        {
            cout<<temp->info<<endl; 
            temp=temp->next ; 
        }
        }


    }
};

int main()
{
    sll s1 ; 
    s1.display() ; 
    s1.insert_At_end(10) ; 
    s1.insert_At_end(20) ; 
    s1.insert_At_end(20) ; 
    s1.insert_at_key(10,10) ; 
    
    // s1.insert_at_key(15,5) ; 
    // s1.display() ;
    s1.display(); 

    return 0 ; 
}