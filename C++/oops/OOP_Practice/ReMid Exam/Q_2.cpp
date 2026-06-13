#include<iostream>
using namespace std;

class Employee
{
    private:
    string name;
    double salary;

    public:
    Employee():name("Unknown"),salary(0.0){}

    Employee(string n,double s):name(n),salary(s){}

    virtual void display(){
        cout<<"Name "<<name<<" Salary "<<salary<<endl;
    }
    ~Employee() = default;

    bool operator> (const Employee& e){
        return salary>e.salary ;
    }

    friend ostream &operator<< (ostream &out, const Employee &e){

        out<< "Employee: "<<e.name<<"! Salary: Rs "<<e.salary<<endl;
        return out;
    }
    void set_salary(double sal)
    {
        salary = sal;
    }
    double get_salary()
    {
        return salary;
    }

};

class Manager: public Employee
{
    private:
    string department;
    double bonus;

    public: 
    Manager(string n,double d, string dep, double bonus): Employee(n,d),department(dep),bonus(bonus){}

    void display() override
    {
        Employee::display();
        cout<<"Department: "<<department<<" bonus "<<bonus<<endl;
        
    }
    Manager &operator+=(int a){
        double salary = get_salary();
        salary+=a;
        set_salary(salary);
        return *this;
    }
};

int main()
{
    Employee e1("Sara Khan", 50000.0);
    Manager m1("Ali Ahmed", 80000.0, "Engineering", 15000.0);

    cout << e1;
    cout << m1;

    m1 += 10000;
    cout << "\nAfter += bonus applied to m1:" << endl;
    m1.display();

    cout << "\nSalary Comparison:" << endl;
    if (m1 > e1)
        cout << "Manager m1 has a higher salary." << endl;
    else
        cout << "Employee e1 has a higher salary." << endl;

    cout << "\nRuntime Polymorphism via Base Pointer Array:" << endl;
    Employee *arr[2];
    arr[0] = &e1;
    arr[1] = &m1;

    for (int i = 0; i < 2; i++)
        arr[i]->display();

    return 0;
}