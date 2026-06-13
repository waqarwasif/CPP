# include <iostream>
using namespace std;

class Printer
{
public:
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

    void demonstratePrinting(Printer *printer)
    {
        printer->print();
    }

    int main(){
        // Create objects of derived classes
        InkjetPrinter inkjet;
        LaserPrinter laser;
        _3DPrinter threeD;
        // Call demonstratePrinting with different printer objects
        cout << "Printing with different printers:" << endl;
        demonstratePrinting(&inkjet); // Calls InkjetPrinter's print
        demonstratePrinting(&laser);  // Calls LaserPrinter's print
        demonstratePrinting(&threeD); // Calls 3DPrinter's print
        return 0;
    }