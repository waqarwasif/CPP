#include <iostream>
using namespace std;

class MyException
{
public:
    string message;
    int value;

    MyException(string s, int v)
    {
        message = s;
        value = v;
    }
};

int main()
{
    int i;

    try
    {
        cout << "Enter a positive number: ";
        cin >> i;

        if (i < 0)
            throw MyException("Not Positive", i);
    }
    catch (const MyException &e)
    {
        cout << e.message << ": " << e.value << endl;
    }

    return 0;
}