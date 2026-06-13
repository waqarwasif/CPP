#include <iostream>
using namespace std;

class Base
{
public:
    int val;
    Base() : val(0) {}
};

class A : virtual public Base
{
};

// Fix: Make B use virtual inheritance as well
class B : virtual public Base
{
};

class C : public A, public B
{
};

int main()
{
    C obj;
    obj.val = 15;
    cout << "Value: " << obj.val << endl;
    return 0;
}