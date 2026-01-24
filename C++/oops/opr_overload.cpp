#include<iostream>
using namespace std;
class Complex {
    private:
    int real;
    int imag;
    public:
    Complex(): real(0), imag(0) {}
    Complex(int r, int i): real(r), imag(i) {}
    // Overloading + operator
    Complex operator + (const Complex &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(5, 6);
    Complex c3;
    c3 = c1 + c2; // Using overloaded + operator
    cout << "Result of addition: ";
    c3.display();

    Complex c4 = c1 + c2 + c3; // Chained addition
    cout << "Result of chained addition: ";
    c4.display();
    return 0;
}