#include<iostream>
using namespace std ;  

class node
{
public:
    int info; 
    node* next ; 
    node* prev ; 
};

class dcll
{
private:
    node* head ; 
    node* temp ; 
    node* temp1 ; 
public: 
    dcll()
    {
        head = temp = temp1 = nullptr ; 
    }

    void insert_at_key(int val , int key)
    {
        temp1 = new node();
        temp1->info = val ; 
        if(head==nullptr)
        {
            cout<<"The dcll has not been initialized yet"<<endl ; 
        }
        else
        {
            temp = head ; 
            while(temp!=head)
            {
                if(temp->info == key)
                { 
                    temp1->next = temp->next ; 
                    temp1->prev = temp->next->prev ; 
                    temp->next->prev = temp1 ; 
                    temp->next = temp1 ; 
                }
                temp = temp->next ; 
            }
        }
    }
    void insert_before_head(int val)
    {
        temp1 = new node(); 
        temp1->info = val ; 
        if(head == nullptr)
        {
            head = temp1 ; 
            head->next = head->prev = head ; 
            return ; 
        }
        
        while(temp->next !=head)
        {
            temp = temp->next ; 
        } 
        temp1->prev=temp;
        temp1->next=head;
        
        temp->next=temp1;
        head->prev = temp1 ;

    }
    void display()
    {
        if(head!=nullptr)
        {
            temp = head ; 
            while(temp->next != head )
            {
                cout<<temp->info<<endl; 
            }
        }
        else
        {
            cout<<"head is empty"<<endl ; 
        }
    }
    ~dcll()
    {
        delete head , temp , temp1 ; 
    }

};

int main()
{
    dcll dc1 ; 
    dc1.insert_before_head(10) ; 
    dc1.insert_before_head(20) ; 
    dc1.insert_before_head(30) ; 
    dc1.insert_before_head(40) ;

    // dc1.display() ; 
    return 0 ; 
}