#include<iostream>
#include<iomanip>
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
    void set_head() ;
    void delete_list() ;


};
void sll::insert_node() /* position and data of the new node   */
{
    int key ;
    temp = new node () ;
    temp = head ;
    if (head == nullptr)
    {
        cout<<"Enter the value you want  to store in head node "<<endl ;
        cin>>head->info;
        return;
    }
    cout<<"Enter key:"<<endl;
    cin>>key  ;

    while(temp != nullptr)
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
void sll::print_list()
{
    temp = head ;
    if(head == nullptr )
    {
        cout<<"Shit! The list is empty"<<endl ;
        return ;
    }
    while(temp!= nullptr)
    {
        cout<<setw(4)<<temp->info<<" " ;
        temp = temp->next ;
    }
}

void sll::set_head()
{
    if(head == nullptr)
    {
        cout<<"Enter the value you want to store in the head "<<endl ;
        cin>>head->info ;
//        return ;
    }
    cout<<"The head already has a value of "<<head->info<<endl ;
}

int main()
{
    cout<<"Start of the program "<<endl ;
    sll s1 ;
    s1.set_head();
    s1.insert_node();
    s1.insert_node();
    s1.insert_node();
    s1.insert_node();
    s1.print_list() ; 


    return 0;
}