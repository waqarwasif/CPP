#include<iostream>

struct User
{
    const int id;
    int age ;
    User():id(0), age(0) {}
};


int main() {
    using namespace std;
    //stack
    int score = 100;
    User mike;
    //heap
    int *heap_score = new int;
    *heap_score = 200;
    User *jack = new User();
    

    delete heap_score;
    delete jack;
    return 0;
}