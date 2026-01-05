#include <iostream>
#include <vector>
using namespace std;

class MyClass
{
public:
    // data members(attributes)
    string name;                // name of the recipe
    int servings;               // number of servings
    vector<string> ingredients; // list of ingredients

    // default constructor
    //if we don't define a constructor, compiler provides a default constructor that is called every time an object is created
    MyClass(){
        name = "Unknown";
        servings = 1;
        ingredients = {"water", "salt", "oil"};
        cout<< "Default constructor called. Recipe initialized to default values." << endl;
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

    MyClass recipe1;
    recipe1.name = "Pancakes";
    recipe1.servings = 4;
    recipe1.ingredients = {"Flour", "Eggs", "Milk", "Sugar", "Baking Powder"};
    recipe1.display_details();

    MyClass recipe2;
    recipe2.name = "Spaghetti Bolognese";
    recipe2.servings = 6;
    recipe2.ingredients = {"Spaghetti", "Ground Beef", "Tomato Sauce", "Onion", "Garlic"};
    recipe2.display_details();
    return 0;
}