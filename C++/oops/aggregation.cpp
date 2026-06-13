#include<iostream>
using namespace std;

class Course{

    string courseName;
    public:
    Course(string n):courseName(n){}
    string getname(){
        return courseName;
    }


};
class Student{
    string studentName;
    public:
    Student(string n):studentName(n){}

    void enroll_in_course(Course *course){
        cout<<studentName<<" enrolled in "<<course->getname()<<endl;
    }
};

int main(){
    Course math("Maths");
    Student s1("Waqar");
    s1.enroll_in_course(&math);
}