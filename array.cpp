#include<iostream>
using namespace std ; 

class array
{
private:
    int size ; 
    int max ;  
    int *array_holder ; 

public:
    array()
    {
        this->size = 0  ;
        this->max = 0 ; 
        // this->array_holder = new int[5] ; /*by default it will create an array of length 5*/  


    }
    array(int n, int a , int b)
    {
        this->size = 0 ; 
        this->max = n ; 
 
        this->array_holder = new int[n] ; 
    }

    ~array()
    {
        delete [] array_holder ; 
    }
    
    void set_array()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<"Enter Value for "<< i+1 <<" :"<<endl ; 
            cin>>(array_holder[i]) ; 
        }
        
    }

    // void append()
    // {

    // }

    int size_()
    {
        return this->size ; 
    }

    void print()
    {
        cout<<"ARRAYS: "<<endl ; 
        for (int i = 0; i < this->size; i++)
        {
            cout<<(array_holder[i]) ; 

        }
         
    }    



} ; 

int main()
{
    return 0 ; 
}