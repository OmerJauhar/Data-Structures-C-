#include<iostream>
using namespace std ; 


int main()
{   
    int n = 10 ; 
    int array[n] ={3,6,5,2,3,6,9,7,1,0} ; 
    

   for (int i = 0; i < n -1; i++)
   {
        for (int j = 0; j < n -i -1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j],array[j+1]) ; 
            }
            
        }
        
   }
   

    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
    

    return 0 ; 
}