#include<iostream>
#include<ostream>
#include<istream>
#include<string.h>
#include<cmath>
using namespace std;
char* nameIn();
int ageIn();
float salaryIn();
/*1.Define a class Person with name and age as instance variables as private members. Provide setters
and gettres as protected methods. Derive a class Employee from Person class with private instance variable
salary. Provide public methods setEmployee() and showEmployee().*/
class Person{
    private:
        char name[20];
        int age;
    protected:
        void setName(char n[]){strcpy(name,n);}
        void setAge(int a){age=a;}
    public:
        char* getName(){return name;}
        int getAge(){return age;}
};
class Employee:public Person{
    private:
        float salary;
    public:
        void setEmployee();
        void showEmployee();
};
void Employee::setEmployee(){
    setName(nameIn());
    setAge(ageIn());
    int s=salaryIn();
    salary=s;
}
void Employee::showEmployee(){
    char name[20];
    strcpy(name,getName());
    for(int i=0;name[i];i++){
        cout<<name[i];
    }
    cout<<"  "<<getAge()<<"  "<<salary<<endl;
}
char* nameIn(){
    char *n=new char[20];
    cin.ignore();
    cout<<"Name: ";
    cin.getline(n,20);
    return n;
}
int ageIn(){
    int a;
    cout<<"Age: ";
    cin>>a;
    return a;
}
float salaryIn(){
    float sal;
    cout<<"Salary: ";
    cin>>sal;
    return sal;
}
void f1(){
    Employee e1,e2;
    e1.setEmployee();
    cout<<"---------------------"<<endl;
    e2.setEmployee();
    cout<<"---------------------"<<endl;
    e1.showEmployee();
    e2.showEmployee();
}

/*2.Define a class Circle with radius as private instance variable and setRadius(),getRadius,getArea as public
instance methods. Define a class ThickCircle as a subclass of Circle with thickness as private instance variable
and getThickness(),setThickness() as public instnace methods. Provide an overridden method getArea() to claculate
area of thick portion of circle.*/
class Circle{
    private:
        double redius;
    protected:
        void setRadius(double red){
            redius=red;
        }
    public:
        Circle(double r=0):redius(r){}
        double getRadius() const{
            return redius;
        }
        double getArea() const{
            return M_PI*redius*redius;
        }
};
class ThickCircle: public Circle{
    private:
        double thickness;
    public:
        ThickCircle(double r=0,double t=0):Circle(r),thickness(r){}
        void setThickness(double thick){
            thickness=thick;
        }
        double getThickness() const{
            return thickness;
        }
        double getAreaOfThick() const{
            double outerRadius = getRadius();
            double innerRadius = outerRadius-thickness;
            return M_PI*(outerRadius*outerRadius - innerRadius*innerRadius);
        }
};

/*3.Define a class Coordinate with x and y as instance variables. Define overloaded versions of getDistance(),
first with no argument calculating distance from origin, and second with one argument of Coordinate type to calculate
distance between two coordinates. Also define other methods if required.*/
class Coordinate{
    private:
        double x,y;
    public:
        Coordinate(double x=0,double y=0){this->x=x; this->y=y;}
        double getDistance(){
            return sqrt(pow(x,2)+pow(y,2));
        }
        double getDistance(Coordinate c){
            return sqrt(pow((c.x-x),2)+pow((c.y-y),2));
        }
};

/*4.Define a class Shape with shapName as instance variable. Provide setter and getter.*/
class Shape{
    private:
        char shapName[20];
    public:
        Shape(){ shapName[0]='\0';}
        void setShapNAme(char s[]){
            strcpy(shapName,s);
        }
        char* getShapName(){
            return shapName;
        }
};

/*5.In question 3 & 4, derive a class StraightLine from Shape with two Coordinate type
objects as instnace members. Provide methods to setLine(),getDistnace() and showLine().*/
class StraightLine:public Shape{
    private:
        Coordinate c1,c2;
    public:
        StraightLine(){
            c1
        }
        void setLine(Coordinate C1,Coordinate C2){
            c1=C1;
            c2=C2;
        }
};

/*6.Define a class Game with an array of 5 int varibales as instance member to store the score of each
of 5 rounds. Provide method to setScore(int round,int score). Also provide method getScore(int round).*/
class Game{
    private:
        int scores[5];
    protected:
        void setScore(int round,int score){
            if(round>=1&&round<=5)
                scores[round-1]=score;
        }
    public:
        int getScore(int round){
            if(round>=1&&round<=5)
                return scores[round-1];
            return 0;
        }
};

/*7.In question 6,derive a class GameResult with an array of 5 int type variables to store the
result in each round. Result value is 2 for win, 0 for loose and 1 for draw. Provide methods to
setResult and getResult. Write method to calculate final result of the game. */
class GameResult:public Game{
    private:
        int results[5]; //store result in each round
        int EmptyIndex;
    public:
        void setResult(int round,char result[]){    //Win Match
            if (round>=1&&round<=5){
                if(!strcmp(result,"win")){
                    results[round-1]=2;
                    setScore(round,2);
                }
                else if(!strcmp(result,"loose")){   //Loose match
                    results[round-1]=0;
                    setScore(round,0);
                }
                else if(!strcmp(result,"draw")){    //Draw Match
                    results[round-1]=1;
                    setScore(round,1);
                }
            }
        }
        int getResult(int round){
            if(round>=1&&round<=5)
                return results[round-1];
        }
        int totalScore(){
            int total=0;
            for(int i=0;i<5;i++){
                total+=getScore(i+1);
            }
            return total;
        }
        int totalWin(){
            int count=0;
            for(int i=0;i<5;i++){
                if(results[i]==2)
                    count++;
            }
            return count;
        }
        int totalLoose(){
            int count=0;
            for(int i=0;i<5;i++){
                if(results[i]==0)
                    count++;
            }
            return count;
        }
        int totalDraw(){
            int count=0;
            for(int i=0;i<5;i++){
                if(results[i]==1)
                    count++;
            }
            return count;
        }
        void finalResult(){
            cout<<"~~~~~~~Final Result~~~~~~~"<<endl;
            cout<<"Total Score = "<<totalScore()<<endl;
            cout<<"Win = "<<totalWin()<<" match"<<endl;
            cout<<"Loose = "<<totalLoose()<<" match"<<endl;
            cout<<"Draw = "<<totalDraw()<<" match"<<endl;
        }
};
void f2(){
    GameResult g1;
    char res[6];
    for(int i=1;i<=5;i++){
        cout<<"#Round-"<<i<<":-"<<endl;
        cout<<"   Result:";
        cin.getline(res,6);
        // cin.ignore();
        g1.setResult(i,res);
        cout<<"--------------------"<<endl;
    }
    g1.finalResult();
}

/*8.Define a class Actor with name, age as instnace variables an setter, getters as instance methods.
Define a class TVActor as a derived class of Actor with instance variable to store number of TV projects
done or running and define setter, getter. Also define setTVActor() and showTVActor(). Define a class
MovieActor as a derived class of Actor with instnace variable to store number of movies doe or running
and define setters, getter.Also define setMovieActor() and showMovieActor(). Derive a class AllScreenActor
from TVActor and MovieActor. Define a method to setActorData() and showActorData().*/
class Actor{
    private:
        int age;
        char name[20];
    protected:
        void setAge(int age){this->age=age;}
        void setName(char name[]){strcpy(this->name,name);}
    public:
        Actor():age(0){}
        int getAge() const {return age;}
        char* getName(){return name;}
};
class TVActor:public::Actor{
    private:
        int noOfProject_done;
        int noOfProject_running;
    protected:
        void set_done(int n){noOfProject_done=n;}
        void set_running(int n){noOfProject_running=n;}
    public:
        ostream& operater<<(ostream& dout,Actor a1){

        }
        void setTVActor(){
            setAge(27);
            setName("Rashi");
            set_done(5);
            set_running(2);
        }
        void showTVActor(){
            getName()
        }
};
int main(){
    Coordinate c1(3,4);
    cout<<c1.getDistance();
}