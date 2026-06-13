#include <iostream>
using namespace std;

class Engine
{
public:
    void start() { cout << "Engine starting...\n"; }
};

// Notice the 'private' keyword here!
class Car : private Engine
{
public:
    void drive()
    {
        start();
        cout << "Car is moving!\n";
    }
};

int main()
{
    Car myCar;
    myCar.drive();
    return 0;
}