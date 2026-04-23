#include<iostream>
using namespace std;

class Account{
    protected:
    int balance;

    public:
    Account():balance(1){}
    Account(int b):balance(b){
        if(balance == 0 || balance <0){
            cout<<"Invalid Balance... system has set balance to 1"<<endl;
            balance = 1;
        }
    }

    virtual void calculateInterest() = 0;
    int get_balance(){
        return balance;
    }
    

};

class SavingsAccount: public Account{
    float interestRate;
    public:
    SavingsAccount():interestRate(0){}
    SavingsAccount(int b, float ir) : Account(b), interestRate(ir) {}
    void calculateInterest()
    {
        cout<<" "<<balance*interestRate<<endl;
    }

    friend SavingsAccount& operator+=(SavingsAccount &obj, int b);
    friend SavingsAccount& operator-=(SavingsAccount &obj, int b);
    friend bool operator>(SavingsAccount &obj, int b);
    friend bool operator==(const SavingsAccount &obj, int b);
    friend bool operator<(const SavingsAccount &obj, int b);
    friend ostream& operator<<(ostream &o, const SavingsAccount &obj );
};
SavingsAccount &operator+=(SavingsAccount &obj, int b)
{
    obj.balance += b;
    return obj;
}
SavingsAccount &operator-=(SavingsAccount &obj, int b)
{
    if (obj.balance >= b)
    {
        obj.balance -= b;
    }
    else
    {
        cout << "Insufficient Balance! Withdrawal failed." << endl;
    }
    return obj;
}
bool operator>(SavingsAccount &obj, int b){
    return (obj.balance>b);
}
bool operator==(const SavingsAccount &obj, int b){
    return (obj.balance == b);
}
bool operator<(const SavingsAccount &obj, int b){
    return (obj.balance < b);
}
ostream &operator<<(ostream &o, const SavingsAccount &obj){
    o<<obj.balance;
    return o;
}

int main()
{
    // 1. Test Constructor and Initialization
    SavingsAccount sa(1000, 0.05); // Balance: 1000, Interest: 5%
    cout << "Initial balance: " << sa << endl;

    // 2. Test Compound Assignment Operators
    sa += 500;
    cout << "After depositing 500: " << sa << endl;

    sa -= 200;
    cout << "After withdrawing 200: " << sa << endl;

    // 3. Test Insufficient Balance Handling
    sa -= 5000;
    cout << "Current balance: " << sa << endl;

    // 4. Test Comparison Operators
    cout << "\n--- Comparison Checks ---" << endl;
    if (sa > 1000)
    {
        cout << "Balance is greater than 1000." << endl;
    }

    if (sa == 1300)
    {
        cout << "Balance is exactly 1300." << endl;
    }

    if (sa < 2000)
    {
        cout << "Balance is less than 2000." << endl;
    }

    // 5. Test Interest Calculation
    cout << "\nCalculated interest: ";
    sa.calculateInterest();

    return 0;
}