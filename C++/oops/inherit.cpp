#include<iostream>
#include<string>
#include<vector>

using namespace std;

//base class or parent class or original class

class Tea {
    protected:
        string teaName;
        int servings;
    
    public:
        Tea(string name, int serve): teaName(name), servings(serve) {
            cout << "Tea constructor called for " << teaName << endl;
        }
        virtual void brew() const{
            cout << "Brewing " << teaName << " tea." << endl;
        }

        virtual void serve() const
        {
            cout << "Serving " << servings << " tea." << endl;
        }
        virtual ~Tea() {
            cout << "Tea destructor called for " << teaName << endl;
        }
};

class GreenTea : public Tea {
     public:
        GreenTea(int serve): Tea("Green", serve) {
            cout << "GreenTea constructor called." << endl;
        }
        void brew() const override {
            cout << "Steeping green tea leaves in hot water." << endl;
        }
        ~GreenTea() {
            cout << "GreenTea destructor called." << endl;
        }

};

class MasalaTea : public Tea {
    public:
        MasalaTea(int serve): Tea("Masala", serve) {
            cout << "MasalaTea constructor called." << endl;
        }
        void brew() const override final{ // final prevents further overriding from this class
            cout << "Boiling masala tea with spices." << endl;
        }
        ~MasalaTea() {
            cout << "MasalaTea destructor called." << endl;
        }
};

int main() {
    Tea *tea1 = new GreenTea(2);
    Tea *tea2 = new MasalaTea(3);

    tea1->brew();
    tea1->serve();

    delete tea1;
    tea2->brew();
    tea2->serve();

    delete tea2;
    return 0;
}



