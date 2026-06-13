#include<iostream>
using namespace std;
class Printer
{

public:
    Printer() = default;

    virtual void print()
    { // Virtual function for run-time polymorphism
        cout << "Printing using a generic printer" << endl;
    }

    virtual ~Printer() {} // Virtual destructor for proper cleanup of derived class objects
};
class InkjetPrinter : public Printer
{
public:
    void print() override
    {
        cout << "Printing using an Inkjet Printer" << endl;
    }
};
class LaserPrinter : public Printer
{
public:
    void print() override
    {
        cout << "Printing using a Laser Printer" << endl;
    }
};
class _3DPrinter : public Printer
{
public:
    void print() override
    {
        cout << "Printing using a 3D Printer" << endl;
    }
};
// Function to demonstrate polymorphism
void demonstratePrinting(Printer *printer)
{
    printer->print(); // Dynamic dispatch (run-time polymorphism)
}

int main()
{
    int n;
    LaserPrinter a;
    a.print();
    Printer b;
    b.print();
    cout << "How many printers? ";
    cin >> n;
    Printer **arr = new Printer *[n]; // dynamic array of base pointers
    for (int i = 0; i < n; i++)
    {
        int choice;
        cout << "1) Inkjet 2) Laser : ";
        cin >> choice;
        if (choice == 1)
            arr[i] = new InkjetPrinter();
        else
            arr[i] = new LaserPrinter();
    }
    cout << "\n--- Printing ---\n";
    for (int i = 0; i < n; i++)
        arr[i]->print();
    for (int i = 0; i < n; i++)
        delete arr[i];
    delete[] arr;
    return 0;
}