#include <iostream>
#include <cstring>

using namespace std;

class Distance{

    private:
    int feet ;
    float inches;

    public:
    void data(){
        cout<<"Enter data";
        cin>>feet;
        cin>>inches;
    }
    void display(){
        cout<<feet<<" "<<inches<<endl;
    }
};

int main(){
    
    Distance d1;
    d1.data();
    d1.display();
    Distance *dptr;
    dptr = new Distance;
    dptr->data();
    dptr->display();
    delete dptr;
    dptr = nullptr;


    // another approach 
    // Distance &d1 = *(new Distance);
    // d1.data();
    // d1.display(); 
    // delete &d1;

    return 0;
}