#include<iostream>
#include<math.h>
using namespace std;
int add(int,int,int=0);

/*1.Define a function to check whether a given number is a prime number or not.*/
bool IsPrime(int n){
    int i;
    for(i=2;i<n;i++)
        if(n%i==0)
            return false;
    return true;
}

/*2.Define a function to find the highest value digit in a given number.*/
int highest_digit(int num){
    int i,max=0;
    while(num){
        if((num%10)>max)
            max=num%10;
        num/=10;
    }
    return max;
}

/*3.Define a function to calculate x raised to the power y.*/
double power(double x,double y){
    if(y>0)
        return x*power(x,y-1);
    else if(y<0)
        return 1/x*power(x,y+1);
    else
        return 1;
}

/*4.Define a function to print Pascal Triangle up to N lines.*/
int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}
int combi(int n,int r){
    return fact(n)/fact(r)/fact(n-r);
}
void pascal_triangle(int n){
    int i,j,r;
    bool k;
    for(i=1;i<=n;i++){
        k=true;
        r=0;
        for(j=0;j<2*n-1;j++){
            if(j>=n-i&&j<=(n-2)+i){
                if(k){
                    printf("%2d",combi(i-1,r++));
                    k=false;
                }
                else{
                    cout<<"   ";
                    k=true;
                }
            }
            else
                cout<<"   ";
        }
        cout<<endl;
    }
}

/*5.Define a function to check whether a given number is a term in a Fibonacci series or not.*/
bool isTerm_fib(int num){
    int i=-1,j=1,k=0;
    while(i+j<num){
        k=i+j;
        i=j;
        j=k;
        if(num==i+j)
            return true;
    }
    return false;
}

/*6.Defien a function to swap data of two int variables using call by reference.*/
inline void swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

/*7.Write a function using the default argument that is able to add 2 or 3 numbers.*/
inline int add(int a,int b,int c){
    return a+b+c;
}

/*8.Define overloaded functions to calculate area of circle, area of rectangle and area of traingle.*/
inline float calArea(int r){
    return 3.14*r*r;
}
inline int calArea(int l,int b){
    return l*b;
}
inline int calArea(int a,int b,int c){
    double s;
    s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

/*9.Write functions using function overloading to find a maximum of two numbers and both the numbers
can be integer or real.*/
inline int find_max(int a,int b){
    return a>b?a:b;
}
inline double find_max(double a,double b){
    return a>b?a:b;
}

/*10.Write functions using function overloading to add two numbers having different data types.*/
int add(int a,int b){
    return a+b;
}
inline double add(double a,double b){
    return a+b;
}

int main(){
    pascal_triangle(10);
}