#include<iostream>
using namespace std ; 
void fun(int *&array)
{
    cout<<*(array) ; 
}

int main()
{
    int* array = new int[21] ; 
    *(array + 0) = 94 ;
    fun(array) ; 

    return 0; 
}