#include<iostream>
using namespace std;

class Secret
{
    int a;
    int b;

public:
    // Even though I wrote 'b' first, 'a' is initialized first!
    Secret(int val) : b(val), a(b + 1) {}
    void print(){
        cout<<a<<"   "<<b<<endl;
    }
};

int main(){
    Secret b(3);
    b.print();
}

