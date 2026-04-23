#include <iostream>
using namespace std;

class Account
{
protected:
    int balance;

public:
    Account() : balance(1) {}
    Account(int b) : balance(b)
    {
        if (balance <= 0)
        {
            cout << "Invalid Balance... system has set balance to 1" << endl;
            balance = 1;
        }
    }

    virtual void calculateInterest() = 0;

    int get_balance()
    {
        return balance;
    }

    Account &operator+=(int b)
    {
        balance += b;
        return *this;
    }

    Account &operator-=(int b)
    {
        if (balance >= b)
        {
            balance -= b;
        }
        else
        {
            cout << "Insufficient Balance! Withdrawal failed." << endl;
        }
        return *this;
    }

    bool operator>(int b) const
    {
        return balance > b;
    }

    bool operator==(int b) const
    {
        return balance == b;
    }

    bool operator<(int b) const
    {
        return balance < b;
    }
};

class SavingsAccount : public Account
{
    float interestRate;

public:
    SavingsAccount() : Account(1), interestRate(0) {}
    SavingsAccount(int b, float ir) : Account(b), interestRate(ir) {}

    void calculateInterest()
    {
        cout << " " << balance * interestRate << endl;
    }

    friend ostream &operator<<(ostream &o, const SavingsAccount &obj)
    {
        o << obj.balance;
        return o;
    }
};

int main()
{
    SavingsAccount sa(1000, 0.05);
    cout << "Initial balance: " << sa << endl;

    sa += 500;
    cout << "After depositing 500: " << sa << endl;

    sa -= 200;
    cout << "After withdrawing 200: " << sa << endl;

    if (sa > 1000)
    {
        cout << "Balance is greater than 1000." << endl;
    }

    sa.calculateInterest();

    return 0;
}