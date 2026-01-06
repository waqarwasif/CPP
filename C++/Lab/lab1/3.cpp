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
        void setName(string n){
                name  = n;
            }
            
        void setroll(int roll){
                rollno = roll;
            }   
        void setMarks(vector<int> m){
                marks = m;
            } 
        void getName(){
                cout<<name;
            }
            
        void getroll(){
                cout<<rollno;
            }   
        void getMarks(){
                for(const int &mark : marks){
                    cout << "-" << mark <<endl;
                }
            } 


    private:
            

    protected:
        

};
// void ComplexNumber::print()
//     {
//             if (img<0)
//             {
                
//                 std::cout<<" The Complex number is : "<< real << img<<"i";
//             }
//             else{
//                 std::cout<<" The Complex number is : "<< real <<"+"<< img<<"i";

//             }
// }
void Student :: print()
{

    cout<<name<<endl;
    cout<<rollno<<endl;
    for(const int &mark : marks){
                    cout << mark <<endl;
                }
    
}

void Student :: avg(){
    float avg=0;
    for(const int &mark : marks){
                    avg +=mark;
                    cout<<"avg : "<< avg/3<<endl;
                }
    
}



int main(){

    
    Student s1 ;
    s1.setName("Waqar");
    s1.setroll(123);
    s1.setMarks({88,99,100});
    s1.print();


}