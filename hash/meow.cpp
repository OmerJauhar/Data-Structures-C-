#include<iostream>
#include<list>
using namespace std ;
class hashtable
{
    public:
    list<string>* table ;
    int capacity ; 
    int checkprime(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0 ; 
        }
        else
        {
            for (int i = 2; i < n/2; i++)
            {
                if (n% i == 0 )
                {
                    return 0 ; 
                }
                
            }
            return 1 ;     
        }
    } 
    int getprime(int n)
    {
        if (n % 2 == 0)
        {
            n+=1 ; 
        }
        while (!checkprime(n))
        {
            n+=2 ; 
        }
        return n ; 
    }
    int hashfunction(int n)
    {
        return (n % this->capacity) ; 
    }
    hashtable(int n)
    {
        int size = getprime(n) ; 
        this->capacity = size; 
        table = new list<string>[size] ; 

    }
    void insert(int index, string a)
    {
        int n = hashfunction(index) ; 
        table[n].push_back(a) ; 
    }
    void deletefunction(int index , string a)
    {

            int meow = hashfunction(index) ; 
            list<string>::iterator i ; 
            for (i = table[meow].begin(); i !=table[meow].end() ; i++)
            {
                if (*i == a)
                {
                    break ; 
                }
            }
            if ( i != table[meow].end())
            {
                table[meow].erase(i) ; 
            }
    }
    
    void displayHash()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "table[" << i << "]";
            for (auto x : table[i])
            cout << " --> " << x;
            cout << endl;
        }
    }

    void search(int index , string a)
    {
            int meow = hashfunction(index) ; 
            list<string>::iterator i ;
            int x ;  
            bool flag = false ; 
            for (i = table[meow].begin() ; i != table[meow].end(); i++)
            {
                if (*i == a)
                {
                    cout<<"Value found at index ["<<meow<<"]["<<x<<"] : "<<a<<endl ;  ; 
                    flag = true ; 
                    break ; 
                }
                x++ ; 
            }
            if (!flag)
            {
                cout<<"Value not found in the table"<<endl; 
            }    
        }
};

int main()
{
int rollNo[] = { 231, 321, 212, 321, 433, 262 };
string data[] = {"Anjum", "Asif", "Asad",
"Aslam", "Majid", "Ajaz"};
int size = sizeof(rollNo) / sizeof(rollNo[0]);
hashtable h(size*2) ; 

for (int i = 0; i < size; i++)
h.insert(rollNo[i], data[i]);
h.displayHash();
cout << endl;
h.search(321, "Ajmil");
return 0 ; 
}