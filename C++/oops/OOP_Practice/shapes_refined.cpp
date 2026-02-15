#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

void getPositiveInput(float &value, const string &prompt)
{
    while (true)
    {
        cout << prompt;
        if (cin >> value && value > 0)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Value must be positive. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

class Shape
{
protected:
    string color;

public:
    Shape() : color("red") {}
    Shape(string c) : color(c) {}

    virtual ~Shape() {}

    virtual void input()
    {
        cout << "Enter color: ";
        cin >> color;
    }

    virtual void display() const
    {
        cout << "Color: " << color << endl;
    }
};

class Rectangle : public Shape
{
    float length, width;

public:
    Rectangle() : length(0), width(0) {}

    void input() override
    {
        cout << endl;
        cout << "--- Rectangle Input ---" << endl;
        Shape::input();
        getPositiveInput(length, "Enter length: ");
        getPositiveInput(width, "Enter width: ");
    }

    float cal_area() const { return length * width; }
    float cal_perimeter() const { return 2 * (length + width); }

    void display() const override
    {
        cout << endl;
        cout << "--- Rectangle Details ---" << endl;
        Shape::display();
        cout << "Length: " << length << " units, Width: " << width << " units" << endl;
        cout << "Area: " << cal_area() << " sq units" << endl;
        cout << "Perimeter: " << cal_perimeter() << " units" << endl;
    }
};

class Triangle : public Shape
{
    float base, height;

public:
    Triangle() : base(0), height(0) {}

    void input() override
    {
        cout << endl;
        cout << "--- Triangle Input ---" << endl;
        Shape::input();
        getPositiveInput(base, "Enter base: ");
        getPositiveInput(height, "Enter height: ");
    }

    float cal_area() const { return 0.5f * base * height; }

    void display() const override
    {
        cout << endl;
        cout << "--- Triangle Details ---" << endl;
        Shape::display();
        cout << "Base: " << base << " units, Height: " << height << " units" << endl;
        cout << "Area: " << cal_area() << " sq units" << endl;
    }
};

class Cylinder : public Shape
{
    float radius, height;

public:
    Cylinder() : radius(0), height(0) {}

    void input() override
    {
        cout << endl;
        cout << "--- Cylinder Input ---" << endl;
        Shape::input();
        getPositiveInput(radius, "Enter radius: ");
        getPositiveInput(height, "Enter height: ");
    }

    float cal_volume() const { return M_PI * radius * radius * height; }

    float cal_surfaceArea() const
    {
        return (2 * M_PI * radius * height) + (2 * M_PI * radius * radius);
    }

    void display() const override
    {
        cout << endl;
        cout << "--- Cylinder Details ---" << endl;
        Shape::display();
        cout << "Radius: " << radius << " units, Height: " << height << " units" << endl;
        cout << "Volume: " << cal_volume() << " cu units" << endl;
        cout << "Surface Area: " << cal_surfaceArea() << " sq units" << endl;
    }
};

class Sphere : public Shape
{
    float radius;

public:
    Sphere() : radius(0) {}

    void input() override
    {
        cout << endl;
        cout << "--- Sphere Input ---" << endl;
        Shape::input();
        getPositiveInput(radius, "Enter radius: ");
    }

    float cal_volume() const
    {
        return (4.0f / 3.0f) * M_PI * pow(radius, 3);
    }

    float cal_surfaceArea() const
    {
        return 4.0f * M_PI * pow(radius, 2);
    }

    void display() const override
    {
        cout << endl;
        cout << "--- Sphere Details ---" << endl;
        Shape::display();
        cout << "Radius: " << radius << " units" << endl;
        cout << "Volume: " << cal_volume() << " cu units" << endl;
        cout << "Surface Area: " << cal_surfaceArea() << " sq units" << endl;
    }
};

class RegularPentagon : public Shape
{
    float side;

public:
    RegularPentagon() : side(0) {}

    void input() override
    {
        cout << endl;
        cout << "--- Regular Pentagon Input ---" << endl;
        Shape::input();
        getPositiveInput(side, "Enter side: ");
    }

    float cal_area() const
    {
        return (5 * side * side) / (4 * tan(M_PI / 5));
    }

    float cal_perimeter() const { return 5 * side; }

    void display() const override
    {
        cout << endl;
        cout << "--- Regular Pentagon Details ---" << endl;
        Shape::display();
        cout << "Side: " << side << " units" << endl;
        cout << "Area: " << cal_area() << " sq units" << endl;
        cout << "Perimeter: " << cal_perimeter() << " units" << endl;
    }
};

int main()
{
    int n;
    cout << "================ SHAPE CALCULATOR ================" << endl;
    cout << "Enter number of shapes: ";
    cin >> n;

    Shape **shapes = new Shape *[n];
    for (int i = 0; i < n; ++i)
    {
        int choice;
        cout << endl;
        cout << "Select shape type for shape " << (i + 1) << ":" << endl;
        cout << "1. Rectangle" << endl;
        cout << "2. Triangle" << endl;
        cout << "3. Cylinder" << endl;
        cout << "4. Sphere" << endl;
        cout << "5. Regular Pentagon" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shapes[i] = new Rectangle();
            break;
        case 2:
            shapes[i] = new Triangle();
            break;
        case 3:
            shapes[i] = new Cylinder();
            break;
        case 4:
            shapes[i] = new Sphere();
            break;
        case 5:
            shapes[i] = new RegularPentagon();
            break;
        default:
            cout << "Invalid choice. Defaulting to Rectangle." << endl;
            shapes[i] = new Rectangle();
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        shapes[i]->input();
    }

    for (int i = 0; i < n; ++i)
    {
        cout << endl;
        cout << "================ RESULTS FOR SHAPE " << (i + 1) << " ================" << endl;
        shapes[i]->display();
    }

    // Clean up
    for (int i = 0; i < n; ++i)
    {
        delete shapes[i];
    }

    delete[] shapes;

    return 0;
}