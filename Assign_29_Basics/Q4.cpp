/*Write a C++ program to calculate the area of circle.*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    float radius;
    cout<<"Enter Radius of circle: ";
    cin>>radius;
    cout<<"Area of circle is "<<3.14*radius*radius;
    getch();
    return 0;
}