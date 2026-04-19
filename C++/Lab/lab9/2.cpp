// Composition
#include <iostream>
using namespace std;

class Engine
{

public:
    void start_engine()
    {
        cout << "Engine started.." << endl;
    }
};
class Car
{
    Engine engine; // object of other class is created in main class 

public:
    void drive()
    {
        engine.start_engine();
        cout << "Now driving.." << endl;
    }
};
int main()
{
    Car c1;
    c1.drive();
}