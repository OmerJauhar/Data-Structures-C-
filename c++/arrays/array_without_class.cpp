#include<iostream>
#include<conio.h>
#include<process.h>
int length = 0;
void create();
void insert();
void deletion();
void search();
void display();
int size();
int a, b[20], n, d, e, f, i;
using namespace std;
int main()
{
int c;
cout << "\n Main Menu";
cout << "\n 1.Create \n 2.Delete \n 3.Search \n 4.insert \n 5.Display \n
6.Exit";
do
{
cout << "\n enter your choice:";
cin >> c;
switch (c)
{
case 1:
create();
break;
case 2:
deletion();
break;
case 3:
search();
break;
case 4:
insert();
break;
case 5:
display();
break;
case 6:
exit(0);
break;
default:
cout << "The given number is not between 1-5\n";
}
} while (c <= 6);
getch();
}
void create()
{
cout << "\n Enter the number of elements you want to create: ";
cin >> n;
length = n;
cout << "\nenter the elements\n";
for (i = 0; i < n; i++)
{
cin >> b[i];
}
}