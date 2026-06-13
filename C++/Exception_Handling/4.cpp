#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Exception
{
    char  message[100];
    int what;

public:
    Exception(const char* message, int what)
    {
        strcpy(this->message, message);
        this->what = what;
    }

    const char* getMessage()
    {
        return message;
    }

    int What()
    {
        return what;
    }
};

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    try
    {
        if (age < 0)
            throw Exception("Age cannot be negative", 1);
        else if (age < 18)
            throw Exception("You are not eligible to vote", 2);
        else
            cout << "You are eligible to vote";
    }
    catch (Exception &e)
    {
        cout << "Error: " << e.getMessage() << " (Error code: " << e.What() << ")" << endl;
    }
}