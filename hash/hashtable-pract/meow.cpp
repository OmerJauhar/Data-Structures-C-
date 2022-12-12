#include<iostream>
#include<list>
using namespace std ;
class hashtable
{
private:
    list<string>* table ; 
    int capacity ; 
public:
    hashtable(int n )
    {
        this->capacity = getprime(n) ; 
        table = new list<string>[this->capacity] ; 
    }
    ~hashtable()
    {
        delete[] table; 
    }
    int checkprime(int n)
    {
        if (n == 0 || n ==1 )
        {
            return 0 ;
        }
        for (int i = 2; i < n/2; i++)
        {
            if (n%i==0)
            {
                return 0 ; 
            }
        }
        return 1 ;
    }
    int getprime(int n)
    {
        if (n%2==0)
        {
            n++ ; 
        }
        while (!checkprime(n))
        {
            n+=2 ; 
        }
        return  n ;         
    }
    int hashfunction(int n)
    {
        return n% this->capacity ; 
    }

    void insert(int key , string data )
    {
        int idx = hashfunction(key) ; 
        table[idx].push_back(data) ; 
    }
    void deletefunction(int key , string data)
    {
        int idx = hashfunction(key) ; 
      list<string>::iterator it ;
      bool flag ; 
      for ( it = table[idx].begin();it!=table[idx].end(); it++)
      {
        if (*it == data)
        {
            flag = true ;
            break ; 
        }
        
      }
      if(it != table[idx].end())
      {
        table[idx].erase(it); 
      }
      else
      {
        cout<<"Value not found"<<endl ; 
      }

         
    }

    void search(int key , string data)
    {
        list<string>::iterator it ;
        int idx = hashfunction(key)  ;  
        bool flag ; 
        int i = 0 ; 
        for ( it = table[idx].begin(); it!=table[idx].end(); it++)
        {
            if (*it == data)
            {
                flag = true ; 
                cout<<"Value found at index table["<<idx<<"]["<<i<<"] --> "<<*it<<endl ; 
                break ; 
            }
            i++ ; 
            
        }
        if (!flag)
        {
            cout<<"Value not found "<<endl ; 
        }
    }

    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout<<"HashTable["<<i<<"] -->";
            for (auto it :table[i])
            {
                cout<<it<<endl ; 
            }
            cout<<endl;
            
        }
        
    }
};
int main()
{
    return 0 ; 
}