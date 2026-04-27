#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class Teacher{
    string name;
    public:
    Teacher(string name):name(name){
        if (name == "")
        {
            throw invalid_argument("Name cannot be empty");
        }
    }
    string getname()const{return name;}
    void setname(string n){
        if(n==""){
            throw invalid_argument("Name cannot be empty");
        }
        name=n;
    }
    void display(){
        cout<<name<<endl;
    }

};

class Department{
    string departname;
    Teacher* teachers[2];
    int teachercount;

    public:
    Department():teachercount(0){}
    Department(string n):teachercount(0){
        if (n == "")
        {
            throw invalid_argument("Name cannot be empty");
        }
        departname = n;
    }
    void addTeacher(Teacher *t){
        if(teachercount==2){
            throw overflow_error("Maximum Teachers reached..");
        }
        teachers[teachercount++]=t;
    }
    void display(){
        cout<<departname<<endl;
        for(int i=0;i<teachercount;i++){
            teachers[i]->display();
        }
    }
    void setname(string n){
        if (n == "")
        {
            throw invalid_argument("Name cannot be empty");
        }
        departname = n;
    }
};

class School{
    Department department[3];
    int depcount;
    public:
    School():depcount(0){}
    void addDep(string name,Teacher* t1,Teacher* t2){
        if(depcount==3){
            throw overflow_error("Maximum departments created...");
        }
        department[depcount].setname(name);
        department[depcount].addTeacher(t1);
        department[depcount].addTeacher(t2);
        depcount++;
        
    }

    void display(){
        for(int i=0;i<depcount;i++){
            cout<<endl;
            department[i].display();
        }
    }

    

};

int main(){
    Teacher t1("Waqar");
    Teacher t2("navid");
    Teacher t3("julie");
    Teacher t4("Carton");

    School school;
    try
    {
        school.addDep("CIS",&t1,&t2);
    school.addDep("EE",&t3,&t4);

    school.display();
    }
    catch(exception& e)
    {
        cout<< e.what() << '\n';
    }
    
    return 0;
    

}