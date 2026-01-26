#include<iostream>
using namespace std;
class Record{

    string name;
    int age;
    float gpa;
    public:
    void set(){
        cout<<"name: "<<endl;
        cin>>name;
        cout<<"age: "<<endl;
        cin>>age;
        cout<<"gpa: "<<endl;
        cin>>gpa;
    }
    
    Record(){}
    void display();
    

};
void Record::display(){
    cout<<"name "<<name<<endl;
    cout<<"age "<<age<<endl;
    cout<<"gpa "<<gpa<<endl;

}

int main(){
    Record R[10];
    for (int i = 0;i<10;i++){
        cout<<"Enter details for record "<<i+1<<endl;
        R[i].set();

    }
    for (int i = 0;i<10;i++){
        cout<<"Details of record "<<i+1<<endl;
        R[i].display();
        
    }

}


