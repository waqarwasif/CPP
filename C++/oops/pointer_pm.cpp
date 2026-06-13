#include<iostream>
using namespace std;

class Printer{

    
    public:
    Printer()=default;
    
        virtual void print()
        { // Virtual function for run-time polymorphism
            cout << "Printing using a generic printer" << endl;
        }
        
        virtual ~Printer() {} // Virtual destructor for proper cleanup of derived class objects 
    };
    class InkjetPrinter : public Printer
        {
        public:
            InkjetPrinter(int a);
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
        void demonstratePrinting(Printer * printer)
        {
            printer->print(); // Dynamic dispatch (run-time polymorphism)
             }

int main(){
    Printer *printers[3];
    printers[0] = new InkjetPrinter(3); // this way if parametric constructor 
    printers[1] = new LaserPrinter();
    printers[2] = new _3DPrinter();

    cout << "Printing using array of base pointers:\n";
    for (int i = 0; i < 3; i++)
    {
        printers[i]->print();
    }

    for (int i = 0; i < 3; i++)
        delete printers[i];
    return 0;

}