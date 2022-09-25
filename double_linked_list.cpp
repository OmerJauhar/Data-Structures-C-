#include<iostream>
using namespace std ; 
class dll ; 
class node
{
private:
    int info ; 
    node * next ;
    node* prev ; 
    friend class dll ;
public:
    node()
    {
        this->info = 0 ; 
        next = nullptr ; 
        prev = nullptr ; 
    }
    node(int a)
    {
        this->info = a ; 
        next = nullptr  ; 
        prev = nullptr ; 
         
    }

    ~node()
    {
        delete next ;
    }

};

class dll
{
private:
    node* head ;
    node* temp1 ; 
    node* temp ; 
public:
    dll()
    {
        head = temp1 = temp = nullptr ; 
    }

    ~dll()
    {
        delete head , temp1 , temp ; 
    }

    void insert_at_end(int val)
    {
        temp1 = new node(val) ; 
        if(head == nullptr)
        {
            head = temp1 ; 
            return ; 
        }
        else
        {
            temp = head ; 
            while(temp->next != nullptr)
            {
                temp = temp->next ; 
            }
            temp->next = temp1 ; 
            temp1->prev = temp ; 
            temp1->next = nullptr ; 
        }

       
    }
    void insert_At_pos(int val , int key)
    {
        if (head == nullptr )
        {
            cout<<"The linked list is not set "<<endl ; 
            return ; 
        }
        else
        {
            temp = head ; 
            while(temp != nullptr )
            {
                if(temp->info == key)
                {
                    temp1 = new node(val) ; 
                    temp1->next  = temp->next ;
                    temp1->prev = temp ; 
                    if(temp1->next!=nullptr)
                    {
                        temp1->next->prev  = temp1 ; 
                    }
                    temp1->prev->next = temp1 ; 
                
                    

                }
                temp = temp->next ; 
            }
        }
    }
    void delete_at_end()
    {
        if(head == nullptr)
        {
            cout<<"The double linked list is already empty "<<endl ; 
        }
        else
        {
            temp = head ; 
            while(temp->next != nullptr)
            {
                temp = temp->next ; 
            }
            temp->prev->next = nullptr ; 
            temp->prev = nullptr ; 
            delete temp ; 
        }
    }

    void delte_at_key(int key)
    {
        if(head== nullptr)
        {
            cout<<"The double linked list is already completely empty "<<endl ; 
            
        }
        else
        {
            temp = head ; 

            while(temp!=nullptr)
            {
                if(temp->info == key )
                {
                    temp->next->prev = temp->prev ; 
                    temp->prev->next = temp->next ; 
                    temp->prev = nullptr ;
                    temp->next = nullptr ; 
                }
                temp = temp->next ; 
            }
        }
    }
    void display()
    {
        if(head== nullptr)
        {
            cout<<"Double linked list is not set "<<endl; 
        }
        else
        {
            temp = head ; 

            while(temp!=nullptr)
            {
                cout<<temp->info<<endl ; 
                temp = temp->next ; 
            }
        }
    }

};

int main()
{
    dll d1 ; 
    d1.display() ; 
    d1.insert_at_end(10) ;
    d1.insert_at_end(20) ;
    d1.insert_at_end(30) ; 
    // d1.display() ; 

    d1.insert_At_pos(5 , 30); 

    d1.delte_at_key(20) ; 
    d1.display() ;  
    return 0 ; 
}