#include<iostream>
using namespace std ; 
class cll ; 
class node
{
private:
    int info ; 
    node* next ;
    friend class cll ; 

public: 
    node()
    {
        this->info = 0 ; 
        next = nullptr ; 
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
class cll
{
private:
    node* head ; 
    node* temp ; 
    node* temp1 ; 
public: 
    cll()
    {
        head = nullptr ; 
    }
    void insert(int val)
    { 
        temp = head ; 
        temp1 = new node(val) ; 
        if(head == nullptr )
        {
            head = temp1 ; 
            head->next = head ; 
            return ; 
        }
        else
        {
            while(temp != head)
            {
                temp = temp->next ; 
            }
            temp ->next = temp1 ; 
            temp1->next = head ; 
        }
    }
    void remove(int key)
    {
        if(head == nullptr)
        {
            cout<<"The linked list is empty "<<endl ; 
        }
        else
        {
            temp = head ; 
            while(temp->next !=head)
            {
                if(temp->next->info == key)
                {
                    temp1 = temp->next ; 
                    temp->next = temp1->next ; 
                    delete temp1 ; 

                }
                temp = temp->next
            }
        }

    }

    void insert_at_key(int val , int key)
    {
        temp = head ; 
        if (head == nullptr)
        {
            cout<<"Head is empty "<<endl ; 
            return ; 
        }
        else
        {
            temp1 = new node(val) ; 
            while(temp!=nullptr && temp->next != head )
            {
                if(temp->info == key )
                {
                    temp1->next = temp->next ; 
                    temp->next = temp1 ; 
                }
                temp = temp->next ; 
            }
        }
        
    }

    void insert_At_head(int val)
    {
        temp1 = new node(val) ; 
        if (head == nullptr)   
        {
            head = temp1 ; 
            // head->next = head ; 
        }
        else
        {
            
            temp = head ; 
            while(temp->next!=head)
            {
                temp = temp->next ; 
            }
            temp->next = temp1  ; 
            temp1->next = head ; 


        }
        
    }

    void display()
    {
        if(head==nullptr)
        {
            cout<<"The head is null "<<endl ; 
        }
        else
        {
            temp = head ; 
            while(temp->next != head )
            {
                cout<<temp->info<<endl ; 
                temp = temp->next ; 
            }
        }
    }
    ~cll()
    {
        delete head ; 
    }
};

int main()
{
    cll c1 ; 
    c1.insert_At_head(40) ; 
    c1.insert_At_head(40) ; 
    c1.insert_At_head(40) ; 
    c1.insert_At_head(40) ; 
    c1.insert_At_head(40) ; 

    c1.display() ;


    return 0 ; 
}