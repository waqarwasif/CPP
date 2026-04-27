#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Patient
{
    string name;
    int age;

public:
    Patient() : name("unknown"), age(1) {}
    Patient(string name, int age) : name(name), age(age)
    {
        if (age <= 0 || age > 120)
        {
            throw invalid_argument("Invalid Age...");
        }
        if (name == "")
        {
            throw invalid_argument("name cannot be empty");
        }
    }
    string getname()
    {
        return name;
    }
    int getage() { return age; }
    void display()
    {
        cout << name << " " << age << endl;
    }
};

class Doctor
{
    string name;
    string speciality;

public:
    Doctor(string name, string speciality) : name(name), speciality(speciality) {}
    string getname()
    {
        return name;
    }
    string getspec()
    {
        return speciality;
    }
    void display()
    {
        cout << getname() << " " << getspec() << endl;
    }
};

class Ward
{
    string Wardname;
    Patient patient[4];
    Doctor *doc;
    int roomcount;

public:
    Ward(string Wardname, Doctor *d) : doc(d), Wardname(Wardname), roomcount(0) {}

    void admitPatient(string name, int age)
    {
        if (roomcount == 4)
        {
            throw overflow_error("No rooms for patients available");
        }
        patient[roomcount++] = Patient(name, age);
    }
    void display()
    {
        cout << Wardname << endl;
        doc->display();
        for (int i = 0; i < roomcount; i++)
        {
            cout << endl;
            patient[i].display();
        }
    }
};

int main(){
    Doctor d("Waqar","neurologist");
    Ward ward("Ward1",&d);
    try
    {
        ward.admitPatient("Saad",19);
        ward.admitPatient("Saad",19);
        ward.admitPatient("Saad",19);
        ward.admitPatient("Saad",19);
        ward.display();
        ward.admitPatient("Saad",19);
        
    }
    catch(exception& e)
    {
        cout<< e.what() << '\n';
    }
    
}