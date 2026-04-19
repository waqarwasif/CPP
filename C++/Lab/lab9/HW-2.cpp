#include<iostream>
#include<string>
using namespace std;

class Salary{
    float GrossPay;
    float Deductions;
    float NetPay;
    
public:
    Salary(float gross, float deductions, float net):GrossPay(gross), Deductions(deductions){NetPay = GrossPay - Deductions;}
    Salary(){
        cout<<"Enter Gross Pay: ";
        cin>>GrossPay;
        cout<<"Enter Deductions: ";
        cin>>Deductions;
        NetPay = GrossPay - Deductions;
    }

    void display(){
        cout<<"Gross Pay: "<<GrossPay<<endl;
        cout<<"Deductions: "<<Deductions<<endl;
        cout<<"Net Pay: "<<NetPay<<endl;
    }
};

class Date{
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y):day(d), month(m), year(y){}
    Date(){
        cout<<"Enter Date of Joining (day month year): ";
        cin>>day>>month>>year;
    }
    void display(){
        cout<<"Date of Joining: "<<day<<"/"<<month<<"/"<<year<<endl;
    }
};



class Employee{
    string *name;
    Salary salary;
    Date date_of_joining;
public:
    Employee(string n):name(new string(n)){
        // Salary and Date will be initialized using their default constructors
    }
    ~Employee(){
        delete name;
    }
    void display(){
        cout<<"Employee Name: "<<*name<<endl;
        salary.display();
        date_of_joining.display();
    }
};

int main(){
    string empName;
    cout<<"Enter Employee Name: ";
    getline(cin, empName);
    Employee emp(empName);
    cout<<"\nEmployee Details:\n";
    emp.display();
    return 0;
}



