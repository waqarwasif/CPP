#include <iostream>
using namespace std;

//Const Member Function Example

// class Sample{
//     public:
//         void ConstFunc() const;
//         void NonConstFunc();

        
// };
// void Sample:: ConstFunc() const
// {
//     cout << "This is a const member function." << endl;
//     // NonConstFunc(); // Error: cannot call non-const function from const function
// }
// void Sample::NonConstFunc()
// {
//     cout << "This is a non-const member function." << endl;
// }



//Const Data Members Example

// #include <iostream>
// using namespace std;
// class ABC
// {
// public:
//     // use const keyword to declare const data member
//     const int A;
//     // create class constructor
//     ABC(int y) : A(y)
//     {
//         cout << " The value of y: " << y << endl;
//     }
// };
// int main()
// {
//     ABC obj(10); // here 'obj' is the object of class ABC
//     cout << " The value of constant data member 'A' is: " << obj.A << endl;
//     // obj.A = 5; // it shows an error.
//     // cout << obj.A << endl;
//     return 0;}


//CONST OBJECTS Example
// #include <iostream>
// using namespace std;
// class ABC
// {
// public:
//     // define data member
//     int A;
//     // create constructor of the class ABC
//     ABC()
//     {
//         A = 10; // define a value to A
//     }
// };
// int main()
// {
//     // declare a constant object
//     const ABC obj;
//     cout << " The value of A: " << obj.A << endl;
//     // obj.A = 20; // It returns a compile time error
// }

class Car
{
public:
    // Constructor to initialize speed
    Car(int initSpeed) : speed(initSpeed) {}
    // This function cannot modify the object, as it's a const object
    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int x) { speed = x; }

private:
    int speed;
};
int main()
{
    const Car myCar(60); // Initialize speed to 60 when creating the object
    // myCar.setSpeed(60); // Error: can't modify a const object
    std::cout << myCar.getSpeed() << std::endl;
} // Output: 60


//CONST POINTERS Example

// class PointerExample
// {
//     public:
//     int x;
//     int y;

//     PointerExample(int a, int b)
//     {
//         x = a;
//         y = b;
//     }

//     int* const ptr = &x; // const pointer to int
//     void errorExample()
//     {
//         // ptr = &y; // Error: cannot change the address stored in const pointer
//         *ptr = 20; // Allowed: can change the value at the address
//     }

//     const int* ptr2 = &x; // pointer to const int
//     void errorExample2(){
//         // *ptr2 = 30; // Error: cannot change the value at the address
//         ptr2 = &y; // Allowed: can change the address stored in pointer
//         x=40; // Allowed: can change the value of x directly but not through ptr2
//     }

// };