#include <iostream>
#include <stdexcept>
using namespace std;

class Rooms
{
    string name;
    int size;

public:
    Rooms() : name("Empty"), size(0) {}
    Rooms(string n, int s) : name(n), size(s)
    {
    }
    void display() const
    {
        cout << "Name: " << name << "\nsize: " << size << endl;
    }
};

class House
{

    Rooms room[3];
    int roomcount;
    string addr;

public:
    House(string add)
    {
        addr = add;
        roomcount = 0;
    }

    void addRoom(const string &name, int size)
    {
        if (roomcount == 3)
        {
            throw overflow_error("Already created Maximum rooms no more rooms can be added");
        }
        room[roomcount++] = Rooms(name, size);
    }
    void display() const
    {
        cout << "House Address: " << addr << endl;
        for (int i = 0; i < roomcount; i++)
        {
            cout << endl;
            room[i].display();
        }
    }
};

int main()
{
    House house("Gulshan-e-Iqbal");
try{

    house.addRoom("Living", 15);
    house.addRoom("Living", 15);
    house.addRoom("Living", 15);
    house.display();
    house.addRoom("Living", 15);
    house.addRoom("Living", 15);
}
catch (overflow_error &e){
    cout<<e.what();
}
return 0;
}