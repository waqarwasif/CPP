#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}

    
    void operator<<(ostream &o)
    {
        o << real << " + " << imag << "i";
    }
};

int main()
{
    Complex c1(3, 4);

    c1 << cout;
}