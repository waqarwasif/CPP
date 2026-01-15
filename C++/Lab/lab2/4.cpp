#include<iostream>
#include<string>
#include<vector>

using namespace std;
class ComplexNumber{
int real;
int img;

public:
// Default used to intialize the values;
ComplexNumber();
//
ComplexNumber(int r,int i=0);

void display();

};
ComplexNumber::ComplexNumber():real(0),img(0){}
void ComplexNumber::display(){
    if (img<0){
        
        cout<<real<<img<<endl;
    }
    else{

        cout<<real<<"+"<<img<<endl;
    }
}

ComplexNumber::ComplexNumber(int r,int i=0):real(r),img(i){}



int main(){

    return 0;
}