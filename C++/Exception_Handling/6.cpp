#include<iostream>
#include<stdexcept> 

using namespace std;
int main()
{
    double numerator,denominator, arr[4] = {0};
    int index;

    cout<<"Enter index number: ";
    cin>>index;

    try{
        if(index<0 || index>3)
        throw overflow_error("Out of bound access!");

        cout<<"Enter Numerator: ";
        cin>>numerator;

        cout<<"Enter Denominator: ";
        cin>>denominator;

        if(denominator == 0)
        throw logic_error("denominar cannot be zero otherwise undefined behaviour occur");

        arr[index]=numerator/denominator;
        cout<<"Answer: "<< arr[index];
    }
    catch (logic_error& e){
        cout<<e.what();
    }
  
    catch (overflow_error& e){
        cout<<e.what();
    }

    


    
}