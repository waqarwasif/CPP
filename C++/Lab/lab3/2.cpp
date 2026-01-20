//array of objects
//multiple parameters
#include<iostream>
using namespace std;

class My_Class{
    int num;
    int num2;

    public:
    My_Class(int n,int num):num(n),num2(num){}
    void display(){
        cout<<num;
        cout<<num2;
    }

};

int main(){

    My_Class c1[2]={My_Class(1,2),My_Class(3,4)};
    for (int i=0;i<2;i++){
        c1[i].display();
    }
}