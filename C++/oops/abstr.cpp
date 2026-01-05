#include<iostream>
#include<string>
using namespace std;

// program is inspired by Apple (IOS) Camera implementation

class Tea {
    public:
        virtual void prepareIngredients() = 0;// pure virtual function
        virtual void brew() = 0;
        virtual void serve() = 0;

        void makeTea() {
            prepareIngredients();
            brew();
            serve();
        }
};

class GreenTea : public Tea {
    public:
        void prepareIngredients() override {
            cout << "Preparing green tea leaves and hot water." << endl;
        }
        void brew() override {
            cout << "Brewing green tea." << endl;
        }
        void serve() override {
            cout << "Serving green tea." << endl;
        }
};

class MasalaTea : public Tea
{
public:
    void prepareIngredients() override
    {
        cout << "Preparing masala tea leaves and hot water." << endl;
    }
    void brew() override
    {
        cout << "Brewing masala tea." << endl;
    }
    void serve() override
    {
        cout << "Serving masala tea." << endl;
    }
};

int main() {

    GreenTea greenTea;
    MasalaTea masalaTea;

    greenTea.makeTea();
    masalaTea.makeTea();
}