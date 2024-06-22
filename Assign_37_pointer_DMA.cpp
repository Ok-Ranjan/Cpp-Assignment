#include<iostream>
#include<string.h>
using namespace std;

/*1.Define a class Person with name and age as instance variables. Provide Parameterised
Constructor with two formal arguments name & age, to initialise instance variables.*/
class Person{
        string name;
        int age;
    public:
        Person(string name,int age){    //Name Conflict
            (*this).name=name;
            this->age=age;
        }
};

/*2.Defien a class Complex with instance variables a and b to store real and imaginary part of a
complex number. Provide setData() method with formal arguments with the name a nad b, to set the values
of instnace variables. Also define showdata() method to display instance member variable values.*/
class Complex{
        int a,b;
    public:
        void setData(int a,int b){  //Name Conflict
            this->a=a;
            this->b=b;
        }
        void showData(){
            cout<<"a="<<this->a<<" b="<<this->b;
        }
};

/*3.In question-2, write a non member function in which instance Complex class dynamically.
Initialise instance variables and display their values.*/
void f3(){
    Complex *p=new Complex;
    p->setData(3,4);
    p->showData();
}

/*4.Define a class Time with instance variables hr, min and sec. Provide instnace method setTime() and
showTime() method has formal argument with the same name as instance variables. Also defien setters and getters.*/
class Time{
    private:
        int hr,min,sec;
    public:
        //setters
        void setTime(int hr,int min,int sec){   //Name Conflict
            this->hr=hr;
            this->min=min;
            this->sec=sec;
        }
        void showTime(){
            cout<<"\n"<<this->hr<<":"<<this->min<<" "<<this->sec;
        }
        //getters-
        int getHour(){return hr;}
        int getMinute(){return min;}
        int getSecond(){return sec;}
        Time* createArray_time(int size);
        bool operator>(Time t);
        void sortTimeArray(Time*,int );
        void Time::displayTimeArray(Time *,int);
};

/*5.IN question-4, define a method to dynamically create an array of time objects with
specified size (recived through argument) and return array.*/
Time* createArray_time(int size){
    Time *p=new Time[size];
    return p;
}

/*6.In question-4, define a method to sort Time object array.*/
bool Time::operator>(Time t){
    if(hr>t.hr)
        return true;
    else if(min>t.min)
        return true;
    else if(sec>t.sec)
        return true;
    return false;
}
void Time::sortTimeArray(Time *p,int size){
    Time temp;
    int r,i;
    for(r=1;r<size;r++){
        for(i=0;i<size-r;i++){
            if(p[i]>p[i+1]){
                temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }
}

/*7.In question-4, define a method to display Time object array values. Array is received through argument.*/
void Time::displayTimeArray(Time *p,int size){
    for(int i=0;i<size;i++){
        p[i].showTime();
    }
}

/*8.Define a class String with char pointer and lenght of the string as instance member Variables.
Define a method to dynamically create an array of char type and hold the input string in such a way
that the array lenght is just enough to accommodate the input string.*/
class String{
    private:
        char *str;
        int len;
    public:
        String():str(NULL),len(0){}
        void inputString(){
            char c;
            String temp;
            cout<<"Enter some text: ";
            cin>>c;
            str=new char[++len];
            str[len-1]=c;
            str[len]='\0';
            while(true){
                cin>>c;
                if(c=='\n')
                    break;
                temp.str=new char[++len];
                strcpy(temp.str,str);
                temp.str[len-1]=c;
                temp.str[len]='\0';
                delete []str; 
                str=temp.str;
            }
        }
        void uppercase();
        void lowercase();
        void printStr();
        char* getStr();
        int getLenOfStr();
        friend ostream& operator<<(ostream &dout,String s);
};

/*9.In question-8,define methods to convert string onto uppercase, lowercase.*/
void String::uppercase(){
    for(int i=0;i<len;i++){
        if(str[i]>='a'&&str[i]<='z')
            str[i]-=32;
    }
}
void String::lowercase(){
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
    }
}

/*10.In question-8,define methods to print string, return string, return lenght of string.*/
void String::printStr(){
    for(int i=0;i<len;i++)
        cout<<str[i];
}
char* String::getStr(){
    return str;
}
int String::getLenOfStr(){
    return len;
}
ostream& operator<<(ostream &dout,String s){
    for(int i=0;i<s.len;i++){
        dout<<s.str[i];
    }
}

int main(){

}