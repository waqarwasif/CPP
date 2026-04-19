#include <iostream>
#include <cmath>
using namespace std;

class Complex_No
{
    double real;
    double img;

public:
    Complex_No(double r = 0, double i = 0) : real(r), img(i) {}

    void display() const
    {
        if (img < 0)
            cout << real << " - " << -img << "i" << endl;
        else
            cout << real << " + " << img << "i" << endl;
    }

    Complex_No operator+(const Complex_No &c) const
    {
        return Complex_No(real + c.real, img + c.img);
    }

    Complex_No operator-(const Complex_No &c) const
    {
        return Complex_No(real - c.real, img - c.img);
    }

    Complex_No operator*(const Complex_No &c) const
    {
        return Complex_No(real * c.real - img * c.img,
                          real * c.img + img * c.real);
    }

    Complex_No operator/(const Complex_No &c) const
    {
        double denom = c.real * c.real + c.img * c.img;
        return Complex_No((real * c.real + img * c.img) / denom,
                          (img * c.real - real * c.img) / denom);
    }

    Complex_No &operator++()
    {
        ++real;
        ++img;
        return *this;
    }

    Complex_No operator++(int)
    {
        Complex_No temp = *this;
        ++real;
        ++img;
        return temp;
    }

    Complex_No &operator--()
    {
        --real;
        --img;
        return *this;
    }

    Complex_No operator--(int)
    {
        Complex_No temp = *this;
        --real;
        --img;
        return temp;
    }

    double magnitude() const
    {
        return sqrt(real * real + img * img);
    }

    bool operator>(const Complex_No &c) const
    {
        return magnitude() > c.magnitude();
    }

    bool operator<(const Complex_No &c) const
    {
        return magnitude() < c.magnitude();
    }

    bool operator==(const Complex_No &c) const
    {
        return real == c.real && img == c.img;
    }
};

int main()
{
    Complex_No a(3, 4), b(1, -2);

    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();

    cout << "\na + b = ";
    (a + b).display();
    cout << "a - b = ";
    (a - b).display();
    cout << "a * b = ";
    (a * b).display();
    cout << "a / b = ";
    (a / b).display();

    Complex_No c(2, 3);
    cout << "\nBefore pre-increment: ";
    c.display();
    ++c;
    cout << "After  pre-increment: ";
    c.display();

    Complex_No d(5, 5);
    cout << "\nBefore post-increment: ";
    d.display();
    d++;
    cout << "After  post-increment: ";
    d.display();

    Complex_No e(1, 1);
    cout << "\nBefore pre-decrement: ";
    e.display();
    --e;
    cout << "After  pre-decrement: ";
    e.display();

    cout << "\nComparisons (a vs b):" << endl;
    cout << "a > b : " << (a > b ? "true" : "false") << endl;
    cout << "a < b : " << (a < b ? "true" : "false") << endl;
    cout << "a == b: " << (a == b ? "true" : "false") << endl;

    Complex_No f(3, 4), g(4, 3);
    cout << "\nf = ";
    f.display();
    cout << "g = ";
    g.display();
    cout << "f == g (value):     " << (f == g ? "true" : "false") << endl;
    
    return 0;
}