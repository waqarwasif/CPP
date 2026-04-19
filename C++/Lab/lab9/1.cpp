// Aggregation through pointer 
#include<iostream>
using namespace std;

class Teacher
{
    string name;
    public:
    Teacher(string n) : name(n) {}
    void display()
    {
        cout<<"I am a teacher named "<<name<<endl;
    }
    string getName()
    {
        return name;
        }
};

class Department{

    string depname;
    Teacher *t1;
    public:
    Department(string n, Teacher *t):depname(n),t1(t){}
    void show(){
        cout<<"Dep: "<<depname<<endl<<"Teacher: " <<t1->getName()<<endl;
    }
};

int main(){
    Teacher t("Waqar"); // first teacher is made then, 
    Department ComputerSystems("Computer Systems",&t); // teacher is passed by reference to second class obj
    ComputerSystems.show();

}