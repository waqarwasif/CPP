// static variable is also called class variable
// static member function can access only static members of the class
#include<iostream>
using namespace std; 

class Employee{

    private:

        static int count; // static variable to keep track of number of employees
        int id;
    public:
        Employee(){
            count++;
            id = count;
        }
        void display(){
            cout<<"Employee ID: "<<id<<endl;
        }
        // static member function
        static void showCount(){
            cout<<"Total Employees: "<<count<<endl;
        }
};

int Employee::count = 0;

int main(){
    Employee e1;
    Employee e2;
    Employee e3;

    e1.display();
    e2.display();
    e3.display();

    Employee::showCount();

    return 0;
}