#include <iostream>
#include <ctime>
#include <string>
#include "..\include\heartrate.h" // Connect to the header

using namespace std;

// Constructor
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
    int minTarget = (maxHR * 50) / 100;
    int maxTarget = (maxHR * 85) / 100;
    cout << minTarget << " - " << maxTarget << " bpm";
}