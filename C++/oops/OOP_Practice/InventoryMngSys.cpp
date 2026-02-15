#include<iostream>
#include<limits>
#include<string>
using namespace std;

void getPositiveInput(double &value, const string &prompt) {
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            break;
        } else {
            cout << "Invalid input. Value must be positive. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void getPositiveInput(int &value, const string &prompt) {
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            break;
        } else {
            cout << "Invalid input. Value must be positive. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void getPositiveInput(float &value, const string &prompt) {
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0 && value < 100) {
            break;
        } else {
            cout << "Invalid input. Value must be positive and less than 100. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}



class InventoryItem {

    protected:
        string name;
        double unitPrice;

    public:

        InventoryItem() : name(""), unitPrice(0.0) {}

        virtual void input() {
            cout << "Enter item name: ";
            getline(cin, name);
            getPositiveInput(unitPrice, "Enter unit price: ");
        }

        virtual void display() {
            cout << "Item Name: " << name << endl;
            cout << "Unit Price: $" << unitPrice << endl;
            cout << "Total Price: $" << calculateTotalPrice() << endl;
        }

        virtual double calculateTotalPrice() {
            // This will be overridden in derived classes
            return unitPrice;
        }

        virtual ~InventoryItem() {}

};

class BulkItem : public InventoryItem {

    private:
        int quantity;

    public:

        BulkItem() : quantity(0) {}

        void input() override {
            InventoryItem::input();
            getPositiveInput(quantity, "Enter quantity: ");
        }

        double calculateTotalPrice() override {
            return unitPrice * quantity;
        }

        void display() override {
            InventoryItem::display();
            cout << "Quantity: " << quantity << endl;
        }
};

class DiscountedItem : public InventoryItem {

    private:
        float discountPercentage;

    public:

        DiscountedItem() : discountPercentage(0.0) {}

        void input() override {
            InventoryItem::input();
            getPositiveInput(discountPercentage, "Enter discount percentage: ");
        }

        double calculateTotalPrice() override {
            return unitPrice * (1 - discountPercentage / 100);
        }

        void display() override {
            InventoryItem::display();
            cout << "Discount Percentage: " << discountPercentage << "%" << endl;
        }
};

class ImportedItem : public InventoryItem {

    private:
        float importtaxPercentage;

    public:

        ImportedItem() : importtaxPercentage(0.0) {}

        void input() override {
            InventoryItem::input();
            getPositiveInput(importtaxPercentage, "Enter import tax percentage: ");
        }

        double calculateTotalPrice() override {
            return unitPrice * (1 + importtaxPercentage / 100);
        }

        void display() override {
            InventoryItem::display();
            cout << "Import Tax Percentage: " << importtaxPercentage << "%" << endl;
        }
};

int main(){

    int n;
    cout << "Enter number of inventory items: ";
    cin >> n;
    cin.ignore(); // Clear the newline character from the input buffer
    InventoryItem **items = new InventoryItem*[n];
    for(int i = 0; i < n; ++i) {
        int choice;
        cout << "Select item type for item " << (i + 1) << ":" << endl;
        cout << "1. Regular Item" << endl;
        cout << "2. Bulk Item" << endl;
        cout << "3. Discounted Item" << endl;
        cout << "4. Imported Item" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch(choice) {
            case 1:
                items[i] = new InventoryItem();
                break;
            case 2:
                items[i] = new BulkItem();
                break;
            case 3:
                items[i] = new DiscountedItem();
                break;
            case 4:
                items[i] = new ImportedItem();
                break;
            default:
                cout << "Invalid choice. Defaulting to Regular Item." << endl;
                items[i] = new InventoryItem();
        }

        
    }

    for(int i = 0; i < n; ++i) {
        cout << endl;
        cout << "================ DETAILS FOR ITEM " << (i + 1) << " ================" << endl;
        items[i]->input();
    }   

    for(int i = 0; i < n; ++i) {
        cout << endl;
        cout << "================ DETAILS FOR ITEM " << (i + 1) << " ================" << endl;
        items[i]->display();
    }

    // Clean up
    for(int i = 0; i < n; ++i) {
        delete items[i];
    }
    delete[] items;
    return 0;



}