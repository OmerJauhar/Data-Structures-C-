#include<iostream>
#include<list>
using namespace std ; 

class graph
{
private:
    int size ;
    list<int>* holder ; 
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

    void dfs(int n)
    {
        bool* array = new bool[this->size] ; 
        for (int i = 0; i < this->size ;i++)
        {
            array[i] = false ; 
        }

        list<int> queue ; 
        array[n] = true ;        
        queue.push_back(n) ;
        while(!queue.empty())
        {
            n = queue.front() ; 
            queue.pop_front() ; 
            list<int>::iterator i ; 
            for ( i = holder[n].begin();i!=holder[n].end() ;i++  )
            {
                if (!array[*i])
                {
                array[*i] = true;
                queue.push_back(*i);
                }
            }
                
            
            

        } 

    }

};

int main()
{
    return 0 ; 
}