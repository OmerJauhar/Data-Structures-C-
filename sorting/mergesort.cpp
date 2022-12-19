#include<iostream>
using namespace std ; 


void merge(int array[] , int l , int mid , int r)
{
    int n1 = mid+1 -l ; 
    int n2 = r - mid ; 

    int a1[n1] ; 
    int a2[n2] ; 

    for (int i = 0; i < n1; i++)
    {
        a1[i] = array[l+i] ; 
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = array[mid+1 +i] ; 
    }
    int i = 0 ; 
    int j = 0 ;  
    int k = l ; 

    while(i<n1 && j<n2)
    {
        if (a1[i] < a2[j])
        {
            array[k] = a1[i] ; 
            i++ ; 
            k++ ; 
        }
        else
        {
            array[k] = a2[j] ; 
            k++ ; 
            j++ ; 
        }
        
    }

    while (i <n1)
    {
        array[k] = a1[i] ; 
        k++ ; 
        i++ ; 
    }
    
    while (j <n2)
    {
        array[k] = a2[j] ; 
        k++ ; 
        j++ ; 
    }

}


void mergesort(int array[], int l , int r)
{
    if (l<r)
    {
        int mid = (l+r)/2 ; 
        mergesort(array,0,mid) ; 
        mergesort(array,mid+1,r) ;
        merge(array , l , mid , r) ;  
    }

}

int main()
{
    int n = 10 ; 
    int array[n] ={3,6,5,2,3,6,9,7,1,0} ; 
    

   mergesort(array,0,n-1) ;
   

    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0 ; 
}