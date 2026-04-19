#include<iostream> 
using namespace std;

class point
{
private:
    int x, y;

public:
    // Constructor
    point(int x = 0, int y = 0)
    {
        x = x;
        y = y;
    }

    // Friend function for >>
    friend istream &operator>>(istream &in, point &c);

    // Friend function for <<
    friend ostream &operator<<(ostream &out, const point &c);
};

// Overloading >>
istream &operator>>(istream &in, point &c)
{
    cout << "Enter x-coordinate: ";
    in >> c.x;

    cout << "Enter y-coordinate: ";
    in >> c.y;

    return in;
}

// Overloading <<
ostream &operator<<(ostream &out, const point &c)
{
    out << c.x << " , " << c.y << endl;
    return out;
}

// Main function
int main()
{
    point c1;

    cin >> c1;               // calls >>
    cout << "Point: " << c1; // calls <<

    return 0;
}