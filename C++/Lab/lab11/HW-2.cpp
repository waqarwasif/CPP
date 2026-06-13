#include <iostream>
using namespace std;

class Worker
{
public:
    void work()
    {
        cout << "Working as an employee" << endl;
    }
};

class Freelancer
{
public:
    void work()
    {
        cout << "Working independently" << endl;
    }
};

class HybridWorker : public Worker, public Freelancer
{
public:
    // (c) Resolving ambiguity by overriding work()
    void work()
    {
        cout << "Working both ways" << endl;
    }
};

int main()
{
    HybridWorker h;

    // (b) Resolving ambiguity using scope resolution operator
    h.Worker::work();
    h.Freelancer::work();

    // (c) Calling the overridden method
    h.work();

    return 0;
}