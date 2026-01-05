#include<iostream>
using namespace std;

void greet() {
    cout << "Hello from the greet function!" << endl;
}

int main(){
    // Declare a pointer to a function that takes no parameters and returns void
    void (*funcPtr)() = greet;

    // Call the function using the function pointer
    funcPtr();
    (*funcPtr)();

    return 0;

}