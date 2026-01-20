//array of objects
#include<iostream>
using namespace std;

class My_Class{
    int num;

    public:
    My_Class(int n):num(n){}
    void display(){
        cout<<num;
    }

};

int main(){

    My_Class c1[3]={1,2,3};
    for (int i=0;i<3;i++){
        c1[i].display();
    }
}