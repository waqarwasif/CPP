#include <iostream>
using namespace std;
class Room
{
    string name;
    int sqft;

public:
    Room()
    {
        name = "";
        sqft = 0;
    }
    Room(int s, string n) : sqft(s), name(n)
    {
    }

    void Display()
    {
        cout << "Name: " << name << "Sqft: " << sqft << endl;
    }
};

class House
{
    string add;
    Room rooms[3];
    int rcount;

public:
    House(string a)
    {
        add = a;
        rcount = 0;
    }
    void addRoom(int s, string n)
    {
        if (rcount < 3)
        {
            rooms[rcount++] = Room(s, n);
        }
        else
        {

            cout << "Maximum rooms have been created already ";
        }
    }
    void show()
    {
        cout << "House No: " << add << " has " << rcount << " rooms, namely " << endl;
        for (int i = 0; i < rcount; i++)
        {
            rooms[i].Display();
        }
    }
};
int main()
{
    House h1("ABC street, Block 6");
    h1.addRoom(10, "Dining Room");
    h1.addRoom(20, "Kitchen");
    h1.addRoom(10, "Bedroom");
    h1.show();
}