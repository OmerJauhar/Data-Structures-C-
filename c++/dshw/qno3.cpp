#include<iostream>
using namespace std;

void function(int N,int n,int array[], int meow )
{
	if(N == 0) 
    {
    return;
    }
	if(n > N)
    {
        return ; 
    }
	if(n == N)
    { 
		for(int i = 0 ; i < N; i++) 
		{
			if(array[i] != 0) 
				cout << array[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i < meow + 1; i++)
    {
        array[n] = i;
	    function(N,n+i,array, meow);
	    array[n] = 0; 
    }
    
}

int main()
{
	int N, A ;  
    cout<<"Enter N:"<<endl ; 
	cin >> N;
    cout<<"Steps at a time:"<<endl ; 
    cin >> A ;
	int  array[N]; 
	for(int i = 0 ; i < N ; i++)
    {
        array[i] = 0;
    } 
	function(N,0,array,A);

	return 0;
}