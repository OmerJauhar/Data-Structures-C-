#include<iostream>
#include<list>
using namespace std ; 

class dfsgraph
{
private:
    int v ; 
    list<int>* adjlist ; 
public:
    void dfsfunction(int v , bool visited[])
    {
        visited[v] = true ; 
        cout<<v<<" " ; 

        list<int>::iterator i ; 
        for  (i = adjlist[v].begin(); i != adjlist[v].end(); i++)
        {
            if (!visited[*i])
            {
                dfsfunction(*i,visited) ; 
            }
            
        }
        
    }
    dfsgraph(int n )
    {
        this->v = n ; 
        adjlist = new list<int>[n] ; 
    }

    void addedge(int start_idx , int end_idx)
    {
        adjlist[start_idx].push_back(end_idx) ; 
    }
    void Dfs()
    {
        bool* visited = new bool[this->v] ; 
        for (int i = 0; i < this->v; i++)
        {
            visited[i] = false ; 
        }

        for (int i = 0; i < this->v; i++)
        {
            if (visited[i] == false)
            {
                dfsfunction(i , visited) ; 
            }
            
        }
        
        
    }

};

int main()
{
    dfsgraph gdfs(5);
gdfs.addedge(0, 1);
gdfs.addedge(0, 2);
gdfs.addedge(0, 3);
gdfs.addedge(1, 2);
gdfs.addedge(2, 4);
gdfs.addedge(3, 3);
gdfs.addedge(4, 4);
cout << "Depth-first traversal for the given graph:" << endl;
gdfs.Dfs();
return 0; 
}