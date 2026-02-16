#include <iostream>
#include <string>

using namespace std;

class Product
{
protected:
    string name;
    string productID;

public:
    Product(string n, string id) : name(n), productID(id) {}

    virtual void showData()
    {
        cout << "Product Name: " << name << endl;
        cout << "Product ID: " << productID << endl;
    }

    virtual ~Product() {}
};

class UtilityItem : public Product
{
private:
    float discount;

public:
    UtilityItem(string n, string id, float d) : Product(n, id), discount(d) {}

    void showData() override
    {
        Product::showData();
        cout << "Discount: " << discount << "%" << endl;
    }
};

class FoodItem : public Product
{
private:
    string expiryDate;

public:
    FoodItem(string n, string id, string date) : Product(n, id), expiryDate(date) {}

    void showData() override
    {
        Product::showData();
        cout << "Expiry Date: " << expiryDate << endl;
    }
};

int main()
{
    UtilityItem u1("Washing Powder", "U101", 10.5);
    FoodItem f1("Milk Pack", "F202", "20-12-2025");

    cout << "UTILITY ITEM DETAILS" << endl;
    u1.showData();

    cout << endl
         << "FOOD ITEM DETAILS" << endl;
    f1.showData();

    return 0;
}