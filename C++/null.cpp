#include<iostream>

void printval(int *ptr){
    if(ptr == nullptr){
        std::cout << "Pointer is null." << std::endl;
    } else {
        std::cout << "Pointer value: " << *ptr << std::endl;
    }
}
int main(){
    printval(nullptr);
    int value = 42;
    printval(&value);
    return 0;


}