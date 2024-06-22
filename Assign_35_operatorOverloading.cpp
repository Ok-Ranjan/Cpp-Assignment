#include<iostream>
using namespace std;
#define ARRAY_INDEX_OUT_OF_BOND 1
/*1.Define a class Complex with appropriate instance vriables and member functions.
define follwing operators in the class: 1.+ ,2.- ,3.* ,4.==*/
class Complex{
    private:
        int a,b;
    public:
        Complex():a(0),b(0){}
        Complex(int a,int b):a(a),b(b){}
        void showData();
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        bool operator==(Complex);
};
void Complex::showData(){
    cout<<"real="<<a<<"  "<<"imag="<<b;
}
Complex Complex::operator+(Complex c){
    Complex temp;
    temp.a=a+c.a;
    temp.b=b+c.b;
    return temp;
}
Complex Complex::operator-(Complex c){
    Complex temp;
    temp.a=a-c.a;
    temp.b=b-c.b;
    return temp;
}
Complex Complex::operator*(Complex c){
    Complex temp;
    temp.a=a*c.a-b*c.b;
    temp.b=a*c.b+b*c.a;
    return temp;
}
bool Complex::operator==(Complex c){
    if(a==c.a&&b==c.b)
        return true;
    return false;
}

/*2.Create a class Time which contains hour,min and second as fields. Overload
greater than. (>)operator to compare two time objects.*/
class Time{
    int hour,min,second;
    public:
        void setTime(int h,int m,int s){hour=h;min=m;second=s;}
        void showTime(){
            cout<<"\n"<<hour<<":"<<min<<":"<<second;
        }
        bool operator>(Time t){
            if(hour*3600+min*60+second>t.hour*3600+t.min*60+t.second)
                return true;
            return false;
        }
        Time operator++(int); //post-increment
        Time operator++(); //pre-increment
        Time operator+(Time t);
};

/*3.In question-2, overload pre-increment and post-increment operator to increment
Time object value by one second.*/
Time Time::operator++(int) //post-increment
{
    Time temp=*this;
    second++;
    min=min+second/60;
    second%=60;
    hour=hour+min/60;
    min%=60;
    return temp;
}
Time Time::operator++() //pre-increment
{
    second++;
    min=min+second/60;
    second%=60;
    hour=hour+min/60;
    min%=60;
    return *this;
}

/*4.In question-2, overload operator+ to add two Time objects.*/
Time Time::operator+(Time t){
    Time temp;
    temp.second=second+t.second;
    temp.min=min+t.min+temp.second/60;
    temp.second%=60;
    temp.hour=hour+t.hour+min/60;
    temp.min%=60;
    return temp;
}

/*5.Define a class matrix to reresent 3×3 matrix. Provide appropriate instance methods. Also define
operator +, operator -, operator *,to perform addition, subtraction and multiplication operations respectively.*/
class Matrix{
    private:
        int mat[3][3];
    public:
        void inputMatrix();
        void showMatrix();
        Matrix operator+(Matrix);
        Matrix operator-(Matrix);
        Matrix operator*(Matrix);
};
Matrix Matrix::operator+(Matrix m){
    Matrix temp;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            temp.mat[i][j]=mat[i][j]+m.mat[i][j];
    return temp;
}
Matrix Matrix::operator*(Matrix m){
    Matrix temp;
    int sum,i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(sum=0,k=0;k<3;k++)
                sum=mat[i][k]*m.mat[k][j];
            temp.mat[i][j]=sum;
        }
    }
    return temp;
}
Matrix Matrix::operator-(Matrix m){
    Matrix temp;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            temp.mat[i][j]=mat[i][j]-m.mat[i][j];
    return temp;
}
void Matrix::showMatrix(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }
}
void Matrix::inputMatrix(){ 
    cout<<"Enter 9 elements of matrix(row wise):";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>mat[i][j];
}

/*5.Consider follwing class Numbers
Overload the operator unary minus(-) to negate the numbers.*/
class Numbers{
    int x,y,z;
    public:
        Numbers operator-(){
            Numbers temp;
            temp.x=-x;
            temp.y=-y;
            temp.z=-z;
            return temp;
        }
};

/*6.Define a C++ class fraction
Define an operator + to add two fraction object.*/
class fraction{
        long numerator;
        long denominator;
    protected:
        long lcm(int a,int b){
            int l;
            for(l=a>b?a:b;l<=a*b;l++)
                if(l%a==0&&l%b==0)
                    return l;
        }
    public:
        fraction(long n=0,long d=0){
            numerator=n;
            denominator=d;
        }
        fraction operator+(fraction f){
            fraction temp;
            long L=lcm(denominator,f.denominator);
            temp.numerator=numerator*(L/denominator)+f.numerator*(L/f.denominator);
            temp.denominator=L;
            return temp;
        }
        bool operator<(fraction);
};

/*7.In question-6, define an operator < to compare two fraction objects*/
bool fraction::operator<(fraction f){
    return numerator*f.denominator<f.numerator*denominator;
}

/*8.Consider a class Distance
Overload the operator+ to add two distance objects*/
class Distance{
        int km,m,cm;
    public:
        void setDistance(int x,int y,int z){km=x;m=y;cm=z;}
        void showDistance(){ cout<<"km="<<km<<" m="<<m<<" cm="<<cm;}
        Distance operator+(Distance d);
        Distance operator--(); //pre-decrement
        Distance operator--(int);   //post-decrement
};
Distance Distance::operator+(Distance d){
    Distance temp;
    temp.cm=cm+d.cm;
    temp.m=m+d.m+temp.cm/100;
    temp.cm%=100;
    temp.km=km+d.km+temp.m/1000;
    temp.m%=1000;
    return temp;
}

/*9.In question-8 define pre decrement and post decrement to decrease distance by 1 cm.*/
Distance Distance::operator--() //pre-decrement
{
    if(cm>0)
        cm--;
    else{
        cm=99;
        if(m>0)
            m--;
        else{
            m=999;
            km--;
        }
    }
    return *this;
}
Distance Distance::operator--(int) //post-decrement
{
    Distance temp=*this;
    if(cm>0)
        cm--;
    else{
        cm=99;
        if(m>0)
            m--;
        else{
            m=999;
            km--;
        }
    }
    return temp;
}

/*10.Consider the follwing class Array
Define constructor to allocate an array of given size (size is given through parameter).
Define a subscript operator to access element at given index. Define destructor to deallocates the memory of array.*/
class Array{
        int *p;
        int size;
    public: 
        Array(int);
        int& operator[](int);
        ~Array();
};
Array::Array(int s){
    size=s;
    p=(int*)malloc(size*sizeof(int));
}
int& Array::operator[](int index){
    if(index>=size&&index<0){
        cout<<"Array index out of bond";
        throw ARRAY_INDEX_OUT_OF_BOND;
    }
    return p[index];
}
Array::~Array(){
    free(p);
}