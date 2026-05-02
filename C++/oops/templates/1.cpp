#include <iostream>
using namespace std;

// by using this template now function can accept several types and perform its task
// it will even work on user provided data types(classes) if we have << and - operators overloaded 
template <class T>
T abs(T n)
{
    return (n < 0) ? -n : n;
}

int main()
{
    int i1 = 500;
    int i2 = -6;
    long l1 = -80000L;
    double dub1 = -9.67;

    cout << "\n " << abs(i1);
    cout << "\n " << abs(i2);
    cout << "\n " << abs(l1);
    cout << "\n " << abs(dub1);

    return 0;
}