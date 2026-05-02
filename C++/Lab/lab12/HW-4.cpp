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
    friend ostream &operator<<(ostream &os, const Complex_No &c)
    {
        if (c.img < 0)
            os << c.real << " - " << -c.img << "i";
        else
            os << c.real << " + " << c.img << "i";
        return os;
    }

};

template <class Type>
class Matrix
{
    Type matrix[2][2];

public:
    Matrix() = default;
    Matrix(Type &a, Type &b, Type &c, Type &d)
    {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    void Determinant()
    {
        cout << "Determinant is: " << (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]) << endl;
    }
    Type get(int i, int j)
    {
        return matrix[i][j];
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                    cout << "[ " << matrix[i][j];
                    if (j == 1)
                            cout
                        << " " << matrix[i][j] << " ]\n";
            }
        }
    }
    Matrix<Type> operator+(const Matrix<Type> &m2)
    {

        Matrix<Type> temp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];
            }
        }
        return temp;
    }

    Matrix<Type> operator-(const Matrix<Type> &m2)
    {

        Matrix<Type> temp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.matrix[i][j] = this->matrix[i][j] - m2.matrix[i][j];
            }
        }
        return temp;
    }
};

int main()
{
    Complex_No c1(1, 2), c2(3, 4), c3(4, 5), c4(7, 8);
    Complex_No c5(2, 1), c6(1, 2), c7(3, 1), c8(2, 3);

    Matrix<Complex_No> m1(c1, c2, c3, c4);
    Matrix<Complex_No> m2(c5, c6, c7, c8);

    cout << "First Complex Matrix:" << endl;
    m1.display();
    m1.Determinant();
    cout << endl;

    cout << "Second Complex Matrix:" << endl;
    m2.display();
    m2.Determinant();
    cout << endl;

    cout << "Addition of Matrices (m1 + m2):" << endl;
    Matrix<Complex_No> m3 = m1 + m2;
    m3.display();
    cout << endl;

    cout << "Subtraction of Matrices (m1 - m2):" << endl;
    Matrix<Complex_No> m4 = m1 - m2;
    m4.display();
    cout << endl;

    return 0;
}