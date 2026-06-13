#include<iostream> 
using namespace std;

class DynamicArray{
    int* data;
    int size;

    public:
    DynamicArray(int s):size(s){

        data = new int[size];
    }

    void setValue(int index, int val){
        if (index>=0 || index<size){
            data[index] = val;
        }

    }

    int getValue(int index) const
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        return -1; // Basic error handling
    }
    ~DynamicArray(){
        cout<<"dynamic";
        delete[] data;
        

}
};

int main()
{
    DynamicArray obj(5); // Constructor called
    obj.setValue(0, 10);
    obj.setValue(1, 20);
    obj.setValue(2, 30);
    std::cout << "Value at index 1: " << obj.getValue(1) << std::endl;
    // The destructor is called automatically when 'obj' goes out of scope.return 0;
}
