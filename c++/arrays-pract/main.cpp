#include<iostream>
using namespace std ; 

int sizeofarray(int a[] , int b[] , int s1 , int s2 ) ; 
int* common(int a[] , int b[] ,int s1 , int s2) ; 
void removedublicates(int *a , int size) ; 

int main()
{
    int n = 10 ; 
    int m = 10 ; 
    int* array1 = new int[n] ;
    int* array2 = new int[m] ; 

    for (int i = 0; i < n; i++)
    {
        *(array1 + i) = i+2 ; 
    }

    for (int i = 0; i < m; i++)
    {
        *(array2 + i) = i ; 
    }
    int* resultarraymain = common(array1,array2,n,m) ; 
    removedublicates(resultarraymain,sizeofarray(array1,array2,n,m)) ;

 
    return 0 ;
}
void removedublicates(int *a , int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<*(a + i)<<"  "; 
    }

    
}
int sizeofarray(int a[] , int b[] , int s1 , int s2 )
{
    int size = 0 ; 
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if ((*(a + i)) == (*(b + j)))
            {
                size+= 1 ; 
            }
        } 
    }
    return size ; 
}

int* common(int a[] , int b[] , int s1 , int s2 )
{
    int size = sizeof(a , b , s1 , s2 ) ; 
    int* resultarray = new int[size] ; 
    int meow = 0; 
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if ((*(a+ i)) == (*(b + j)))
            {
                *(resultarray + meow ) = *(b+j) ; 
                meow += 1 ; 
            }
            
        }
        
    }
    return resultarray ; 
}




