#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student{
    std :: string name;
    int rollno;
    std :: vector <int> marks; 
    public:
        void print ();
        void avg();
        void setName(string n);
        void setroll(int roll);  
        void setMarks(vector<int> m);
        void getName();
        void getroll();  
        void getMarks(); 
    private:
    protected:     
};

void Student :: print()
{
    int i = 1;
    cout<<"Student name : "<<name<<endl;
    cout<<"Roll no : "<<rollno<<endl;
    for(const int &mark : marks){
                    cout << "Quiz " << i++ << " : " << mark <<endl;
                }}

void Student :: avg(){
    float avg=0;
    for(const int &mark : marks){
                    avg +=mark;
                }
                cout<<"avg : "<< avg/3<<endl;
}
void Student::setName(string n)
{
    name = n;
}
void Student::setroll(int roll)
{
    rollno = roll;
}
void Student::setMarks(vector<int> m)
{
    marks = m;
}
void Student::getName()
{
    cout << name;
}
void Student::getroll()
{
    cout << rollno;
}
void Student::getMarks()
{
    for (const int &mark : marks)
    {
        cout << "-" << mark << endl;
    }
}

int main(){

    
    Student s1 ;
    s1.setName("Waqar");
    s1.setroll(123);
    s1.setMarks({88,99,100});
    s1.print();
    s1.avg();


}