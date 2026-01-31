#include <iostream>
#include "..\include\heartrate.h" 

using namespace std;

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

// To run the program:
// g++ main.cpp HeartRate.cpp -I include -o app
// ./app