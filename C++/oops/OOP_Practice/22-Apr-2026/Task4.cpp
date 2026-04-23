#include <iostream>
#include <cmath> // absolute value
using namespace std;

class Time
{
    int hours, minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // helper
    void norm()
    {
        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }

    Time operator+(const Time &t) const
    {
        Time temp;
        temp.minutes = this->minutes + t.minutes;
        temp.hours = this->hours + t.hours;
        temp.norm();
        return temp;
    }

    Time operator-(const Time &t) const
    {
        
        int total1 = this->hours * 60 + this->minutes;
        int total2 = t.hours * 60 + t.minutes;
        int diff = abs(total1 - total2);

        return Time(diff / 60, diff % 60);
    }

    bool operator>(const Time &t) const
    {
        return (this->hours * 60 + this->minutes) > (t.hours * 60 + t.minutes);
    }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << t.hours << ":" << t.minutes;
        return os;
    }
};

int main()
{
    Time t1(2, 45); // 02:45
    Time t2(1, 30); // 01:30

    Time sum = t1 + t2;
    Time diff = t1 - t2;

    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;
    cout << "Sum: " << sum << endl;   //04:15
    cout << "Diff: " << diff << endl; // 01:15

    if (t1 > t2)
        cout << "t1 is later than t2" << endl;

    return 0;
}