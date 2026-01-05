#include <iostream>
#include <vector>
using namespace std;

class Chai{
    public:
        string teaname;
        int servings;
        vector<string> ingredients;

        //delegation constructor
        Chai(string name) : Chai(name, 1, {"Water", "Tea Leaves", "Sugar"}) {
            cout << "Delegation constructor called. Recipe initialized with default servings and ingredients." << endl;
        }

        //main constructor
        Chai(string name, int serve, vector<string> ingr){
            teaname = name;
            servings = serve;
            ingredients = ingr;
            cout << "Main constructor called. Recipe initialized to given values." << endl;
        }
        void display_details() const
        {
            cout << "Tea Name: " << teaname << endl;
            cout << "Servings: " << servings << endl;
            cout << "Ingredients: " << endl;
            for (const string &ingredient : ingredients)
            {
                cout << "- " << ingredient << endl;
            }
            cout << endl;
        }
};

int main(){

    Chai chai1("Masala Chai");
    chai1.display_details();

    

}

