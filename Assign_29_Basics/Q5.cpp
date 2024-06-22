/*Write a C++ program to calculate the volume of cuboid.*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int l,h,w;
    cout<<"Enter the Lenght of cuboid: ";
    cin>>l;
    cout<<"Enter the hight of cuboid: ";
    cin>>h;
    cout<<"Enter the width of cuboid: ";
    cin>>w;
    cout<<"Volume of cuboid is "<<l*h*w;
    getch();
    return 0;
}
