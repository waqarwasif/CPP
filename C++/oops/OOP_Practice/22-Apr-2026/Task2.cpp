#include<iostream>
#include<string>
using namespace std;

class Student {
    string roll_no, name;
    float GPA;

    public:
    Student():roll_no(""),name("Unknown"),GPA(0){}
    Student(string roll,string n,float g):roll_no(roll),name(n),GPA(g){}

    friend bool operator==(const Student &s1, const Student &s2);
    friend bool operator==(const Student &s1, int n);
    friend bool operator!=(const Student &s1, const Student &s2);
    friend bool operator!=(const Student &s1, int n);
    friend bool operator>(const Student &s1, const Student &s2);
    friend bool operator>(const Student &s1, int n);
    friend ostream &operator<<(ostream &os, const Student &s);

};

bool operator==(const Student &s1, const Student &s2){
    return (s1.GPA == s2.GPA);
}
bool operator==(const Student &s1, int n){
    return (s1.GPA == n);
}
bool operator!=(const Student &s1, const Student &s2){
    return !(s1 == s2);
}
bool operator!=(const Student &s1, int n){
    return !(s1 == n);
}
bool operator>(const Student &s1, const Student &s2){
    return (s1.GPA > s2.GPA);
}
bool operator>(const Student &s1, int n){
    return (s1.GPA > n);
}
ostream &operator<<(ostream &os, const Student &s)
{
    os << "Roll: " << s.roll_no << ", Name: " << s.name << ", GPA: " << s.GPA;
    return os;
}

int main()
{
    // 1. Create test objects
    Student s1("S001", "Imran", 3.00);
    Student s2("S002", "Asim", 4.00);
    Student s3("S003", "Saad", 3.00);

    cout << "--- Equality Testing ---" << endl;
    // Test Student == Student
    if (s1 == s3)
        cout << "s1 and s3 have the same GPA (3.00)." << endl;

    // Test Student == int
    if (s2 == 4.00)
        cout << "s2 has a GPA of 4.00." << endl;

    cout << "\n--- Inequality Testing ---" << endl;
    // Test Student != Student
    if (s1 != s2)
        cout << "s1 and s2 have different GPAs." << endl;

    // Test Student != int
    if (s1 != 4.00)
        cout << "s1 does not have a GPA of 4.00 ." << endl;

    cout << "\n--- Relational (Greater Than) Testing ---" << endl;
    // Test Student > Student
    if (s2 > s1)
        cout << "s2 (Asim) has a higher GPA than s1 (Imran)." << endl;

    // Test Student > int
    if (s2 > 3)
        cout << "s2 has a GPA greater than 3." << endl;

    return 0;
}