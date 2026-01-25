#include <iostream>
using namespace std;

class myclass
{
    int data[2];

public:
    int *p;

public:
    myclass()
    {
        p = data;
    }
};
int main()
{
    myclass *cp;
    cp = new myclass[3];

    // Assigning values to the data member of myclass array
    cp->p[0] = 10;
    cp->p[1] = 20;
    (cp + 1)->p[0] = 30;
    (cp + 1)->p[1] = 40;
    (cp + 2)->p[0] = 50;
    (cp + 2)->p[1] = 60;


    // displaying values of the data member of myclass array
    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1 << " data: " << endl;
        cout << cp[i].p[0] << endl;
        cout << cp[i].p[1] << endl;
    }

    return 0;

}
