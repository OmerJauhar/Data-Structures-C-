#include<iostream>
using namespace std ; 
class maxheap ; 
class node
{
private:
    friend class maxheap;
    int info ; 
};
class maxheap
{
private:
    node* arrayholder ; 
    int totalitems ; 
    int capacity ; 
public:
    maxheap(int n)
    {
        this->arrayholder = new node[n] ; 
        this->capacity = n ; 
        this->totalitems = 0 ; 
    }
    void shiftup(int index)
    {
        if (index<0)
        {
            return ;
        }
        int parent = (index-1)/2 ; 
        if (this->arrayholder[index] <this->totalitems)
        {
            if (this->arrayholder[index].info < this->arrayholder[parent].info)
            {
            swap(this->arrayholder[index],this->arrayholder[parent])
            shiftup(parent);
            }            
        }        
    }
    void shiftdown(int n)
    {
        if (n < 0)
        {
            return ; 
        }
        int maxindex = -1 ;
        int li = n*2+1 ; 
        int ri = n*2+2 ; 

        if (li < this->totalitems)
        {
            if (this->arrayholder[li].info > this->arrayholder[n].info)
            {
                maxindex = li ; 
            }
            
        }

        if (ri < this->totalitems)
        {
            int newindex =( maxindex == -1 ? index : maxindex );
            if (this->arrayholder[newindex].info < this->arrayholder[ri].info )
            {
                maxindex = ri ; 
            }
        }
        if (maxindex == -1)
        {
            return ; 
        }
        swap(this->arrayholder[index],this->arrayholder[maxindex]);
        shiftdown(maxindex);  

    }
};