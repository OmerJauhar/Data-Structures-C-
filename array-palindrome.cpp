#include<iostream>
#include<string>
#include<cstring>
using namespace std ;
int main()
{
    string meow = "abcddcba" ; 
    char* array = new char[10];
    strcpy(array, meow) ; 
}