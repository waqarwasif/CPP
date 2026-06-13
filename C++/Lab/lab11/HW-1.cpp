#include <iostream>
using namespace std;

const double PI = 3.14159;

class Shape
{
protected:
    double Area;

public:
    Shape()
    {
        Area = 0.0;
    }

    virtual void Calculate_Area() = 0;

    virtual void Display()
    {
        cout << "Area: " << Area << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void Calculate_Area() override
    {
        Area = PI * radius * radius;
    }

    void Display() override
    {
        cout << "Circle Radius: " << radius << endl;
        cout << "Area of Circle: " << Area << endl;
    }
};

class Rectangle : public Shape
{
private:
    double Length;
    double Breadth;

public:
    Rectangle(double l, double b)
    {
        Length = l;
        Breadth = b;
    }

    void Calculate_Area() override
    {
        Area = Length * Breadth;
    }

    void Display() override
    {
        cout << "Rectangle Length: " << Length << endl;
        cout << "Rectangle Breadth: " << Breadth << endl;
        cout << "Area of Rectangle: " << Area << endl;
    }
};

int main()
{
    Shape *p;
    Circle C1(5);
    Rectangle R1(4, 6);

    p = &C1;
    p->Calculate_Area();
    p->Display();

    cout << endl;

    p = &R1;
    p->Calculate_Area();
    p->Display();

    return 0;
}