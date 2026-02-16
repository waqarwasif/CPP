#include <iostream>
#include <string>

using namespace std;

class Post
{
private:
    string name;
    string to;
    float StampCost;

public:
    Post() : name(""), to(""), StampCost(1.0) {}

    virtual ~Post() {}

    virtual void Read()
    {
        cout << "Enter sender's name: ";
        getline(cin, name);
        cout << "Enter recipient's address: ";
        getline(cin, to);
        cout << "Enter stamp cost: ";
        cin >> StampCost;
        cin.ignore();
    }

    virtual void Print()
    {
        cout << "Sender: " << name << endl;
        cout << "Recipient: " << to << endl;
        cout << "Stamp Cost: $" << StampCost << endl;
    }

    virtual float TotalCost()
    {
        return StampCost;
    }
};

class RegisteredPost : public Post
{
private:
    float Weight;
    float RegistrationCost;

public:
    RegisteredPost() : Post(), Weight(20.0), RegistrationCost(10.0) {}

    void Read() override
    {
        Post::Read();
        cout << "Enter weight (gms): ";
        cin >> Weight;
        cout << "Enter registration cost: ";
        cin >> RegistrationCost;
        cin.ignore();
    }

    void Print() override
    {
        Post::Print();
        cout << "Weight: " << Weight << " gms" << endl;
        cout << "Registration Cost: $" << RegistrationCost << endl;
        cout << "Total Combined Cost: $" << TotalCost() << endl;
    }

    float TotalCost() override
    {
        return Post::TotalCost() + RegistrationCost;
    }
};

int main()
{

        RegisteredPost envelope;
        envelope.Read();
        cout << "Post Details..";
        envelope.Print();
        return 0;
    }