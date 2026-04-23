#include<iostream>
using namespace std;

class Fraction{

    int num,den;
    public:
    Fraction(){
        num = 1;
        den = 1; // cannot be zero as it is a denominator 
    }
    Fraction(int n,int d){
        num = n;
        den = d;
        if(d == 0){
            cout<<"Denominator cannot be zero... System has set the denominator to 1"<< endl;
            den = 1;
        }

    }
    friend Fraction Reduce(const Fraction obj); // contains gcd logic and all reduce fraction implementation
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend ostream& operator<<(ostream &o, Fraction f);
    
};

Fraction Reduce(const Fraction obj){
    // gcd logic 
    int a = obj.num;
    int b = obj.den;

    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }

    return Fraction(obj.num/a , obj.den/a);
}

Fraction operator+(const Fraction& f1, const Fraction& f2){
    Fraction fr1 = Reduce(f1);
    Fraction fr2 = Reduce(f2);
    // num = ad + bc
    // den = bd
    Fraction result(fr1.num*fr2.den + fr1.den*fr2.num, fr1.den*fr2.den);
    return Reduce(result);
}

Fraction operator-(const Fraction& f1, const Fraction& f2){
    Fraction fr1 = Reduce(f1);
    Fraction fr2 = Reduce(f2);
    // num = ad - bc
    // den = bd
    Fraction result(fr1.num * fr2.den - fr1.den * fr2.num, fr1.den * fr2.den);
    return Reduce(result);
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
    Fraction fr1 = Reduce(f1);
    Fraction fr2 = Reduce(f2);
    // num = a*c
    // den = b*d
    Fraction result(fr1.num * fr2.num, fr1.den * fr2.den);
    return result;
}

bool operator==(const Fraction& f1, const Fraction& f2){
    Fraction fr1 = Reduce(f1);
    Fraction fr2 = Reduce(f2);
    return (fr1.num == fr2.num  && fr1.den == fr2.den);
}

ostream &operator<<(ostream &o, Fraction f){
    o<<"Fraction is "<<f.num<<" / "<<f.den<<endl;
    return o;
}

int main(){

    // 1. Test Constructors
    Fraction f1(1, 2); // 1/2
    Fraction f2(2, 4); // 2/4 (Should reduce to 1/2)
    Fraction f3(3, 4); // 3/4

    cout << "--- Initial Fractions ---" << endl;
    cout << f1 << f2 << f3 << endl;

    // 2. Test Addition
    Fraction sum = f1 + f3;
    cout << "--- Addition (1/2 + 3/4) ---" << endl;
    cout << "Result: " << sum << endl;

    // 3. Test Subtraction
    Fraction diff = f3 - f1;
    cout << "--- Subtraction (3/4 - 1/2) ---" << endl;
    cout << "Result: " << diff << endl;

    // 4. Test Multiplication
    Fraction prod = f1 * f3;
    cout << "--- Multiplication (1/2 * 3/4) ---" << endl;
    cout << "Result: " << prod << endl;

    // 5. Test Equality (Comparison)
    cout << "--- Comparison (1/2 == 2/4) ---" << endl;
    if (f1 == f2)
    {
        cout << "f1 and f2 are equivalent." << endl;
    }
    else
    {
        cout << "f1 and f2 are not equivalent." << endl;
    }

    // 6. Test Error Handling (Denominator 0)
    cout << "\n--- Testing Denominator Zero ---" << endl;
    Fraction fZero(5, 0);
    cout << fZero << endl;

    return 0;
}