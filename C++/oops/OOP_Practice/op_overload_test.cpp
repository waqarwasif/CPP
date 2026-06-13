#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
private:
    int degree;  // The highest power of x
    int *coeffs; // Dynamic array holding coefficients
                 // Index 0 is x^0, Index 1 is x^1, etc.

public:
    // Basic Constructor
    Polynomial(int deg) : degree(deg)
    {
        coeffs = new int[degree + 1]{0}; // Initialize all to 0
    }

    // Copy Constructor (Provided for safety)
    Polynomial(const Polynomial &other) : degree(other.degree)
    {
        coeffs = new int[degree + 1];
        for (int i = 0; i <= degree; ++i)
        {
            coeffs[i] = other.coeffs[i];
        }
    }

    // Destructor (Provided for safety)
    ~Polynomial()
    {
        delete[] coeffs;
    }

    // ==========================================
    // TODO: WRITE YOUR OPERATOR DECLARATIONS HERE
    // ==========================================
    Polynomial &operator= (const Polynomial& p2);
    Polynomial operator+(const Polynomial &p2);
    Polynomial &operator+=(const Polynomial &p2);
    bool operator==(const Polynomial &p2);
    Polynomial &operator++();
    Polynomial operator++(int a);
    int& operator[](int index);
    int operator()(int value);
    friend ostream& operator<<(ostream &out,const Polynomial &p);
    friend istream& operator>>(istream &in,Polynomial &p);


};

// ==========================================
// TODO: WRITE YOUR OPERATOR DEFINITIONS HERE
// ==========================================
bool Polynomial::operator==(const Polynomial &p2)
{
    if(degree!=p2.degree)return false;
    for(int i=0;i<=degree;i++){
        if(coeffs[i] != p2.coeffs[i])return false;
    }
    return true;
    
}

Polynomial &Polynomial::operator+=(const Polynomial &p2)
{
    for (int i = 0; i <= degree; i++){
        coeffs[i]+=p2.coeffs[i];
    }
    return *this;
}

Polynomial &Polynomial::operator=(const Polynomial &p2)
{
    if(this == &p2) return *this;
    delete [] coeffs;
    degree = p2.degree;
    coeffs = new int [p2.degree +1];
    for (int i = 0; i <= degree; ++i)
    {
        coeffs[i] = p2.coeffs[i];
    }
    return *this;
}
Polynomial& Polynomial::operator++()
{
    for (int i = 0; i <= degree; ++i)
    {
        coeffs[i]++;
    }
    return *this;
}
Polynomial Polynomial::operator++(int a)
{
    Polynomial temp = *this;
    for (int i = 0; i <= degree; ++i)
    {
        coeffs[i]++;
    }
    return temp;
}
Polynomial Polynomial::operator+(const Polynomial &p2)
{
    int maxdegree  = (degree>p2.degree)? degree : p2.degree;
    Polynomial result(maxdegree);
    
    for (int i = 0; i <= degree; i++)
    {
        result.coeffs[i] += coeffs[i];
    }

    
    for (int i = 0; i <= p2.degree; i++)
    {
        result.coeffs[i] += p2.coeffs[i];
    }

    return result;
}
int Polynomial::operator()(int x){
    int answer = 0;
    for (int i = 0; i <= degree; i++){
        answer += coeffs[i]*pow(x,i);
    }
    return answer;
}
ostream &operator<<(ostream &out, const Polynomial &p)
{
    for (int i = p.degree; i >= 0; i--)
    {
        if (p.coeffs[i]!=0){
            if (p.coeffs[i]<0)
                out << p.coeffs[i] << "x^" << i <<" ";
            else
            out << "+"<<p.coeffs[i] << "x^" << i << " ";
        }
    }
    return out;
}
istream &operator>>(istream &in, Polynomial &p)
{
    for (int i = 0; i <= p.degree; i++)
    {
        in >> p.coeffs[i];
    }
    return in;
}
int &Polynomial::operator[](int index)
{
   
    if (index < 0 || index > degree)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return coeffs[index];
}
    // --- THE TEST ARENA ---
int main()
{
    cout << "--- POLYNOMIAL TEST ARENA ---\n\n";

    Polynomial p1(2);
    Polynomial p2(2);

    // 1 & 2. Stream Operators (>> and <<)
    cout << "Enter 3 coefficients for p1 (for x^0, x^1, x^2): ";
    cin >> p1;
    cout << "p1 is: " << p1 << "\n\n";

    cout << "Enter 3 coefficients for p2 (for x^0, x^1, x^2): ";
    cin >> p2;
    cout << "p2 is: " << p2 << "\n\n";

    // 3. Subscript Operator []
    cout << "Setting p1's x^0 coefficient to 99...\n";
    p1[0] = 99;
    cout << "p1 is now: " << p1 << "\n\n";

    // 4. Addition Operator (+)
    Polynomial p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << "\n\n";

    // 5. Compound Assignment (+=)
    cout << "Performing p1 += p2...\n";
    p1 += p2;
    cout << "p1 is now: " << p1 << "\n\n";

    // 6. Equality Operator (==)
    if (p1 == p2)
    {
        cout << "Check: p1 and p2 are equal!\n\n";
    }
    else
    {
        cout << "Check: p1 and p2 are NOT equal.\n\n";
    }

    // 7. Assignment Operator (=)
    Polynomial p4(1);
    cout << "Created new p4: " << p4 << "\n";
    cout << "Performing p4 = p3...\n";
    p4 = p3;
    cout << "p4 is now: " << p4 << "\n\n";

    // 8 & 9. Increment Operators (++)
    cout << "Prefix ++p4: " << ++p4 << "\n";
    cout << "Postfix p4++ (should print old value): " << p4++ << "\n";
    cout << "After Postfix, p4 is now: " << p4 << "\n\n";

    // 10. Function Call Operator ()
    int x = 2;
    cout << "Evaluating p3(" << x << ")...\n";
    cout << "Result: " << p3(x) << "\n";

    return 0;
}