#include <iostream>
using namespace std;

class TwoD_Vector
{
    int x, y;

public:
    TwoD_Vector(int a = 0, int b = 0) : x(a), y(b) {}

    void display()
    {
        cout << "(" << x << " , " << y << ")" << endl;
    }

    int &operator[](int index)
    {
        if (index == 0)
            return x;
        return y;
    }

    friend istream &operator>>(istream &in, TwoD_Vector &v);
    friend ostream &operator<<(ostream &out, const TwoD_Vector &v);
};

istream &operator>>(istream &in, TwoD_Vector &v)
{
    cout << "Enter x: ";
    in >> v.x;
    cout << "Enter y: ";
    in >> v.y;
    return in;
}

ostream &operator<<(ostream &out, const TwoD_Vector &v)
{
    out << "(" << v.x << " , " << v.y << ")";
    return out;
}

int main()
{
    TwoD_Vector v1(3, 7);

    cout << "--- display() ---" << endl;
    v1.display();

    cout << "\n--- operator<< ---" << endl;
    cout << v1 << endl;

    cout << "\n--- operator[] read ---" << endl;
    cout << "v1[0] = " << v1[0] << endl;
    cout << "v1[1] = " << v1[1] << endl;

    cout << "\n--- operator[] write ---" << endl;
    v1[0] = 10;
    v1[1] = 20;
    cout << "After v1[0]=10, v1[1]=20: " << v1 << endl;

    cout << "\n--- operator>> ---" << endl;
    TwoD_Vector v2;
    cin >> v2;
    cout << "You entered: " << v2 << endl;

    return 0;
}