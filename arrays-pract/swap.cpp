#include<iostream>
using namespace std ; 
void swap(int array1[] , int array2[] , int n , int m)
{
    cout<<"Printing before swapping"<<endl ; 
    cout<<"array1:"; 
    for (int i = 0; i < n -1; i++)
    {
        cout<<*(array1 ) ;
        array1++ ; 
    }
    cout<<endl; 
    for (int i = 0; i < m -1; i++)
    {
        cout<<*(array2+i) ; 
    }
    cout<<endl; 
    
    
}
int main()
{
    int size1  = 0 ; 
    int size2  = 0 ; 
    int* array = new int[size1] ; 
    *array = 0  ; 
    int* array2  = new int[size2] ;
    *array2 = 0 ;  
    cout<<"Enter elements for array 1"<<endl ; 
    int input1 ; 
    do
    {
        cin>>input1 ; 
        *array = input1 ; 
        array++ ;
        size1++ ;
    } while (input1 != -11);

    cout<<"Enter elements for array 2"<<endl ; 
    int input2 ; 
    do
    {
        cin>>input2 ; 
        *array2 = input2 ;
        array2++ ; 
        size2++ ; 
    } while (input2 != -11);
    swap(array,array2,size1,size2) ; 
    
    
    return 0 ; 
}