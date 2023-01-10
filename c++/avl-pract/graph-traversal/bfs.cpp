#include<iostream>
#include<list>
using namespace std ; 

class bfsgraph
{
private:
    int n ; 
    list<int>* holder ; 
public:
    bfsgraph(int n)
    {
        this->n = n ; 
        holder = new list<int>[this->n] ; 
    }
    void addedge(int start_idx , int end_idx)
    {
        holder[start_idx].push_back(end_idx) ; 
    }
    void bfs(int x)
    {
        bool* visited = new bool[this->n] ; 
        for (int i = 0; i < this->n; i++)
        {
            visited[i] = false ; 
        }
        list<int> queue ; 
        visited[x] = true ; 
        queue.push_back(x) ; 
        list<int>::iterator i ; 
        while (!queue.empty())
        {
            x = queue.front() ; 
            cout<<x<<" ";
            queue.pop_front() ; 
            for ( i = holder[x].begin(); i != holder[x].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true ; 
                    queue.push_back(*i) ; 
                }
                
            }
            
        }
        
        
    }
};


int main()
{
    return 0 ; 
}