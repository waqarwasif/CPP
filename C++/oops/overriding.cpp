#include<iostream>
using namespace std;

class stack{

    protected:
    enum{max=3};
    int st[max];
    int top;

    public:
    stack(){
        top=-1;
    }
    void push(int var){
        st[++top]=var;
    }
    int pop(){
        return st[top--];
    }
    
};

class stack2:public stack{
    public:
    void push(int var){
        if(top==max-1){
            cout<<"Stack is full"<<endl;
        }
        else{
            st[++top]=var;
        }
    }
};