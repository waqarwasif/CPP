#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
    int *arr;
    int count, size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        count = 0;
    }

    void Push(int a)
    {
        if (count == size)
        {
            throw overflow_error("Stack full.. Unable to push more items");
        }

        arr[count++] = a;
    }

    void Pop()
    {
        if (count == 0)
        {
            throw underflow_error("No item in stack.. please enter first to unable pop funciton.");
        }

        count--;
        arr[count] = 0;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            
            cout << "item " << i + 1 << " : " << arr[i] << endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    try
    {
        Stack s(3);
        for (int i = 0; i < 3; i++)
        {
            s.Push(i + 1);
        }

        s.display();
        s.Push(4);
    }
    catch (const exception &e)
    {
        
        cout << "\nException Caught: " << e.what() << endl;
    }
}
