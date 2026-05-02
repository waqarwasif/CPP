#include <iostream>
using namespace std;
const int MAX = 100;

template <class Type>
class Stack
{
    Type st[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(Type var)
    {
        st[++top] = var;
    }
    Type pop()
    {
        return st[top--];
    }
};

int main(){
    Stack<float> s1;
    Stack<long> s2;

    s1.push(1234.56);
    s1.push(5679.90);
    s2.push(343);
    s2.push(444);

    cout<<"s1 pop "<<s1.pop()<<endl;
    cout<<"s2 pop "<<s2.pop();
    return 0;

}
