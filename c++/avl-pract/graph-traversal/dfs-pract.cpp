#include<iostream>
#include<list>
using namespace std ; 

class graph
{
private:
    int size ;
    list<int>* holder  ; 
public:
    graph(int n)
    {
        this->size = n ; 
        holder = new list<int>[this->size] ; 
    }
    void addedge(int start_idx , int end_idx)
    {
        holder[start_idx].push_back(end_idx) ; 
    }
    void dfs(int )
    {
        bool* visited = new bool[this->size] ; 
        for (int i = 0; i < this->size; i++)
        {
            visited[i] = false ; 
        }

        for (int i = 0; i < this->size; i++)
        {
            if(!visited[i])
            {
                dfs_helper(i,visited) ; 
            }
        }
        
        
    }

    void dfs_helper(int n , bool array[] )
    {
        array[n] = true ; 
        list<int>::iterator i ; 
        for ( i = holder[n].begin(); i !=holder[n].end(); i++)
        {
            if (array[*i] == false )
            {
                dfs_helper(*i,array) ; 
            }
            
        }
        
    }
};

int main()
{
    return 0; 
}