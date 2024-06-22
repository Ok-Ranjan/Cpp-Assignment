#include<iostream>
#include<string.h>
#include<string>
using namespace std;
void sort(int A[],int,bool=true);
void sort(string*,int,bool=true);
void rotate(int A[],int size,int d=1,int n=1);
int LCM(int,int,int=1);
void subString(char[],int,int=-1);

/*1.Define a function to sort an array of itegers in ascending or descending order depending on bool
type argument(true for ascending and false for descending). Use default argument to implement it.*/
void ascending_order(int A[],int s){
    int r,i,t;
    for(r=1;r<s;r++){
        for(i=0;i<s-r;i++){
            if(A[i]>A[i+1]){
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
    }
}
void descending_order(int A[],int s){
    int r,i,t;
    for(r=1;r<s;r++){
        for(i=0;i<s-r;i++){
            if(A[i]<A[i+1]){
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
    }
}
void sort(int A[],int size,bool d){
    if(d)
        ascending_order(A,size);
    else
        descending_order(A,size);
}
void f1(){
    int arr[]={23,65,13,52,56,22,11,5,80};
    sort(arr,9,false);
    for(int i=0;i<9;i++)
        cout<<arr[i]<<" ";
}

/*2.Define a function to sort an array of strings in ascending or descending order depending on bool type
argument(true for ascending and false for descending). Use default argument to implement it.*/
void ascending_order(string *str,int s){
    int r,i;
    for(r=1;r<s;r++){
        for(i=0;i<s-r;i++){
            if(str[i].compare(str[i+1])>0){
                str[i].swap(str[i+1]);
            }
        }
    }
}
void descending_order(string *str,int s){
    int r,i;
    for(r=1;r<s;r++){
        for(i=0;i<s-r;i++){
            if(str[i].compare(str[i+1])<0){
                str[i].swap(str[i+1]);
            }
        }
    }
}
void sort(string *str,int size,bool d){
    if(d)
        ascending_order(str,size);
    else
        descending_order(str,size);
}
void f2(){
    string str[5];
    str[0].assign("Ranjan");
    str[1].assign("Mukesh");
    str[2].assign("Rahul");
    str[3].assign("Banti");
    str[4].assign("Rohit");
    sort(str,5);
    for(int i=0;i<5;i++)
        cout<<str[i]<<endl;
}

/*3.Define a function to rotate an array by n positions in the d direction. Implement postion and direction
using default arguments. Argument d can be -1 or 1 denoting left or right direction. Argument n should be the
last argument with default value 1.*/
void left_rotate(int arr[],int size){
    int i,temp=arr[0];
    for(i=0;i<size-1;i++)
        arr[i]=arr[i+1];
    arr[i]=temp;
}
void right_rotate(int arr[],int size){
    int i,temp=arr[size-1];
    for(i=size-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[i]=temp;
}
void rotate(int A[],int size,int d=1,int n=1){
    if(d==1){
        while(n){
            right_rotate(A,size);
            n--;
        }
    }
    else if(d==-1){
        while(n){
            left_rotate(A,size);
            n--;
        }
    }
}
void f3(){
    int A[]={5,8,12,19,7};
    rotate(A,5,-1,2);
    for(int i=0;i<5;i++)
        cout<<A[i]<<" ";
}

/*4.Defien a function to calculate LCM of three numbers.*/
int LCM(int a,int b,int c){
    int i=2,j,mul=1;
    while(a>1||b>1||c>1){
        if(a%i==0||b%i==0||c%i==0){
            if(a%i==0)
                a/=i;
            if(b%i==0)
                b/=i;
            if(c%i==0)
                c/=i;
            mul*=i;
        }
        else
            i++;
    }
    return mul;
}

/*5.Define a function to print all the prime factors of given number.[for example num=36, prime factors are 2,3]*/
bool isPrime(int n){
    int i;
    for(i=2;i<n;i++)
        if(n%i==0)
            return false;
    return true;
}
int nextPrime(int n){
    while(!isPrime(++n));
    return n;
}
void primeFactors(int num){
    int i;
    for(i=2;i<=num;i=nextPrime(i))
        if(num%i==0)
                cout<<i<<" ";
}

/*6.Define a function to calculate HCF of two numbers.*/
int HCF(int a,int b){
    int i;
    for(i=a<b?a:b;i>0;i--){
        if(a%i==0&&b%i==0)
            return i;
    }
    return 1;
}

/*7.Define overloaded functions to calculate volume of a cuboid, cone and sphere*/
int cal_volume(int l,int b,int h) //cuboid
{
    return l*b*h;
}
float cal_volume(int r,int h) //cone
{
    return (1*3.141*r*r*h)/3;
}
float cal_volume(int r) //sphere
{
    return (4*3.141*r*r*r)/3;
}

/*8.Define a function to print a substring from startIndex(inclusive) to endIndex(exclusive).
Define function in such a way that if second argument is not provided, string will print till the last possible index.*/
void subString(char str[],int start_index,int end_index){
    int i,l;
    if(end_index==-1)
        end_index=strlen(str);
    for(i=start_index;i<end_index;i++){
        cout<<str[i];
    }
}
void f8(){
    char str[]="Ranjan is a boy";
    subString(str,7,11);
}

/*9.Define a function to swap two arrays.*/
void swap(int A[],int B[],int size){
    int i,t;
    for(i=0;i<size;i++){
        t=A[i];
        A[i]=B[i];
        B[i]=t;
    }
}
void f9(){
    int A[]={23,61,45,12,54,36,79};
    int B[]={12,75,33};
    swap(A,B,sizeof(B)/sizeof(int));
    for(int i=0;i<sizeof(A)/sizeof(int);i++)
        cout<<A[i]<<" ";
    cout<<"\n";
    for(int i=0;i<sizeof(B)/sizeof(int);i++)
        cout<<B[i]<<" ";
}

/*10.Define a function to merge two sorted arrays of same size.*/
int* merge(int A[],int B[],int size){
    int i,j,k,*C=(int*)malloc(2*size*sizeof(int));
    for(i=0,j=0,k=0;i<size&&j<size;k++){
        if(A[i]<B[j]){
            C[k]=A[i];
            i++;
        }
        else{
            C[k]=B[j];
            j++;
        }
    }
    while(i<size){
        C[k]=A[i];
        k++;
        i++;
    }
    while(j<size){
        C[k]=B[j];
        j++;
        k++;
    }
    return C;
}
void f10(){
    int A[]={23,45,54,63,79};
    int B[]={12,33,54,84,90};
    int *C=merge(A,B,sizeof(A)/sizeof(int));
    for(int i=0;i<2*sizeof(A)/sizeof(int);i++)
        cout<<C[i]<<" ";
}

int main(){
    // cout<<cal_volume(14,8);
    f3();
    return 0;
}