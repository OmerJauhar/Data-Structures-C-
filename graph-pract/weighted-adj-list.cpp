#include<iostream>
#include<list>
using namespace std ; 

class node
{
public:
    int start_idx ;
    int end_idx ; 
    int weight ; 
public:
    node()
    {
        this->start_idx = 0 ; 
        this->end_idx = 0 ; 
        this->weight = 0 ; 
    } 
};

class graph
{
private:
    list<node>* table ; 
    int size ; 
public:
    graph(int size )
    {
        this->size = size ; 
        table = new list<node>[size] ; 
    }
    void addnode(int start , int end , int cost)
    {
        node* ptr = new node() ; 
        ptr->start_idx = start ; 
        ptr->end_idx = end ; 
        ptr->weight = cost ; 
        table[start].push_back(*ptr) ; 
    }

    // void deletenode(int start , int end , int cost)
    // {
    //     node* ptr= new node() ; 
    //     ptr->start_idx = start ; 
    //     ptr->end_idx = end ; 
    //     ptr->weight = cost ; 
    //     table[start].remove(*ptr) ; 
    // }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            for (auto it = table[i].begin() ; it!=table[i].end();it++)
            {
                cout<<"Adjacent of:"<<i<<"-->"<<it->end_idx<<" (w:"<<it->weight<<")"<<endl ; 
            }
            cout<<endl ; 
            
        }
        
    }
    void print_adjacent(int i)
    {
        for (auto it = table[i].begin() ; it!=table[i].end();it++)
        {
            cout<<"Adjacent of:"<<i<<"-->"<<it->end_idx<<" (w:"<<it->weight<<")"<<endl ; 
        }
    }
    
};

int main()
{
 graph g(3) ; 
 g.addnode(0,1,2) ; 
 g.addnode(1,2,4) ; 
 g.print() ; 
}
