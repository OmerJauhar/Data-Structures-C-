#include<iostream>
using namespace std ; 


class node
{
public:

    int data ; 
    node * next ;         

    node()
    {
        this->data = 0 ; 
        this->next = nullptr ; 
    }
    node(int n)
    {
        this->data = n ; 
        this->next = nullptr ; 
    }
    ~node()
    {
        delete next ;
    }
};

class sll
{
private:
    node *head , *temp1 , *temp2 ;
public:
    sll() ; 
    ~sll();
    void set_sll_head() ; 
    void print_sll() ; 
    void insert_end(); 
};
sll::sll()
{
    head = NULL ; 
    temp1 = NULL ; 
    temp2 = NULL ; 
}

sll::~sll()
{
    delete head , temp1 , temp2  ; 
}

void sll::insert_end()
{
    temp1 = head ; 
    if(head==nullptr)
    {
        cout<<"Head is not set "<<endl ; 
        set_sll_head() ; 
        return ; 

    }
    
    while(temp1 != nullptr)
    {
        if(temp1->next == nullptr )
        {
           
            cout<<"Enter the value you want to store in the node"<<endl ;
            cin>>temp1->next->data ; 
            temp1->next->next = nullptr ;  
        }
        temp1 = temp1->next ; 
    }
}

void sll::set_sll_head()
{
    if (head == nullptr)
    {
        head = new node ; 
        cout<<"Enter the value you want to store in head : "<<endl ; 
        cin>>head->data ; 
        head->next = nullptr ; 
        return ; 
    }
   
}

void sll::print_sll()
{
    temp1 = head ; 
    while(temp1 != nullptr)
    {
        cout<<(temp1->data)<<endl ; 
        temp1 = temp1->next ; 
    }

}


int main()
{
    sll s1 ; 
    s1.set_sll_head() ; 
    s1.insert_end();
    s1.print_sll() ; 

    return 0 ; 
}