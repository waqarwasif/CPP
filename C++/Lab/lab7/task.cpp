#include<iostream>
using namespace std;

class Shape{

    protected:
    double area;

    public:
    Shape():area(0){}

    virtual void calculate_Area() = 0;

    virtual void Display() const
    {
        cout << "Area: " << area << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;
    const double PI = 3.14159265359;

public:
    Circle(double r) : radius(r) {}

        void calculate_Area() override
    {
        area = PI * radius * radius;
    }

    
    void Display() const override
    {
        cout << "--- Circle ---" << endl;
        cout << "Radius: " << radius << endl;
        Shape::Display(); 
    }

};

class Rectangle : public Shape
{
private:

    double length;
    double breadth;
public:

    Rectangle(double l, double b):length(l),breadth(b){}
    

    void calculate_Area() override
    {
        area = length * breadth;
    }

    void Display() const override
    {
        cout << "--- Rectangle ---" << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        Shape::Display(); // show area from base class
    }
};

int main()
{
    Circle myCircle(5.0);
    myCircle.calculate_Area();
    myCircle.Display();

    cout << endl;

    Rectangle myRectangle(4.0, 6.0);
    myRectangle.calculate_Area();
    myRectangle.Display();

    // RT polymorphism
    cout<<endl;
    cout<<"RT polymorphism"<<endl;

    Shape *shapes[2];

    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; i++)
    {
        
        shapes[i]->calculate_Area();
        shapes[i]->Display();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete shapes[i];
    }

    return 0;
}