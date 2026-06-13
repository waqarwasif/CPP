#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class DOB
{
    int day;
    int month;
    int year;

public:
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
};

class HeartRates
{
    string fname;
    string lname;
    int UID;
    int rollno;
    DOB dob;

public:
    HeartRates(string fn, string ln, int r);

    // Setters and Getters
    void setFirstName(string fName);
    void setLastName(string lName);
    string getFirstName();
    string getLastName();
    void setRollno(int r);
    int getRollno();
    void setUID();
    int getUID();
    void setDOB(int d, int m, int y);
    void printDOB();

    // Core Business Logic
    int getAge();
    int getMaximumHeartRate();
    void printTargetHeartRateRange();
};

// --- Function Definitions ---

HeartRates::HeartRates(string fn, string ln, int r)
{
    fname = fn;
    lname = ln;
    rollno = r;
    setUID();
}

void HeartRates::setFirstName(string fName)
{
    fname = fName;
}

void HeartRates::setLastName(string lName)
{
    lname = lName;
}

string HeartRates::getFirstName()
{
    return fname;
}

string HeartRates::getLastName()
{
    return lname;
}

void HeartRates::setRollno(int r)
{
    rollno = r;
    setUID(); // Recalculate UID if rollno changes
}

int HeartRates::getRollno()
{
    return rollno;
}

int HeartRates::getUID()
{
    return UID;
}

void HeartRates::setUID()
{
    string s = to_string(rollno);
    if (s.length() >= 3)
    {
        // Extract 3rd digit (index 2)
        UID = s[2] - '0';
    }
    else
    {
        UID = 0;
    }
}

void HeartRates::setDOB(int d, int m, int y)
{
    dob.setDay(d);
    dob.setMonth(m);
    dob.setYear(y);
}

void HeartRates::printDOB()
{
    cout << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear();
}

int HeartRates::getAge()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    if (ltm == nullptr)
        return 0;

    int current_year = 1900 + ltm->tm_year;
    return current_year - dob.getYear();
}

int HeartRates::getMaximumHeartRate()
{
    return 220 - getAge();
}

void HeartRates::printTargetHeartRateRange()
{
    int maxHR = getMaximumHeartRate();
    int minTarget = maxHR * 0.50;
    int maxTarget = maxHR * 0.85;
    cout << minTarget << " - " << maxTarget << " bpm";
}

// --- Main Application ---

int main()
{
    string f, l;
    int r, d, m, y;

    cout << "Enter First Name: ";
    cin >> f;
    cout << "Enter Last Name: ";
    cin >> l;
    cout << "Enter Roll No: ";
    cin >> r;

    cout << "Enter Day of Birth: ";
    cin >> d;
    cout << "Enter Month of Birth: ";
    cin >> m;
    cout << "Enter Year of Birth: ";
    cin >> y;

    HeartRates hr(f, l, r);
    hr.setDOB(d, m, y);

    cout << "\n----------------------------" << endl;
    cout << "       HEALTH REPORT        " << endl;
    cout << "----------------------------" << endl;
    cout << "Name:               " << hr.getFirstName() << " " << hr.getLastName() << endl;
    cout << "Roll No:            " << hr.getRollno() << endl;
    cout << "UID:                " << hr.getUID() << endl;
    cout << "Date of Birth:      ";
    hr.printDOB();
    cout << endl;
    cout << "Age:                " << hr.getAge() << " years" << endl;
    cout << "Max Heart Rate:     " << hr.getMaximumHeartRate() << " bpm" << endl;
    cout << "Target Heart Range: ";
    hr.printTargetHeartRateRange();
    cout << endl;
    cout << "----------------------------" << endl;

    return 0;
}