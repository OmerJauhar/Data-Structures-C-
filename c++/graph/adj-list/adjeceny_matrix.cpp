#include<iostream>
using namespace std ; 
class arrays
{
    public:
        int *arrayholder ; 
        int a ; 
        int b ; 
    arrays(int n, int m)
    {
        this->a = n ; 
        this->b = m ; 
        arrayholder = new int[n * m] ; 
    }
    void addedge(int start_index , int end_index )
    {
        *(arrayholder + (start_index-1) * b + (end_index -1)) = 1 ; 
    }
    void print()
    {
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout<<*(arrayholder +i * b + j)<<" ";
            }
            cout<<endl ; 
            
        }
        
    }
    int counter(int m)
    {
        static int c = 0 ; 
        for (int i = 0; i < this->b; i++)
        {
            if (*(arrayholder + m * i) == 1)
            {
                c++ ; 
            }
            
        }
        return c ;
    }
};
int main()
{
    arrays a1(8, 7) ; 
    a1.addedge(1,2) ; 
    a1.addedge(2,3) ; 
    a1.addedge(4,5) ; 
    a1.addedge(1,5) ; 
    a1.addedge(6,1) ; 
    a1.addedge(7,4) ;
    a1.addedge(3,8) ; 

    a1.print();
    cout<<a1.counter(3) ; 
    return 0 ; 
}