#include<iostream>

class Counter {

    private:
        int value;
    public:
        Counter(): value(0) {}
        
        void increment() {
            value++;
        }
        void decrement() {
            if (value > 0) {
                value--;
            }
        }
        void getValue() {
            std::cout << "Counter Value: " << value << std::endl;
        }

};

int main() {
    Counter c1, c2;

    c1.increment();
    c1.increment();
    c1.increment();
    c1.getValue(); // Should print 3


    return 0;
}