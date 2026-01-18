#include <iostream>

class Counter
{

private:
    int value;

public:
    Counter() : value(0) {}

    void increment()
    {
        value++;
    }
    void decrement()
    {
        if (value > 0)
        {
            value--;
        }
    }
    void getValue()
    {
        std::cout << "Counter Value: " << value << std::endl;
    }
    friend void reset(Counter& c);
};

void reset(Counter& c){
    c.value = 0;
}

int main()
{
    Counter c1, c2;

    c1.increment();
    c1.increment();
    c1.increment();
    c1.getValue(); // Should print 3

    reset(c1);
    c1.getValue(); // Should print 0

    return 0;
}