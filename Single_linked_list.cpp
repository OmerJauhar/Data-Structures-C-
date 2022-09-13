#include<iostream>
using namespace std ;

class node {
;
public:

    node* next ;
    int info;
public:
    node()
    {
        this->next = NULL ; 
    }
    node(int val )
    {
        this->next = nullptr ;
        this-> info = val ;
    }
};

class sll
        /* sll stand for single linked list */
{

    node* head;
    node* temp ; 
    node* temp1 ; 
public:
    sll()
    {
        this->head = NULL ;
    }
    void insert_node() ;
    void print_list() ;
    void delete_list() ;

};
void sll::insert_node() /* position and data of the new node   */
{
    int key ;
    temp = new node () ; 
    head = new node () ; 
    temp = head ; 
    if (head = NULL)
    {
        cout<<"Enter the value you want  to store in head node "<<endl ;
        return;
    }
    cout<<"Enter key:"<<endl; 
    cin>>key  ;
    
    while(temp != NULL)
    {
        if(temp->info == key)
        {
            temp1 = new node ;
            cout<<"Enter the info for the new node "<<endl ; 
            cin>>temp1->info ; 
            temp1->next = temp->next ;
            temp->next = temp1 ;
        }
        temp = temp->next ; 
    }


}

int main()
{
    cout<<"Start of the program "<<endl ;

    return 0;
}