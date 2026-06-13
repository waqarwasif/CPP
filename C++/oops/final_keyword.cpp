#include <iostream>
using namespace std;

class A
{
    virtual void go() { puts("A"); }
};
class B : A
{
    // Overrides A::go(). No need to specify `virtual` explicitly,
    // it already implicitly is virtual and overrideable
    void go() override { puts("B"); }
};
class C : B
{
    void go() final { puts("C"); }
    // virtual void go() override final { puts("C"); } would still compile,
    //  but it is considered, for lack of a better description, "extra"
};
class D : C
{
    // Would produce error C3248 : 'C::go' : function declared as 'final' cannot be overridden by 'D::go'
    // void go() override { puts("D"); }
};