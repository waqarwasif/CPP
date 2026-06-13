#include<iostream>
using namespace std;
#include<string>


class Student{

    public:
    void study(){
        cout<<"study "<<endl;
    }
    void ID(){

    }
};

class Teacher {
    public:
    void teach(){
        cout<<"Teach "<<endl;
    }
    void ID(){

    }
};

// Multiple Inheritance 
class TeachingAssistant: public Student, public Teacher{
    public:
    void assist(){
        cout<<"TA for good grades "<<endl;

    }
};

int main(){
    
    TeachingAssistant ta;
    ta.study(); // from parent
    ta.teach(); // from parent 
    ta.assist();// own class function

    return 0;
}