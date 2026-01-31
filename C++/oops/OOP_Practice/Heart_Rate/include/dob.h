#ifndef DOB_H
#define DOB_H

class DOB
{
    int day;
    int month;
    int year;

public:
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

#endif