#include<iostream>
using namespace std ; 

class queue
{
private:
    int length ; 
    int start_index ; 
    int end_index ; 
    int *imp_array ; 

public: 
    queue()
    {
        /* on default an array of 100 indexes is created  */
        imp_array = new int[100] ;
        this->length = 100 ;  
        this->start_index = -1 ; 
        this->end_index = -1 ; 
    }
    queue(int n)
    {
        imp_array = new int[n] ; 
        this->start_index = -1 ; 
        this->end_index = -1 ; 
        this->length = n ; 
    }

    bool is_empty()
    {
        return ( start_index == -1 && end_index == -1)? true : false ;
    }

    void enqueue(int a )
    {
        if(end_index == length -1 )
        {
            cout<<"Queue overlfow "<<endl ; 
        }
        else
        {
            if(start_index == -1)
            {
                start_index  = 0  ; 
            }
        this->end_index ++ ; 
        *(imp_array + end_index) = a ; 
        }

    }

    void dequeue()
    {
        if(is_empty())
        {
            cout<<"The queue is empty"<<endl ; 
        }
        else
        {
            if(start_index == end_index)
            {
                this->start_index = this->end_index = -1 ; 
            }
        start_index ++ ; 
        length -- ;
        }
    }

    void display()
    {
        if(is_empty())
        {
            cout<<"The queue is empty .. "<<endl ; 
            cout<<start_index<<endl ; 
        }
        else
        {
        cout<<"Printing the elements of the queue "<<endl ;
        for (int i = start_index; i <= end_index; i++)
        {
            cout<<imp_array[i]<<endl ; 
        }
        }
        
    }

    ~queue()
    {
        delete [] imp_array ; 
    }
};

int main()
{
    queue meow1(10) ; 
    meow1.display() ; 

    meow1.enqueue(10) ; 
    meow1.enqueue(10) ;
    meow1.enqueue(10) ;
    meow1.enqueue(10) ;

    meow1.display() ; 

    meow1.dequeue() ; 
    meow1.dequeue() ; 
    meow1.dequeue() ; 

    meow1.display() ; 

    return 0 ; 
}