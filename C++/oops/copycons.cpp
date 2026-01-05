#include <iostream>
#include <vector>
using namespace std;

class MyClass
{
public:
    // data members(attributes)
    string* name;                // name of the recipe
    int servings;               // number of servings
    vector<string> ingredients; // list of ingredients

    // default constructor
    MyClass()
    {
        name = new string("Unknown");
        servings = 1;
        ingredients = {"water", "salt", "oil"};
        cout << "Default constructor called. Recipe initialized to default values." << endl;
    }

    // parameterized constructor
    MyClass(string tname, int serve, vector<string> ingr)
    {
        name = new string(tname);
        servings = serve;
        ingredients = ingr;
        cout << "Parameterized constructor called. Recipe initialized to given values." << endl;
    }

    // copy constructor
    MyClass(const MyClass &other){
        name = new string (*other.name); //deep copy
        servings = other.servings;
        ingredients = other.ingredients;
        cout << "Copy constructor called. Deep copy performed for recipe: " << *name << endl;
    }

    //as memory is allocated using new, we should define a destructor to free that memory
    ~MyClass()
    {
        delete name;
        cout << "Destructor called. Memory freed for recipe: "  << endl;
    }

    // member functions (methods)
    void display_details()
    {
        cout << "Recipe: " << *name << endl;
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

    // MyClass recipe2("Spaghetti Bolognese", 6, {"Spaghetti", "Ground Beef", "Tomato Sauce", "Onion", "Garlic"});
    // recipe2.display_details();

    MyClass copyRecipe = recipe1; // Copy constructor called
    copyRecipe.display_details();

    *recipe1.name = "Modified pancakes";
    recipe1.display_details();  


    return 0;
}