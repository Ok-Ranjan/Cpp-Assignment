/*Write a C++ program to calculate an average of 3 numbers.*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    float a,b,c;
    cout<<"Enter three number: ";
    cin>>a>>b>>c;
    cout<<"Average of three number = "<<(a+b+c)/3;
    getch();
    return 0;
}