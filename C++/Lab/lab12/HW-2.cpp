#include <iostream>
#include <cmath>

using namespace std;

template <class T>
T Power(T x, T y)
{
    return pow(x, y);

}

int main()
{
    int x =2 ,y =2;
    double a = 4.000,b = 0.5;
    cout<<Power(x,y)<<endl;
    cout<<Power(a,b);
    
}