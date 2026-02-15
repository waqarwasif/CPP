#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

class Student
{
private:
    char *name;
    int rollNo;
    double marks[5];
    float percentage;

public:
    Student()
    {
        char tempName[100];
        cout << "Enter Name: ";
        cin.getline(tempName, 100);

        name = new char[strlen(tempName) + 1];
        strcpy(name, tempName);

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
        cin.ignore(); // Clear the newline character from the input buffer
        calculatePercentage();
    }
    Student(const char *n, int r, double m[])
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        rollNo = r;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
        calculatePercentage();
    }

    Student(const Student &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        rollNo = other.rollNo;
        percentage = other.percentage;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = other.marks[i];
        }
    }

    ~Student()
    {
        delete[] name;
    }

    void setName(const char *n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    const char *getName() const { return name; }

    void setRollNo(int r) { rollNo = r; }
    int getRollNo() const { return rollNo; }

    void setMarks(double m[])
    {
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
        calculatePercentage();
    }
    const double *getMarks() const { return marks; }

    float getPercentage() const { return percentage; }

    void calculatePercentage()
    {
        double total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        percentage = (total / 500.0) * 100.0;
    }

    char grade()
    {
        calculatePercentage();
        if (percentage >= 80)
            return 'A';
        if (percentage >= 70)
            return 'B';
        if (percentage >= 60)
            return 'C';
        if (percentage >= 50)
            return 'D';
        return 'F';
    }

    double getHighestMark() const
    {
        double highest = marks[0];
        for (int i = 1; i < 5; i++)
        {
            if (marks[i] > highest)
                highest = marks[i];
        }
        return highest;
    }

    void displayInfo()
    {
        cout << endl;
        cout << "----------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
        cout << "Grade: " << grade() << endl;
        cout << "Highest Mark: " << getHighestMark() << endl;
    }
};

int main()
{
    const int size = 2;

    Student *students = new Student[size];
    cout << endl;
    cout << "--- Student Records ---";
    for (int i = 0; i < size; i++)
    {
        students[i].displayInfo();
    }

    delete[] students;

    return 0;
}