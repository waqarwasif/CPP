#include<iostream>
#include<string>
#include<vector>   
using namespace std;


class Chai
{
    private:
        string teaname;
        int servings;

    public:
        Chai(string name , int serve):teaname(name), servings(serve) {}

        void display( ) const{
            cout<< "Tea Name: " << teaname << endl;
        }

        friend bool CompareServings(const Chai &c1, const Chai &c2);


};

bool CompareServings(const Chai &c1, const Chai &c2){
    return c1.servings > c2.servings;   }

int main(){
    Chai masalaChai("Masala Chai", 4);
    Chai gingerChai("Ginger Chai", 8);
    masalaChai.display();
    gingerChai.display();

    if(CompareServings(masalaChai, gingerChai))
    {
        cout << "Masala Chai has more servings than Ginger Chai." << endl;
    }else{
        cout << "Ginger Chai has more servings than Masala Chai." << endl;

    }


}