#include<iostream>
#include<string.h>
using namespace std;

/*1.Define a class Cuboid wtih lenght, breadth and height as instance member
variable. Define constructors to initialise member variables.*/
class Cuboid{
    private:
        int lenght,breadth,height;
    public:
        Cuboid(int l,int b,int h)
        {
            lenght=l;
            breadth=b;
            height=h;
        }
};

/*2.Define a class Customer with instance member cust_id,name,email,mobile.
Define non parameterised constructor and parameterised constructor in the class.*/
class Customer{
    private:
        int cust_id;
        string name,email,mobile;
    public:
        Customer()  //Non parameterised Constructor
        {
            cust_id=0;
            name="Anonymous";
            email="xyz@example.com";
            mobile="8709751861";
        }
        Customer(int id,string n,string e,string m):cust_id(id),mobile(m) //parameterised constructor
        {
            cust_id=id;
            name=n;
            email=e;
            mobile=m;
        }
};

/*3.Define a class Time with hr,min,sec as instance member variables.
Define constructor to initialise time object.*/
class Time{
    private:
        int hr,min,sec;
    public:
        Time():hr(-1),min(-1),sec(-1){}
        Time(int h,int m,int s):hr(h),min(m),sec(s){}
};

/*4.Define a class Book with bookId,title and price as instance member variables.
Define non parameterised and parameterised constructor in the class.*/
class Book{
    private:
        int book_id;
        string title;
        int price;
    public:
        Book():book_id(-1),price(00)    //Non parameterised Constructor
        {
            title="Nothing";
        }
        Book(int id,string t,int p)     //Parameterised Constructor
        {
            book_id=id;
            title=t;
            price=p;
        }
};

/*5.Define a class Complex with instance variables for real and imaginary part of a complex number.
Define only one parameterised constructor in the class to initialise complex object. Also define
showData method in the class to display object data. Now create an array of Complex class with
size of 5 and display values of each object.*/
class Complex{
    private:
        int a,b;
    public:
        Complex(int a,int b):a(a),b(b){}
        void showData(){
            cout<<"real="<<a<<"  "<<"imaginary="<<b;
        }
};
void example(){
    Complex C[5]={Complex(4,5),Complex(10,20),Complex(7,8),Complex(12,17),Complex(30,18)};
    for(int i=0;i<5;i++)
        C[i].showData();
}

/*6.Define a class Numbers with size and arr pointer as instance variables.Proide constructor to initialise
instance members, dynamically allocate an array of given size and store address in arr variable of object.
Also define destructor to deallocate memory of array. Implement deep copy using copy constructor to avoid memory issues.*/
class Numbers{
    private:
        int size;
        int *arr;
    public:
        Numbers(){
            size=-1;
            arr=NULL;
        }
        Numbers(int n){
            size=n;
            arr=(int*)malloc(size*sizeof(int));
        }
        Numbers(Numbers &N){
            size=N.size;
            arr=(int*)malloc(size*sizeof(int));
            for(int i=0;i<size;i++)
                arr[i]=N.arr[i];
        }
        void create(int n){
            size=n;
            if(arr!=NULL)
                free(arr);
            arr=(int*)malloc(size*sizeof(int));
        }
        ~Numbers(){
            free(arr);
        }

};

/*7.Define a class student and write a program to enter student details using
constructor and define member function to display all the details.*/
class Student{
    private:
        int rollNo;
        string name;
    public:
        Student();
        void displayStu();
};
Student::Student(){
    cout<<"Enter RollNo: ";
    cin>>rollNo;
    cout<<"Enter Name: ";
    cin>>name;
}
void Student::displayStu(){
    cout<<rollNo<<" "<<name;
}

/*8.Define a class Date with d,m,y as instance variables. Initialise members using initialisers.*/
class Date{
    private:
        int d,m,y;
    public:
        Date():d(0),m(0),y(0){}
        Date(int d,int m,int y):d(d),m(m),y(y){}
};

/*9.Define a class Room for a hotal management project with room number, room type,
is_Ac, price as instance variables. Initialise instance variables using constructor.*/
class Room{
    private:
        int room_num;
        string room_type;
        bool is_Ac;
        int price;
    public:
        Room(int,string,bool,int);
};
Room::Room(int num,string type,bool isAc,int p){
    room_num=num;
    room_type=type;
    is_Ac=isAc;
    price=p;
}

/*10.Define Circle class with radius as instance variable. Define two Constructors in the
class non parameterised and parameterised.*/
class Circule{
    private:
        int radius;
    public:
        Circule()   //Non parameterised Constructor
        {
            radius=0;
        }
        Circule(int r)  //Parameterised Constructor
        {
            radius=r;
        }
};
