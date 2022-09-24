#include<iostream>
using namespace std ; 


class stack 
{
private:
	int size ; 
	int top ; 
	int *stack_array ; 
public:
	stack()
	{
		this->top = -1 ; 
		this->size = 100 ; 
		stack_array = new int[100] ; 
		/* default array size will be 100 */
	}
	stack(int n )
	{
		this->top = -1 ;
		this->size = n ; 
		stack_array = new int[n] ;  
	}
	~stack()
	{
		delete [] stack_array ; 
	} 
	void push(int n)
	{
		if(top == size - 1)
		{
			cout<<"Stack overflow "<<endl ; 

		}
		else
		{
			top ++ ; 
			stack_array[top] = n ; 
		}
	}


	void pop()
	{
		if (this->top <= -1)
		{
			cout<<"Stack Underflow"<<endl ; 
		}
		else
		{
			
			int num ; 
			num = stack_array[top] ; 
			top -- ; 
			cout<<"Deleted "<<num<<endl ; 
		}
		
	}
	void display()
	{
		if(top == -1)
		{
			cout<<"stack is empty"<<endl ; 
		}
		else
		{
			for (int i = top+1; i >= 0 ; i--)
			{
				cout<<*(stack_array + i)<<endl ; 
			}
			
		}
	}
	bool is_empty() 
	{
		if (size == 0 )
		{
			return true ; 
		}
		else
		{
			return false  ;
		}
		
		
	}
	

};

int main()

{

	cout<<"Start of the program"<<endl ; 

	stack s1(100) ; 

	s1.display() ; 

	s1.push(110) ; 
	s1.push(20) ; 
	s1.push(30) ; 
	s1.push(140) ;
	s1.display() ;

	s1.pop() ; 
	s1.pop() ; 

	s1.display() ;  



return 0 ; 
}
