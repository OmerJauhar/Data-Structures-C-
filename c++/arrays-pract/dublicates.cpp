#include<iostream>
using namespace std ; 
void bubblesort(int array[] , int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*(array + j) < *(array+j+1) )
            {
                swap(array[j],array[j+1]) ; 
            }
            
        }
        
    }
    
}
int * removedublicates(int array[] , int size)
{
    int* finalarray = new int[size] ; 
    int count = 0 ; 
    for (int j = 0; j < size; j++)
    {
        if (*(array + j) != *(array+j+1) )
        {
         *(finalarray + count) = *(array + j) ; 
            count++ ;  
        } 
    }
    for (int i = 0; i < size ; i++)
    {
        if (*(finalarray +i) != 0)
        {
            cout<<*(finalarray + i) ; 
        }
        
    }
    
    return finalarray ; 
    
}

int main()
{
    int n = 10 ;
    int* meow = new int[n] ; 
    for (int i = n - 1; i != 0; i--)
    {
       if (i % 2 == 0)
       {
        *(meow + i ) = i + 2 ; 
       }
       else
       {
        *(meow + i ) = i + 1 ; 
       }
       
    }
    bubblesort(meow , n) ; 
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<*(meow + i)<<endl ;
    // }
    meow = removedublicates(meow , n ) ; 
    

    
    

    return 0 ; 
}