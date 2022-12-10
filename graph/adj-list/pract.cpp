#include<iostream>
#include<list>
using namespace std ; 


class graph
{
    public:
        list<int>* arrayholer ; 
        int n ; 
    graph(int n)
    {
        arrayholer = new list<int>[n] ; 
        this->n = n ; 
    }
    void addedge(int start_index , int end_index , bool bi)
    {
        arrayholer[start_index].push_back(end_index) ; 
        if (bi)
        {
           arrayholer[end_index].push_back(start_index) ;  
        }
        
    }

    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout<<i<<"-->" ; 
            for (auto it:arrayholer[i])
            {
                cout<<it ; 
            }
            cout<<endl; 
            
        }
        
    }

};

int main()
{
    graph g1(5) ; 
    g1.addedge(1,2,true) ; 
    g1.addedge(1,3,true) ; 
    g1.addedge(3,2,true) ; 
    g1.print() ; 

    return 0 ; 
}