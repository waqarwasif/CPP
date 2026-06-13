 #include <iostream>
using namespace std;

// class A{

//     public:
//     A(){
//         cout<<"Base class A constructor called"<<endl;
//     }
//     void display(){
//         cout<<"Base class A"<<endl;
//     }
// };

// class B: public A{

//     public:
//         B(){
//             cout<<"Derived class B constructor called"<<endl;
//         }
//     void display(){
//         cout<<"Derived class B"<<endl;
//     }
// };

// class C: public A{

//     public:
//         C(){
//             cout<<"Derived class C constructor called"<<endl;
//         }
//     void display(){
//         cout<<"Derived class C"<<endl;
//     }
// };

// class D: public B, public C{

//     public:
//         D(){
//             cout<<"Derived class D constructor called"<<endl;
//         }
//     void display(){
//         cout<<"Derived class D"<<endl;
//     }
// };

// int main(){
//     D d;                                                        
//     d.display(); // Calls D's display
//     d.B::display(); // Calls B's display
//     d.C::display(); // Calls C's display                        
//     return 0;
// }

// result:
/*
Derived class B constructor called
Base class A constructor called
Derived class C constructor called
Derived class D constructor called
Derived class D
Derived class B
Derived class C
*/
// Explanation:
// In this code, we have a class hierarchy where class D inherits from both B and C, which in turn inherit from A. This creates a diamond-shaped inheritance structure. When we create an object of class D, the constructors are called in the following order:
// 1. B's constructor is called, which first calls A's constructor (since B inherits from A).
// 2. C's constructor is called, which also calls A's constructor (since C inherits from A).
// 3. Finally, D's constructor is called.
// When we call d.display(), it calls D's display method. To call B's and C's display methods, we need to specify which base class's display method we want to call using the scope resolution operator (::). This is necessary because both B and C have their own display methods, and without specifying, it would be ambiguous which one to call.

// solution to diamond problem: virtual inheritance

class A{

    public:
    A(){
        cout<<"Base class A constructor called"<<endl;
    }
    void display(){
        cout<<"Base class A"<<endl;
    }
};

class B: virtual public A{

    public:
        B(){
            cout<<"Derived class B constructor called"<<endl;
        }
    void display(){
        cout<<"Derived class B"<<endl;
    }
};

class C: virtual public A{

    public:
        C(){
            cout<<"Derived class C constructor called"<<endl;
        }
    void display(){
        cout<<"Derived class C"<<endl;
    }
};

class D: public B, public C{

    public:
        D(){
            cout<<"Derived class D constructor called"<<endl;
        }
    void display(){
        cout<<"Derived class D"<<endl;
    }
};

int main(){
    D d;                                                        
    d.display(); // Calls D's display
    d.B::display(); // Calls B's display
    d.C::display(); // Calls C's display                        
    return 0;
}
