#include<iostream>
using namespace std ;

class adjmatrix
{
private:
    int n ;
    int m ; 
    int* arrayholder ; 
public:
    adjmatrix(int n ) 
    {
        this->n = n ; 
        this->m = n ; 
        arrayholder = new int[n*m] ; 
    }
    void addedge(int start , int end , int cost)
    {
        *(arrayholder +(start -1) * this->m + (end -1)) = cost ; 
    }

    void print()
    {
        cout<<"      ";
        for (int i = 0; i < this->n; i++)
        {
            cout<<i+1<<" " ; 
        }
        cout<<endl;
        cout<<"      "; 
        for (int i = 0; i < this->n; i++)
        {
            cout<<"|"<<" ";
        }
        
        cout<<endl; 
        cout<<"      "; 
        for (int i = 0; i < this->n; i++)
        {
            cout<<"v"<<" ";
        }
        
        cout<<endl;
        cout<<endl ;  
        
        for (int i = 0; i < this->n; i++)
        {
            cout<<i+1<<"-->  " ; 
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
    a1.addedge(1,1,2) ; 
    a1.print() ; 
    return 0 ; 
}