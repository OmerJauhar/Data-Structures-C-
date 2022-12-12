#include<iostream>
#include<list>
using namespace std ; 

class graph
{
private:
    list<int>* table ; 
    int n ; 
public:
    graph(int n)
    {
        table = new list<int>[n] ; 
        this->n = n ; 
    }
    void addedge(int start_idx , int end_idx , bool bi)
    {
        table[start_idx].push_back(end_idx) ; 
        if (bi)
        {
            table[end_idx].push_back(start_idx) ; 
        }
        
    }
    void deleteedge(int start_idx , int end_idx,bool bi)
    {
        table[start_idx].remove(end_idx) ; 
        if (bi)
        {
            table[end_idx].remove(start_idx) ; 
        }
        
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout<<i<<"-->" ; 
            for (auto it:table[i])
            {
                cout<<it<<" " ; 
            }
            cout<<endl ; 
            
        }
        
    }
};

int main()
{
    graph g(5) ; 
    g.addedge(0,1,true) ; 
    g.print() ; 
    cout<<endl ; 
    g.deleteedge(0,1,true ) ; 

    g.print() ; 
    return 0 ; 
}