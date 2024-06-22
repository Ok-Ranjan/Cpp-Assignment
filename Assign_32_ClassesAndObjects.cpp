#include<iostream>
using namespace std;

/*1.Define a class Complex to represent a complex number. Declare instance member
variable to store real and imaginary part of a complex number, also define instance
member functions to set values of complex number and print values of complex number.*/
class Complex{
    private:
        int real;
        int imag;
    public:
        void setValues(int r,int i);
        void printValue();
};
void Complex::setValues(int r,int i){
    real=r;
    imag=i;
}
void Complex::printValue(){
    cout<<"\nreal="<<real<<"imaginary="<<imag;
}

/*2.Define a class Time to represent Time (like 3 hr 45 min 20 sec). Declare appropriate
number of instance member variables and also define instance member function to set values
for time and display values of time.*/
class Time{
    private:
        int hr,min,sec;
    public:
        void setTime(int h,int m,int s){
            hr=m;
            min=m;
            sec=s;
        }
        void showTime(){
            cout<<hr<<"hr "<<min<<"min "<<sec<<"sec";
        }
};

/*3.Define a class Date to represent date (like d=31, m=12, y=2022).Declare appropriate number
of instance member variables and also define instance member function to set data and get date.*/
class Date{
    private:
        int day,month,year;
    public:
        void setDate(int d,int m,int y){
            day=d;
            month=m;
            year=y;
        }
        void showDate(){
            cout<<"d="<<day<<" m="<<month<<" y="<<year;
        }
        void showDateFormate1();
        void showDateFormate2();
};

/*4.In question 3, define a methods to display date in the following pattern
    1. 31-12-2022   &   2. 31-Dec-2022 */
void Date::showDateFormate1(){
    cout<<day<<"-"<<month<<"-"<<year;
}
void Date::showDateFormate2(){
    char *months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    cout<<day<<"-"<<months[month-1]<<"-"<<year;
}

/*5.Define a class Circle with radius as its property. Provide setRadius() and getRadius()
methiods. Also define methods to return area and circumference of circle.*/
class Circle{
    private:
        int radius;
    public:
        void setRadius(int r){
            radius=r;
        }
        int getRadius(){
            return radius;
        }
        float area();
        float circumference();
};
float Circle::area(){
    return 3.14*radius*radius;
}
float Circle::circumference(){
    return 2*3.14*radius;
}