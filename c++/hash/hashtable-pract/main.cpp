#include<iostream>
#include<list>
using namespace std ; 

class hashtable
{
public:
    list<string> *arrayholder ; 
    int capacity ; 

    hashtable(int n)
    {
        this->capacity = getprime(n) ; 
        arrayholder = new list<string>[this->capacity] ; 
    }
    int checkprime(int n)
    {
        if (n== 0 || n == 1)
        {
            return  0 ; 
        }
        for (int i = 2; i < n/2; i++)
        {
            if (n % i == 0)
            {
                return 0 ;
            } 
        }
        return 1 ; 
    }
    ~hashtable()
    {
        delete[]arrayholder ; 
    }
    int getprime(int n)
    {
        if (n%2 == 0)
        {
            n++ ; 
        }

        while(!checkprime(n))
        {
            n+=2 ; 
        }      
        return n ; 
    }
    int hashfunction(int n)
    {
        return (n % this->capacity) ; 
    }

    void insert(int key , string data)
    {
        int idx = hashfunction(key) ; 
        arrayholder[idx].push_back(data) ; 
    }

    void deletefunction(int key , string data)
    {
        int idx = hashfunction(key) ; 
        list<string>::iterator it ;
        bool flag ;  
        for ( it = arrayholder[idx].begin(); it!=arrayholder[idx].end(); it++)
        {
            if (*it == data)
            {
                flag = true ; 
            }
            
        }
        if (it != arrayholder[idx].end())
        {
            arrayholder[idx].erase(it) ; 
        }
        else
        {
            cout<<"value not at hash table "<<endl ;
        }  
    }

    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout<<"table["<<i<<"]--> ";
            for (auto it  = arrayholder[i].begin(); it!=arrayholder[i].end(); it++)
            {
                cout<<*it<<" "<<endl; 
            }
            cout<<endl ; 
            
        }
        
    }

};

int main()
{
    int rollNo[] = { 231, 321, 212, 321, 433, 262 };
string data[] = {"Anjum", "Asif", "Asad",
"Aslam", "Majid", "Ajaz"};
int size = sizeof(rollNo) / sizeof(rollNo[0]);
hashtable h(size*2);
for (int i = 0; i < size; i++)
h.insert(rollNo[i], data[i]);
h.print();
cout << endl;
// h.searchItem(321, "Ajmil");
    // return 0 ; 
}