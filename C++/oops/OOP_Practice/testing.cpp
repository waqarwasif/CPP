#include <iostream>
using namespace std;

class Demo
{
private:
    int A;
    int B;
    int C;

public:
    // parameterized constructor
    Demo(int A, int B, int C);
    void set(int A, int B, int C);
    void print();
};

Demo::Demo(int A, int B, int C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

void Demo::set(int A, int B, int C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

void Demo::print()
{
    cout << "Value of A :  " << A << endl;
    cout << "Value of B :  " << B << endl;
    cout << "Value of C :  " << C << endl;
}

int main()
{
    // Calling of parameterized constructor with array of object.
    Demo obj[3] = {{1, 2, 3}, {11, 12, 13},{21, 22, 23}};

    // print values
    obj[0].print();
    obj[1].print();

    // set new values
    obj[0].set(100, 200, 300);
    obj[1].set(1000, 2000, 3000);

    // print values
    obj[0].print();
    obj[1].print();

    return 0;
}