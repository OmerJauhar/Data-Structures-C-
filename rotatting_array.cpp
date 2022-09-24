#include<iostream>
using namespace std ; 
int * mov_array(int a[] , int b ,int c)
{
    int secondary_array[b] ; 

    for (int i = 0; i < b; i++)
    {
        secondary_array[(i+c)%b] = a[i] ; 
    }

    for (int i = 0; i < b; i++)
    {
        a[i] = secondary_array[i] ; 
    }

    return a ; 
    
    
}

int main()
{
    int array[100]; 
    int size = sizeof(array)/sizeof(array[0]) ; 
    
    for (int i = 0; i < size; i++)
    {
        array[i] = i ; 
    }
    

    cout<<"The length of the array is "<<size<<endl ; 
    

    int number ; 
    cout<<"Enter the number of position you wish to move the array "<<endl ; 
    cin>>number ; 

    int* ptr  = mov_array(array , size , number) ; 




    cout<<"The array after shift is "<<endl ; 
    for (int i = 0; i < number; i++)
    {
        cout<<*(ptr + i)<<endl ; 
    }
    



    

    return 0 ; 
}