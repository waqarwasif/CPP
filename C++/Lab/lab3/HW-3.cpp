#include <iostream>
using namespace std;

class IntArr
{
    int size;
    int *arr;

public:
    IntArr(int s) : size(s)
    {
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
        cout << "Array of size " << size << " created." << endl;
    }

    IntArr(const IntArr &other)
    {
        size = other.size;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
        cout << "Array copied." << endl;
    }

    ~IntArr()
    {
        delete[] arr;
        cout << "Memory freed." << endl;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
    }

    void add()
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            total += arr[i];
        }
        cout << "Addition result: " << total << endl;
    }

    int getSize() { return size; }
};

int main()
{

    cout << "--- Creating Object A ---" << endl;
    IntArr objA(5);

    objA.setValue(0, 10);
    objA.setValue(1, 20);
    objA.setValue(2, 30);
    objA.setValue(3, 40);
    objA.setValue(4, 50);

    cout << "Sum of A: ";
    objA.add();

    cout << "\n--- Creating Object B (Copy of A) ---" << endl;
    IntArr objB = objA;

    cout << "Sum of B: ";
    objB.add();

    cout << "\n--- Exiting (Destructors will run) ---" << endl;
    return 0;
}