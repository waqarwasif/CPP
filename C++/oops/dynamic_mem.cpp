#include<iostream>
using namespace std;
class DynamicArray {
   private:
       int* arr;
       int size;
    public:
    DynamicArray(int s):size(s){
        arr = new int[size];

    }

    ~DynamicArray(){
        cout<<"deleting";
        delete [] arr;
    }
    void setvalues(){
        for (int i = 0; i < 2; i++)
        {
            cout<< "enter value"<< i+1<<endl;
            cin>> arr[i] ;
        }
    }
    void display();
};
void DynamicArray::display(){
    for(int i=0;i<2;i++){
        cout<<arr[i]<<endl;
    }


}

int main(){
    DynamicArray a1(2);
    a1.setvalues();
    a1.display();
    

}