#include<iostream>
#include<vector>
using namespace std;

class Chai{
    private:
        string teaname;
        int servings;
        vector<string> ingredients;

    public:
        
        Chai(){
            teaname = "Unknown";
            servings = 1;
            ingredients = {"Water", "Tea Leaves", "Sugar"};
        }

        Chai(string name, int serve, vector<string> ingr){
            teaname = name;
            servings = serve;
            ingredients = ingr;
        }

        void display_details() const {
            cout << "Tea Name: " << teaname << endl;
            cout << "Servings: " << servings << endl;
            cout << "Ingredients: " << endl;
            for(const string &ingredient : ingredients){
                cout << "- " << ingredient << endl;
            }
            cout << endl;
        }
        // getter 
        string getTeaName() const {
            return teaname;
        }
        // setter
        void setTeaName(const string &name){
            //logic to validate name can be added here
            teaname = name;
        }
        // getter
        int getServings() const {
            return servings;
        }   
        // setter
        void setServings(int serve){
            if(serve >= 0){
                servings = serve;
            }else{
                cout << "Servings must be positive." << endl;
            }
        }
        // getter
        vector<string> getIngredients() const {
            return ingredients;
        }
        // setter
        void setIngredients(const vector<string> &ingr){
            ingredients = ingr;
        }



    
};

int main(){
    Chai chai1;
    chai1.setTeaName("Masala Chai");
    chai1.setServings(4);
    chai1.setIngredients({"Water", "Tea Leaves", "Milk", "Spices", "Sugar"});
    chai1.display_details();


}