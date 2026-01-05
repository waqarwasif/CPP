#include<iostream>
#include<vector>
using namespace std;

class MyClass
{
public:
    // data members(attributes)
    string name;                // name of the recipe
    int servings;               // number of servings
    vector<string> ingredients; // list of ingredients

    // default constructor
    MyClass(){
        name = "Unknown";
        servings = 1;
        ingredients = {"water", "salt", "oil"};
        cout<< "Default constructor called. Recipe initialized to default values." << endl;
    }

    // parameterized constructor
    MyClass(string name, int serve,vector<string> ingr)
    {
        name = name;
        servings = serve;
        ingredients = ingr;
    }

    // member functions (methods)
    void display_details()
    {
        cout << "Recipe: " << name << endl;
        cout << "Servings: " << servings << endl;
        cout << "Ingredients: " << endl;
        for (string ingredients : ingredients)
        {
            cout << "- " << ingredients << endl;
        }
        cout << endl;
    }
};

int main()
{

    MyClass recipe1("Pancakes", 4, {"Flour", "Eggs", "Milk", "Sugar", "Baking Powder"});
    recipe1.display_details();

    MyClass recipe2("Spaghetti Bolognese", 6, {"Spaghetti", "Ground Beef", "Tomato Sauce", "Onion", "Garlic"});
    recipe2.display_details();
    
    return 0;
}