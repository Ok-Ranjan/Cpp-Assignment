#include<iostream>
using namespace std;

/*1.Define a class Complex and overload follwing operator as a friend.*/
// 1.+ ,2.- ,3.*
class Complex{
    private:
        int a,b;
    public:
        Complex(int a=0,int b=0):a(a),b(b){}
        void showCom();
        friend Complex operator+(Complex,Complex);
        friend Complex operator-(Complex,Complex);
        friend Complex operator*(Complex,Complex);
        friend Complex operator-(Complex);
};
void Complex::showCom(){
    cout<<"real="<<a<<" imag="<<b;
}
Complex operator+(Complex c1,Complex c2){
    Complex temp;
    temp.a=c1.a+c2.a;
    temp.b=c1.b+c2.b;
    return temp;
}
Complex operator-(Complex c1,Complex c2){
    Complex temp;
    temp.a=c1.a-c2.a;
    temp.b=c1.b-c2.b;
    return temp;
}
Complex operator*(Complex c1,Complex c2){
    Complex temp;
    temp.a=c1.a*c2.a-c1.b*c2.b;
    temp.b=c1.a*c2.b+c1.b*c2.a;
    return temp;
}

/*2.Define a class Time with appropriate instance variables and member functions.Overload following operators*/
// 1.<<insertion operator , 2.>>extraction operator
class Time{
    private:
        int hr,min,sec;
    public:
        Time(int h=0,int m=0,int s=0):hr(h),min(m),sec(s){}
        void showTime(){cout<<hr<<":"<<min<<":"<<sec;}
        friend ostream& operator<<(ostream&,Time);  //insertion operator
        friend istream& operator>>(istream&,Time);  //extraction operator
        Time& operator=(Time);
};
ostream& operator<<(ostream& dout,Time t){
    dout<<t.hr<<":"<<t.min<<":"<<t.sec;
    return dout;
}
istream& operator>>(istream& din,Time t){
    din>>t.hr>>t.min>>t.sec;
    return din;
}

/*3.In question-2, over load operator= to perform copy of time object.*/
Time& Time::operator=(Time t){
    hr=t.hr;
    min=t.min;
    sec=t.sec;
    return *this;
}

/*4.Consider the follwing class Array*/
//define operator= to perform deep copy of Array objects.
class Array{
        int *p;
        int size;
    public:
        Array():p(NULL),size(-1){}
        void inputArray(){
            for(int i=0;i<size;i++)
                    cin>>p[i];
        }
        void showArr(){
            for(int i=0;i<size;i++)
                    cout<<p[i];
        }
        Array& operator=(Array arr){
            size=arr.size;
            if(p!=NULL){
                delete []p;
                p=NULL;
            }
            if(arr.p!=NULL){
                p=new int[size];
                for(int i=0;i<size;i++)
                    p[i]=arr.p[i];
            }
            return *this;
        }
        friend Array  operator+(Array A,Array B);

};

/*5.In question-4, define a friend operator+ to concatenate two Array objects.*/
Array operator+(Array A,Array B){
    Array C;
    int i,j;
    C.size=A.size+B.size;
    C.p=new int[C.size];
    for(i=0;i<A.size;i++)
        C.p[i]=A.p[i];
    for(i=A.size,j=0;i<C.size;i++,j++)
        C.p[i]=A.p[j];
    return C;
}

/*6.In question-1,provide a unary friend operator- to negate the real and imaginary part of a Complex number.*/
Complex operator-(Complex c){
    Complex temp;
    temp.a=-c.a;
    temp.b=-c.b;
    return temp;
}
/*7.Define a class Integer with instance variable of type int. Provide a friend logical
operator not !. Also define a friend operator== to compare two Integer objects.*/
class Integer{
    private:
        int a;
    public:
        friend bool operator!(Integer);
        friend bool operator==(Integer,Integer);
};
bool operator!(Integer i){
    if(i.a==false)
        return true;
    return false;
}
bool operator==(Integer i1,Integer i2){
    if(i1.a==i2.a)
        return true;
    return false;
}

/*8.Create a Coordinate class with 2 Instance variables x and y. Overload comma operator such that when
c3 = (c1,c2) then c2 is assigned to c3. where c1,c2 and c3 are objects of 3D coordinate class.*/
class Coordinate{
    int x,y;
    public:
        friend Coordinate operator,(Coordinate,Coordinate);
        friend istream& operator>>(istream &din,Coordinate c);
        friend ostream& operator<<(ostream &dout,Coordinate c);
};
Coordinate operator,(Coordinate c1,Coordinate c2){
    Coordinate temp;
    temp.x=c2.x;
    temp.y=c2.y;
    return temp;
}

/*9.In question-8, provide overload insertion and extraction operators.*/
ostream& operator<<(ostream &dout,Coordinate c){
    dout<<c.x<<" "<<c.y;
    return dout;
}
istream& operator>>(istream &din,Coordinate c){
    din>>c.x>>c.y;
    return din;
}

/*10.Define a class Student with roll no,name and age as instance variables. Create setStudent() and
showStudent() methods in the class. Overload operator == to compare two student objects.*/
class Student{
    private:
        int rollNo;
        string name;
        int age;
    public:
        void setStudent(int r,string n,int a){
            rollNo=r;
            name=n;
            age=a;
        }
        void showStudent(){
            cout<<rollNo<<" "<<name<<" "<<age;
        }
        bool operator==(Student s){
            if(*this==s)
                return true;
            return false;
        }
};