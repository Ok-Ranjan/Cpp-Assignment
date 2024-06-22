#include<iostream>
using namespace std;

/*1.Define a class Complex to represent a complex number with instance variables a and b
to store real and imaginary parts. Also define folllowing member function*/
//1.void setData(int,int),2.void showData(),3.Complex add(Complex),4.Complex subtract(Complex),5.Complex multiply(Complex)
class Complex{
    private:
        int a,b;
    public:
        void setData(int,int);
        void showData();
        Complex add(Complex);
        Complex subtract(Complex);
        Complex multiply(Complex);

};
void Complex::setData(int real,int imag){
    a=real;
    b=imag;
}
void Complex::showData(){
    cout<<a<<"+"<<b<<"i";
}
Complex Complex::add(Complex c){
    Complex temp;
    temp.a=a+c.a;
    temp.b=b+c.b;
    return temp;
}
Complex Complex::subtract(Complex c){
    Complex temp;
    temp.a=a-c.a;
    temp.b=b-c.b;
    return temp;
}
Complex Complex::multiply(Complex c){
    Complex temp;
    temp.a=a*c.a-b*c.b;
    temp.b=a*c.b+b*c.a;
    return temp;;
}

/*2.Define a class Time to represent a time with instance variables h,m and s to store
hour, minute and second. Also define following member functions*/
//1.void setTime(int,int,int),2.void showTime(),3.void narmalize(),4.Time add(Time),5.bool is_greater(Time)
class Time{
    private:
        int h,m,s;
    public:
        void setTime(int,int,int);
        void showTime();
        void narmalize();
        Time add(Time);
        bool is_greater(Time);
};
void Time::setTime(int hr,int min,int sec){
    h=hr;
    m=min;
    s=sec;
}
void Time::showTime(){
    cout<<"hr="<<h<<" min="<<m<<" sec="<<s;
}
void Time::narmalize(){
    m=m+s/60;
    s=s%60;
    h=h+m/60;
    m=m%60;
}
Time Time::add(Time t){
    Time temp;
    temp.h=h+t.h;
    temp.m=m+t.m;
    temp.s=s+t.s;
    return temp;
}
bool Time::is_greater(Time t){
    int sec=h*3600+m*60+s;
    int sec_t=t.h*3600+t.m*60+t.s;
    if(sec>sec_t)
        return true;
    else
        return false;
}

/*3.Define a class TestResult with properties roll_no,right,wrong,net_score. Also define class properties
right_weightage,wrong_weightage. Provide methods to set and get all the properties.*/
class TestResult{
    private:
        int roll_no,right,wrong,net_score;
        static int right_weightage,wrong_weightage;
    public:
        void setRoll_no(int r){ roll_no=r;}
        int getRoll_no(){return roll_no;}
        void setRight(int r){ right=r;}
        int getRight(){return right;}
        void setwrong(int w){wrong=w;}
        int getWrong(){return wrong;}
        void setNet_score(int n){net_score=n;}
        int getNet_score(){return net_score;}
        static void setRightWeightage(int r){right_weightage=r;}
        static void setWrongWeightage(int w){wrong_weightage=w;}
        int getRight_weightage(){return right_weightage;}
        int getWrong_weightage(){return wrong_weightage;}
};
int TestResult::right_weightage;
int TestResult::wrong_weightage;

/*4.Write a driver function main() to use TestResult class(Question 3). Create an array to 5 TextResult objects,
set values to all the objects and display the results in sorted order (by net_score).*/
void sortByNetScore(TestResult t[],int s){
    int i,r;
    TestResult temp;;
    for(r=1;r<s;r++){
        for(i=0;i<s-r;i++){
            if(t[i].getNet_score()<t[i+1].getNet_score()){
                temp=t[i];
                t[i]=t[i+1];
                t[i+1]=temp;
            }
        }
    }
}
void setTestResult(TestResult tr,int r,int rig,int w){
    tr.setRoll_no(r);
    tr.setRight(rig);
    tr.setwrong(w);
    tr.setNet_score(rig*tr.getRight_weightage()-w*tr.getWrong_weightage());
}
void printTestResult(TestResult tr){
    cout<<"\n"<<tr.getRoll_no()<<" "<<tr.getRight()<<" "<<tr.getWrong()<<" "<<tr.getNet_score();
}
int main(){
    TestResult result[5];
    setTestResult(result[0],101,80,20);
    setTestResult(result[1],102,70,10);
    setTestResult(result[2],103,90,0);
    setTestResult(result[3],104,60,10);
    setTestResult(result[4],105,50,8);
    sortByNetScore(result,5);
    for(int i=0;i<5;i++){
        printTestResult(result[i]);
    }
}

/*5.Define a class Matrix to represent a 3✕3 order matrix. Provide appropriate methods
and properties to the class. Also define following methods in the class.*/
//1.Matrix add(Matrix),2.Matrix sub(Matrix),3.Matrix multiply(Matrix),4.Matrix transpose(),5.bool is_singular()
class Matrix{
    private:
        int Mat[3][3];
    public:
        // void createMatrix(int r,int c){
        //     row=r;
        //     col=c;
        //     Mat=(int*)malloc(row*col*sizeof(int));
        // }
        void setMatrix(int a[][3]){
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    Mat[i][j]=a[i][j];
        }
        void printMatrix(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)
                    cout<<Mat[i][j]<<" ";
                cout<<endl;
            }
        }
        Matrix add(Matrix m);
        Matrix sub(Matrix m);
        Matrix multiply(Matrix m);
        Matrix transpose();
        bool is_singular();
};
Matrix Matrix::add(Matrix m){
    int i,j;
    Matrix sum;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            sum.Mat[i][j]=Mat[i][j]+m.Mat[i][j];
        }
    }
    return sum;
}
Matrix Matrix::sub(Matrix m){
    int i,j;
    Matrix sum;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            sum.Mat[i][j]=Mat[i][j]-m.Mat[i][j];
        }
    }
    return sum;
}
Matrix Matrix::multiply(Matrix m){
    int i,j,k,sum=0;
    Matrix mul;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                sum+=Mat[i][k]*m.Mat[k][j];
            }
            mul.Mat[i][j]=sum;
        }
    }
    return mul;
}
Matrix Matrix::transpose(){
    Matrix tran;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tran.Mat[j][i]=Mat[i][j];
        }
    }
    return tran;
}
bool Matrix::is_singular(){
    int D;
    D=Mat[0][0]*(Mat[1][1]*Mat[2][2]-Mat[1][2]*Mat[2][1])-Mat[0][1]*(Mat[1][0]*Mat[2][2]-Mat[1][2]*Mat[2][0])+Mat[0][2]*(Mat[1][0]*Mat[2][1]-Mat[1][1]*Mat[2][0]);
    return D==0;
}