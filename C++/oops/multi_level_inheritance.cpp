#include <iostream>
#include <string>
using namespace std;
// Base class: Person
class Person
{
protected:
    string name;
    int age;

public:
    // Constructor to initialize Person's name and age
    Person(string n, int a) : name(n), age(a) {}
    void introduce()
    {
        cout << "Hello, I am " << name << " and I am " << age << "years old." << endl;
    }
};

class Employee : public Person
{
protected:
    string employee_id;
    double salary;

public:
    // Constructor to initialize Employee's data, using the constructor of Person
    Employee(string n, int a, string id, double s) : Person(n, a), employee_id(id), salary(s) {}
    void work()
    {
        cout << name << " is working." << endl;
    }
};

class Faculty : public Employee
{
private:
    string subject;

public:
    // Constructor to initialize Faculty's data, using Employee's constructor
    Faculty(string n, int a, string id, double s, string sub)
        : Employee(n, a, id, s), subject(sub) {}
    // Method to represent the faculty teaching a subject
    void teach()
    {
        cout << name << " is teaching " << subject << "." << endl;
    }
};

// Main function to demonstrate the multilevel inheritance
int main()
{
    // Creating an instance of Faculty
    Faculty faculty_member("Dr. John Doe", 40, "F123", 65000, "Computer Science");
    // Using methods from Person, Employee, and Faculty classes
    faculty_member.introduce(); // From Person class
    faculty_member.work();      // From Employee class
    faculty_member.teach();     // From Faculty class
}