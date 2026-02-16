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

protected:
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
            cin >> marks[i];
        cin.ignore();
        calculatePercentage();
    }

    virtual ~Student()
    {
        delete[] name;
    }

    const double *getMarks() const { return marks; }

    virtual double calculatePercentage()
    {
        double total = 0;
        for (int i = 0; i < 5; i++)
            total += marks[i];
        percentage = (total / 500.0) * 100.0;
        return percentage;
    }

    char grade()
    {
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

    virtual void displayInfo()
    {
        cout << endl
             << "----------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
        cout << "Grade: " << grade() << endl;
    }
};

class ScienceStudent : public Student
{
private:
    double practicalMarks;

public:
    ScienceStudent() : Student(), practicalMarks(0.0) {}

    void setPracticalMarks(double m)
    {
        practicalMarks = m;
        calculatePercentage();
    }

    double calculatePercentage() override
    {
        double total = 0;
        const double *m = getMarks();
        for (int i = 0; i < 5; i++)
            total += m[i];
        total += practicalMarks;
        percentage = (total / 650.0) * 100.0;
        return percentage;
    }

    void displayInfo() override
    {
        Student::displayInfo();
        cout << "Practical Marks: " << practicalMarks << " / 150" << endl;
    }
};

class ArtsStudent : public Student
{
private:
    double optionalMarks;

public:
    ArtsStudent() : Student(), optionalMarks(0.0) {}

    void setOptionalMarks(double m)
    {
        optionalMarks = m;
        calculatePercentage();
    }

    double calculatePercentage() override
    {
        double total = 0;
        const double *m = getMarks();
        for (int i = 0; i < 5; i++)
            total += m[i];
        total += optionalMarks;
        percentage = (total / 600.0) * 100.0;
        return percentage;
    }

    void displayInfo() override
    {
        Student::displayInfo();
        cout << "Optional Course Marks: " << optionalMarks << " / 100" << endl;
    }
};

int main()
{
    cout << "Enter Science Student Details" << endl;
    ScienceStudent *sci = new ScienceStudent();
    sci->setPracticalMarks(125.0);

    cout << endl
         << "Enter Arts Student Details" << endl;
    ArtsStudent *art = new ArtsStudent();
    art->setOptionalMarks(78.0);

    Student *students[2];
    students[0] = sci;
    students[1] = art;

    cout << endl
         << "SCIENCE STUDENT DATA" << endl;
    students[0]->displayInfo();

    cout << endl
         << "ARTS STUDENT DATA" << endl;
    students[1]->displayInfo();

    for (int i = 0; i < 2; i++)
    {
        delete students[i];
    }

    return 0;
}