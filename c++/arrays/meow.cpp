#include<iostream>
using namespace std ; 
int * fun(int *array)
{
    cout<<*(array) ;
    return array ;  
}

int main()
{
    int* array = new int[21] ; 
    *(array + 0) = 94 ;
    int * array1 = fun(array) ;
     

    return 0; 
}