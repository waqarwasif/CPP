#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Gradebook_System
{
    int roll_no;
    string name;
    vector <float> marks;

    public:
        Gradebook_System(int r,string n,vector<float> m): name(n) , roll_no(r) , marks(m){}
        void display();
        float avg();
        bool is_passed();
        void setName(string n)
        {
            name = n;
        }

        void setroll(int roll)
        {
            roll_no = roll;
        }
        void setMarks(vector<float> m)
        {
            marks = m;
        }
        string getName()
        {
            return name;
        }

        int getroll()
        {
            return roll_no;
        }
        void getMarks()
        {
            for (const int &mark : marks)
            {
                cout << "-" << mark << endl;
            }
        }

};
float Gradebook_System ::avg()
{
    int i = 0;
    float avg = 0;
    for (const int &mark : marks)
    {
        avg += mark;
        i++;

    }
    avg = avg/i;
    return avg;
}

void Gradebook_System ::display()
{
    int i = 1;
    cout << "Student name : " << name << endl;
    cout << "Roll no : " << roll_no << endl;
    for (const int &mark : marks)
    {
        cout << "Quiz " << i++ << " : " << mark << endl;
    }
}

bool Gradebook_System ::is_passed()
{
    return (avg()>50);
}

int main(){
    Gradebook_System S1(123,"Waqar",{92,93,95,88,78,87});
    if(S1.is_passed()){
        cout << "Congratulations for you achievement!!"<< endl;
    }
    else{
        cout << "Try again next time...."<< endl;
    }

    S1.display();
    
    cout<<"Average: "<<S1.avg()<<endl;

}