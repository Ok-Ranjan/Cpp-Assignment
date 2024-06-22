/*Write a C++ program to find the maximum of two numbers.*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    if(a>=b)
      cout<<"Muximum is "<<a;
    else
      cout<<"Muximum is "<<b;
    getch();
    return 0;
}