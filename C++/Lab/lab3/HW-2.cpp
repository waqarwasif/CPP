#include <iostream>
using namespace std;
class Record
{
    string name;
    int age;
    float gpa;

public:
    int rollno;
    void set()
    {
        cout << "roll no: " << endl;
        cin >> rollno;
        cout << "name: " << endl;
        cin >> name;
        cout << "age: " << endl;
        cin >> age;
        cout << "gpa: " << endl;
        cin >> gpa;
    }

    Record() {}
    void display();
};
void Record::display()
{
    cout << "roll no " << rollno << endl;
    cout << "name " << name << endl;
    cout << "age " << age << endl;
    cout << "gpa " << gpa << endl;
}

int main()
{
    Record *ptr;
    Record R[2];
    ptr = R;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter details for record " << i + 1 << endl;
        R[i].set();
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "Details of record " << i + 1 << endl;
        (ptr+i)->display();
    }

    cout << "Enter a roll no. to search for the record: ";
    int roll;
    cin >> roll;

    for (int i = 0; i < 2; i++)
    {
        if((ptr+i)->rollno == roll)
        {
            cout << "Record found: " << endl;
            (ptr+i)->display();
            break;
        }
    }
}
