#include<iostream>
#include<string>
#include<vector>

using namespace std;
class ComplexNumber{
int real;
int img;

public:
// Default used to get the values from user;
ComplexNumber(){
    cout<<"real"<<endl;
    cin>>real;
    cout<<"img"<<endl;
    cin>>img;

}

void display();

};
void ComplexNumber::display(){
    if (img<0){
        
        cout<<real<<img<<endl;
    }
    else{

        cout<<real<<"+"<<img<<endl;
    }
}



int main(){

    return 0;
}