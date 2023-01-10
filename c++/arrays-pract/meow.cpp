#include<iostream>
using namespace std ; 


class arraylist
{
private:
    int* arr ; 
    int* curr ; 
    int info ;
    int count ; 
public:
    int size  ; 
    arraylist()
    {
        size = 10 ; 
        arr = new int[size] ; 
    }
    arraylist(int n)
    {
        this->size = n ; 
        arr = new int[n] ; 
    }
    ~arraylist()
    {
        delete[]arr ;
        free(curr); 

    }
    void head()
    {
        curr = arr ; 
    }
    void tail()
    {
        curr = arr + size-1 ; 
    }
    void insert(int val)
    {
        if (!isfull())
        {
            head() ; 
            curr = curr + count ; 
            *curr = val ; 
            count++ ; 
        }
        else
        {
            cout<<"Array is full"<<endl ; 
        }
    }
    void insertatpos(int val , int pos)
    {
        if (pos < count && pos > 1 )
        {
            tail() ; 
            for (int i = count ; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                 curr-- ; 
            }
            curr++ ; 
            *(curr) = val ; 
            count++; 
            
        }
        else if(pos > count && pos< size )
        {
            head() ; 
            curr = curr + pos -1 ; 
            *curr = val ; 
            count++;
        }
        else
        {
            cout<<"Wrong position"<<endl ; 
        } 
    }
    bool isfull()
    {
        return (this->count == this->size) ; 
    }
        void printArray() {
        if (count > 0) {
            head();
        for (int x = 0; x < count; x++)
                cout << *curr++ << "\t";
        }
        else cout << "Array is Empty" << endl;
    }

};
int main()
{
    arraylist* a1 = new arraylist(12) ;  
    a1->insert(1)  ; 
    a1->printArray() ; 
    
    return 0 ; 
}