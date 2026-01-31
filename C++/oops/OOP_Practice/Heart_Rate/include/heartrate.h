#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>
#include "dob.h" // Include the dependency

class HeartRates
{
    std::string fname;
    std::string lname;
    int UID;
    int rollno;
    DOB dob;

public:
    // Constructor
    HeartRates(std::string fn, std::string ln, int r);

    // Setters
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setRollno(int r);
    void setUID();
    void setDOB(int d, int m, int y);

    // Getters
    std::string getFirstName();
    std::string getLastName();
    int getRollno();
    int getUID();
    void printDOB();

    // Core  Logic
    int getAge();
    int getMaximumHeartRate();
    void printTargetHeartRateRange();
};

#endif