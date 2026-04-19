#include <iostream>
using namespace std;
class point
{
    int x_coordinate, y_coordinate;

public:
    point() {}
    point(int x, int y)
    {
        x_coordinate = x;
        y_coordinate = y;
    }
    void show()
    {
        cout << x_coordinate << " , ";
        cout << y_coordinate << "\n";
    }
    point operator+( point op2);
    point operator++();
    point operator++(int x);
};
// Overload + for point.
point point::operator+( point op2)
{
    point temp;
    temp.x_coordinate = op2.x_coordinate + x_coordinate;
    temp.y_coordinate = op2.y_coordinate + y_coordinate;
    return temp;
}
// Overload prefix ++ for point.
point point::operator++()
{
    ++x_coordinate;
    ++y_coordinate;
    return *this;
}
point point::operator++(int x)
{
    point temp = *this;
    x_coordinate++;
    y_coordinate++;
    return temp;
}
int main()
{
    point ob1(10, 20), ob2(5, 30);
    ob1.show(); // displays 10 20
    ob2.show(); // displays 5 30
    ob1 = ob1 + ob2;
    ob1.show(); // displays 15 50
    ++ob1;
    ob1.show();
    point ob3 = ob2++;
    ob3.show();
    ob2.show();
    return 0;
}