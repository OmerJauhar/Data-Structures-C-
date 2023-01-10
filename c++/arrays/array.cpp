#include<iostream>

using namespace std ; 

class queue
{
private:
    int length ; 
    int start ; 
    int end ; 
    int *array_holder ; 
public:
    queue()
    {
        // by default the length will be 100
        length= 100 ; 
        array_holder = new int[length] ; 
        start = end = -1 ;
    }
    queue(int n)
    {
        length = n ; 
        array_holder = new int[n] ; 
        start = end = -1 ; 
    }

    void enqueue(int n)
    {
        if(end = length -1 )
        {
            cout<<"Queue overflowed"<<endl ; 
        }
        else
        {
            if (start == -1)
            {
                start  = 0 ; 
            }
            end++ ; 
            *(array_holder + end) = n ; 
            length ++ ; 
        }
    }

    void dequeue()
    {
        if(start == -1 && end == -1)
        {
            cout<<"Queue is empty"<<endl ; 
        }
        else
        {
            if(start == end)
            {
                start = end = -1 ; 
            }
            start++ ; 
            length -- ; 
        }
    }

    ~queue()
    {
        delete [] array_holder ; 
    }

};

int main()
{

    return 0 ; 
}