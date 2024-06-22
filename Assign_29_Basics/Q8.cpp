/*Write a C++ program to swap values of two int variables without using thrid variable.*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a,b;;
    cout<<"Enter the value of a: ";  cin>>a;
    cout<<"Enter the value of b: ";  cin>>b;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<"\tb="<<b;
    getch();
    return 0;

}
