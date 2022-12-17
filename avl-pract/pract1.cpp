#include <iostream>
using namespace std;
void temp(int *, int *);
int main () {
int a, b;
a=10;
b=20;
temp(&a, &b); // function calling
cout<<"Value of a= "<<a<<endl;
cout<<"Value of b= "<<b<<endl;
cout<<"OK"<<endl;
return 0;
}
void temp(int *x, int *y)
{
*x = *x+100;
*y = *y+100;
}