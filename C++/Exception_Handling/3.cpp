#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    try
    {
        if(age<0){
            throw invalid_argument("Age cannot be negative");
        }
        else if(age<18){
            throw runtime_error("You are not eligible to vote");
        }
        else{
            cout<<"You are eligible to vote";
        }
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}