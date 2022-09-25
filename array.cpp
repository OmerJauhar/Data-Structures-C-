#include<iostream>
using namespace std ; 

class array
{
private:
    int length ; 
    int max ; 
    int *arrayholder ; 
public:
    array()
    {
        // by default the array size will be 100 
        arrayholder = new int[100] ; 
        length = 100 ; 
        max = 0 ; 
        
    }
    array(int n)
    {
        arrayholder = new int[n] ; 
        length = n ; 
        max = n ; 
    }
    
    ~array()
    {
        delete [] arrayholder ; 
    }

    void add(int n)
    {
        for (int i = 0; i < n+1; i++)
        {
            
            cout<<"Enter the number "<<endl ; 
            cin>>*(arrayholder + i ) ; 
            max ++ ; 
        
        }
        
    }
    void remove(int n)
    {
        for (int i = 0; i < length; i++)
        {
            if (*(array_holder) == n)
            {
                for (int j = i; j < length -1 ; j++)
                {
                    arrayholder[j] = arrayholder[j]; 
                }
                
            }
            
        }
        
    }

};

int main()
{
    return 0 ; 
}