#include<iostream>
using namespace std ; 

class adjmatrix
{
private:
    int n ; 
    int m ; 
    int* arrayholder ; 
public:
    adjmatrix(int n)
    {
        this->n = n ; 
        this->m = n ; 
        arrayholder =  new int[n*m] ; 
    }
    void addedge(int startindex , int endindex) 
    {
        *(arrayholder+(startindex-1) * this->m + (endindex-1) ) = 1 ; 
    }
    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->m; j++)
            {
                cout<<*(arrayholder + i * this->m + j)<<" " ; 
            }
            cout<<endl ; 
            
        }
        
    }
};

int main()
{
    adjmatrix a1(5) ; 
    a1.addedge(1,1) ; 
    a1.addedge(2,2) ;
    a1.addedge(3,3) ;
    a1.addedge(4,4) ;
    a1.addedge(5,5) ; 
    a1.print() ;
    return 0 ; 
}