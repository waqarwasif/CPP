#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Student
{
    string name;
    double gpa;

public:
    Student(string name, double gpa) : name(name), gpa(gpa)
    {
        if (gpa < 0 || gpa > 4)
        {
            throw invalid_argument("GPA must be between 0-4");
        }
    }
    string getname() { return name; }
    double getgpa() { return gpa; }
    void display()
    {
        cout << name << " - GPA: " << gpa << endl;
    }
};

class Professor
{
    string name, department;

public:
    Professor(string name, string department) : name(name), department(department) {}

    void display()
    {
        cout << "Professor: " << name << " (" << department << ")" << endl;
    }
};

class Course
{
    string name;
    Student *student[5];
    int studentcounter;
    Professor *professor;

public:
    
    Course(string coursename, Professor *p) : name(coursename), professor(p), studentcounter(0) {}

    void enrollStudent(Student *s)
    {
        if (studentcounter == 5)
        {
            throw overflow_error("Max students have been enrolled already");
        }
        student[studentcounter++] = s;
    }

    void display()
    {
        cout << "--- Course: " << name << " ---" << endl;
        professor->display();
        cout << "Enrolled Students:" << endl;
        for (int i = 0; i < studentcounter; i++)
        {
            student[i]->display();
        }
        cout << "--------------------------------" << endl;
    }
};

int main()
{
    try
    {
        Professor p("Waqar", "CIS");

        
        Student s1("Saad", 3.5);
        Student s2("Ali", 3.8);
        Student s3("Bilal", 2.9);
        Student s4("Omar", 4.0);
        Student s5("Zain", 3.1);

        Course course("Discrete Structures", &p);

        
        course.enrollStudent(&s1);
        course.enrollStudent(&s2);
        course.enrollStudent(&s3);
        course.enrollStudent(&s4);
        course.enrollStudent(&s5);

        
        course.display();

        
        Student s6("Hassan", 3.0);
        cout << "\nAttempting to enroll 6th student..." << endl;
        course.enrollStudent(&s6);
    }
    catch (exception &e)
    {
        cout << "Exception Caught: " << e.what() << '\n';
    }

    
    try
    {
        cout << "\nAttempting to create student with invalid GPA..." << endl;
        Student s7("ErrorBoy", 5.5); // Should throw invalid_argument
    }
    catch (exception &e)
    {
        cout << "Exception Caught: " << e.what() << '\n';
    }

    return 0;
}