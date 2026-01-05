#include<iostream>
#define DT int32_t
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PRINT_VAR(var) std::cout << #var << " = " << var << std::endl;
int main() {
    DT num = 5;
    DT a = 10, b = 20;

    std::cout << "Square of " << num << " is " << SQUARE(num) << std::endl;
    std::cout << "Max of " << a << " and " << b << " is " << MAX(a, b) << std::endl;

    PRINT_VAR(num);
    PRINT_VAR(a);
    PRINT_VAR(b);

    return 0;
}