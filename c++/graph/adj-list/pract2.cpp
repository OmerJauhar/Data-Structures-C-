#include<iostream>
#include<list>
using namespace std ;

class node
{
    public:
        int start_index , end_index , weight ; 
};


class graph
{
    public:
        list<node>* holder ;
        int n ; 
    graph(int n)
    {
        holder = new list<node>[n] ;
        this->n = n ; 
    } 
    void addedge(int start_index ,int  end_index , int weight )
    {
        node *temp = new node() ; 
        temp->start_index = start_index ; 
        temp->end_index = end_index ; 
        temp->weight = weight ; 
        holder[start_index].push_back(*temp) ; 
    }

    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            for (auto it = holder[i].begin() ; it!= holder[i].end(); it++)
            {
                cout << "Adjacent of: " << it->start_index << " -> " << it->end_index << " (w:" << it->weight << ")" << endl;
            }
            cout<<endl;
            
        }
        
    }

    void list_adjacent_node(int n)
    {
        for (auto it = holder[n].begin() ;it != holder[n].end() ; it++)
        {
            cout << "Adjacent of: " << it->start_index << " -> " << it->end_index << " (w:" << it->weight << ")" << endl;
        }
        
    }

};

int main()
{
graph g(5);
g.addedge(0, 1, 3);
g.addedge(0, 2, 3);
g.addedge(1, 3, 2);
g.addedge(1, 2, 5);
g.addedge(2, 3, 7);
g.addedge(3, 4, 2);
g.addedge(4, 5, 6);
g.addedge(4, 1, 4);
g.addedge(4, 0, 4);
g.print();
int n;
cout << "Enter node number to see adjacent nodes: ";
cin >> n; 
g.list_adjacent_node(n);
return 0 ; 
}