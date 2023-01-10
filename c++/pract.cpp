#include<iostream>
using namespace std ; 
void function(int* a , int* b, int c)
{

    if (c > *b)
    {
        return ; 
    }
    cout<<*a<<" * "<<c<<" = "<<(*a)*(c)<<endl; ; 
    function(a,b,c+=1);
    
}
int main()
{
    int a ; 
    int b; 
    cout<<"Enter the value of the table"<<endl ; 
    cin>>a ; 
    cout<<"Enter the limit of the table"<<endl ; 
    cin>>b ; 
    cout<<a<<b<<endl;
    function(&a,&b,0);
    cout<<"After function"<<endl;  
    return 0 ; 
}