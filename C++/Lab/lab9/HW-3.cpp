#include <iostream>
#include <string>
using namespace std;

class Salary
{
    float GrossPay;
    float Deductions;
    float NetPay;

public:
    Salary(float gross, float deductions, float net) : GrossPay(gross), Deductions(deductions) { NetPay = GrossPay - Deductions; }
    Salary()
    {
        cout << "Enter Gross Pay: ";
        cin >> GrossPay;
        cout << "Enter Deductions: ";
        cin >> Deductions;
        NetPay = GrossPay - Deductions;
    }

    void display()
    {
        cout << "Gross Pay: " << GrossPay << endl;
        cout << "Deductions: " << Deductions << endl;
        cout << "Net Pay: " << NetPay << endl;
    }
};

class Date
{
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    Date()
    {
        cout << "Enter Date of Joining (day month year): ";
        cin >> day >> month >> year;
    }
    void display()
    {
        cout << "Date of Joining: " << day << "/" << month << "/" << year << endl;
    }
};

class Employee
{
    string *name;
    Salary salary;
    Date date_of_joining;
    int id;

public:
    Employee(string n, int emp_id) : name(new string(n)), id(emp_id)
    {
        // Salary and Date will be initialized using their default constructors
    }
    Employee() : name(new string("")), id(0)
    {
        // Salary and Date will be initialized using their default constructors
    }
    ~Employee()
    {
        delete name;
    }
    void display()
    {
        cout << "Employee Name: " << *name << endl;
        cout << "Employee ID: " << id << endl;
        salary.display();
        date_of_joining.display();
    }
    string getName()
    {
        return *name;
    }
    int getId()
    {
        return id;
    }
};

class Database
{
    Employee *employees;
    int capacity;
    int count;
public:
    Database(int c) : capacity(c), count(0)
    {
        employees = new Employee[capacity];
    }
    ~Database()
    {
        delete[] employees;
    }
    int Add(const string& name)
    {
        if (count < capacity)
        {
            employees[count++] = Employee(name, count);
            return 1;
        }
        else
        {
            cout << "Database is full, cannot add more employees." << endl;
            return 0;
        }
    }
    int Delete(const string& name)
    {
        for (int i = 0; i < count; i++)
        {
            if (employees[i].getName() == name)
            {
                for (int j = i; j < count - 1; j++)
                {
                    employees[j] = employees[j + 1]; // shift left
                }
                count--;
                return 1;
            }
        }
        cout << "Employee not found, cannot delete." << endl;
        return 0;
    }
    void Search(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (employees[i].getId() == id)
            {
                cout << "Employee found:\n";
                employees[i].display();
                return;
            }
        }
        cout << "Employee not found." << endl;
    }
    


};

int main()
{
    Database db(5);
    cout<< "Options: \n"
        << "1. Add Employee\n"
        << "2. Delete Employee\n"
        << "3. Search Employee by ID\n"
        << "4. Exit\n";
    int choice;
    string name;
    int id;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            db.Add(name);
            break;
        case 2:
            cout << "Enter Employee Name to Delete: ";
            cin.ignore();
            getline(cin, name);
            db.Delete(name);
            break;
        case 3:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            db.Search(id);
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
