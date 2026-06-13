#include <iostream>

class Base
{
public:
    virtual void doWork(int x)
    {
        std::cout << "Base working with int: " << x << '\n';
    }
    virtual void doWork(double x)
    {
        std::cout << "Base working with double: " << x << '\n';
    }
};

class Derived : public Base
{
public:
    // We want to add a new string version, but we accidentally HIDE the others.
    void doWork(std::string s)
    {
        std::cout << "Derived working with string: " << s << '\n';
    }
};

int main()
{
    Derived d;
    d.doWork("Hello"); // Works perfectly.

    // ERROR: compiler says "cannot convert int to std::string".
    // It doesn't even see Base::doWork(int) because the name "doWork" was found in Derived.
    //d.doWork(5);
    return 0;
}


// solution
class Derived : public Base
{
public:
    // Tells the compiler: "Bring all doWork functions from Base into this scope"
    using Base::doWork;

    void doWork(std::string s)
    {
        std::cout << "Derived working with string: " << s << '\n';
    }
};
// Now d.doWork(5) works perfectly!