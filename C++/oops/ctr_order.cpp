#include<iostream>
using namespace std;

class Counter {
    protected: 
    unsigned int count ;
    public:
    Counter(){
        cout<<"Counter Constructor called"<<endl;
    }

    Counter(int c){
        count = c;
        cout<<"Counter Parameterized Constructor called"<<endl;
    }
};

class CountDn : public Counter {
    public:
    CountDn(){
        cout<<"CountDn Constructor called"<<endl;
    }

    CountDn(int c) : Counter(c){
        cout<<"CountDn Parameterized Constructor called"<<endl;
    }
};

class CountUp : public Counter {
    public:
    CountUp(){
        cout<<"CountUp Constructor called"<<endl;
    }

    CountUp(int c) : Counter(c){
        cout<<"CountUp Parameterized Constructor called"<<endl;
        //Counter(c);// wrong way to call base class constructor
    }
};


int main(){
    CountUp cu(10);
    CountDn cd(20);
    return 0;
}