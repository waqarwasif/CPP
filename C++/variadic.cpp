#include<iostream>
#include<string>
using namespace std;

template<typename T>
void func(T t){
    cout << "f1 "<< t << endl;
}

template<typename T, typename... Args>
void func(T t, Args... args){
    cout << "f2 " << t << endl;
    func(args...);
}

int main(){
    func(1, 2.5, "Hello", string("Variadic Templates"), 'A');
    return 0;
}