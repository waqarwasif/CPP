#include<iostream>
#include<vector>
#include<string>
 

class MyCar{

    public:
        int age;
        void display (){
            std::cout<<" Age "<< age;
        }
        private:

    protected:
        

};



int main(){

    std :: cout << "start";
    MyCar car ;
    car.age = 11;
    car.display();

}