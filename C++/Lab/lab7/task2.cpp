#include <iostream>
using namespace std;

class dateTime
{
private:
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    int seconds;

public:
    dateTime()
    {
        day = 0;
        month = 0;
        year = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // 1. Set date only
    void SetValue(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;

        // resetting time after date modification
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // 2. Set date and Hours
    void SetValue(int d, int m, int y, int h)
    {
        day = d;
        month = m;
        year = y;
        hours = h;

        minutes = 0;
        seconds = 0;
    }

    // 3. Set date, Hours, and Minutes
    void SetValue(int d, int m, int y, int h, int min)
    {
        day = d;
        month = m;
        year = y;
        hours = h;
        minutes = min;

        seconds = 0;
    }

    // 4. Set date and full Time
    void SetValue(int d, int m, int y, int h, int min, int s)
    {
        day = d;
        month = m;
        year = y;
        hours = h;
        minutes = min;
        seconds = s;
    }

    void Display() const
    {
        cout << "date: " << day << "/" << month << "/" << year << " | ";
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{
    dateTime dt;

    cout << "Method Overloading............." << endl;

    // 1
    dt.SetValue(24, 3, 2026);
    dt.Display();

    // 2
    dt.SetValue(24, 3, 2026, 9);
    dt.Display();

    // 3
    dt.SetValue(24, 3, 2026, 9, 33);
    dt.Display();

    // 4
    dt.SetValue(24, 3, 2026, 9, 35, 47);
    dt.Display();

    return 0;
}