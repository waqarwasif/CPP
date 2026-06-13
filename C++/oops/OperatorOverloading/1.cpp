#include <iostream>
using namespace std;

class Count
{
private:
    int value;

public:
    // Constructor initializes value to 5
    Count() : value(5) {}

    // Overloading the prefix increment operator (++)
    Count& operator++()
    {
        ++value;
        return *this; // Return the current object after incrementing
    }

    void display()
    {
        cout << "Count: " << value << endl;
    }
};

int main()
{
    Count count1;

    // Call the overloaded ++ operator function
    ++count1;
    count1.display();
    Count count2;
    count2 = ++count1; // Using the overloaded ++ operator to assign count1 to count2

    count2.display();
    count1.display();
    count2 = count1; 
    count2.display();
    return 0;
}