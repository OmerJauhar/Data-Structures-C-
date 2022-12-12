#include<iostream>
using namespace std ; 

class sll ; 
class node
{
private:
    friend class sll ; 
    int info ; 
    node* next ; 
public:
    node()
    {
        this->info = 0 ; 
        this->next = nullptr ; 
    }
    node(int n)
    {
        this->info = n ; 
        this->next = nullptr  ;
    }
    ~node()
    {
        delete next ; 
    }
};

class sll
{
private:
    node* head ; 
    node* temp ; 
public: 
    sll()
    {
        head = nullptr ; 
        temp = nullptr ; 
    }
    void insertatend(int n)
    {
        if (head == nullptr)
        {
            head = new node(n) ; 
            return ; 
        }
        temp = head ; 
        while(temp->next != nullptr)
        {
            temp = temp->next ; 
        }
        node* ptr = new node(n) ; 
        temp->next  = ptr ; 
        return ;
        
    }
    void printll()
    {
        temp= head ; 
        while(temp!=nullptr)
        {
            cout<<temp->info<<" ->";
            temp = temp->next ; 
        }
    }
    void insertatkey(int n , int key)
    {
        if(head->info == key)
        { 
            node* ptr = new node(n) ; 
            ptr->next = head ; 
            head = ptr ; 
            return ; 
        }
        temp = head ; 
        while (temp !=nullptr)
        {
            if (temp->next != nullptr)
            {
                if (temp->next->info=key)
                {
                node* temp1 ; 
                temp1 = temp->next ;
                node* ptr = new node(key) ; 
                temp->next = ptr ;
                ptr->next = temp1 ;
                }
                  

            }
            else
            {
                temp = temp->next ; 
            }
            
        }
        
        
    }
};

int main()
{
    sll s1 ;
    s1.insertatend(12) ; 
    s1.insertatend(13) ; 
    s1.insertatend(14) ; 
    s1.insertatend(15) ; 
    s1.insertatend(16) ; 
    s1.insertatend(17) ; 
    s1.insertatkey(10,15) ; 
    s1.printll();
    return 0 ; 
}