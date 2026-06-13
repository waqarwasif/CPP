#include<iostream>
using namespace std;

class Base
{
public:
    virtual void print(int x = 10) { cout << "B:" << x; }
};
class Derived : public Base
{
public:
    void print(int x = 20) override { cout << "D:" << x; }
};
int main()
{
    Base *b = new Derived();
    b->print();
    return 0;
}