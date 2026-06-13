#include <iostream>
using namespace std;
class Page
{
    int layers;

public:
    Page(int a):layers(a)
    {

        cout << "Page created" << endl;
    }
    ~Page()
    {
        cout << "Page destroyed" << endl;
    }
};
class Book
{
private:
    Page page;

public:
    Book() : page(3)
    {
        cout << "Book created" << endl;
    }
    ~Book()
    {
        cout << "Book destroyed" << endl;
    }
};

class Book2
{
private:
    Page page;

public:
    Book2():page(3)
    {
        cout << "Book created" << endl;
    }
    ~Book2()
    {
        cout << "Book destroyed" << endl;
    }
};
int main()
{
    Book myBook;
    return 0;
}