#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n)
    {
        name = n;
    }
    virtual void introduce()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person
{
protected:
    int studentID;

public:
    Student(string n, int id) : Person(n)
    {
        studentID = id;
    }
};

class Teacher : virtual public Person
{
protected:
    int employeeID;

public:
    Teacher(string n, int id) : Person(n)
    {
        employeeID = id;
    }
};

class TeachingAssistant : public Student, public Teacher
{
public:
    TeachingAssistant(string n, int sID, int eID) : Person(n), Student(n, sID), Teacher(n, eID)
    {
    }

    void introduce() override
    {
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main()
{
    TeachingAssistant ta("Ahmed", 101, 5001);
    ta.introduce();
    return 0;
}