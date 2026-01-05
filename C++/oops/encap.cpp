#include<iostream>

using namespace std;

// the class encapsulates the details of a bank account
// how? By keeping data members private and providing public methods to interact with them

class BankAccount{
    private:
        string accountNumber;
        double balance;
    public:
        BankAccount(string accnum, double bal): accountNumber(accnum), balance(bal) {}

        void deposit(double amount){
            if(amount > 0){
                balance += amount;
                cout << "Deposited: " << amount  << endl;
            }else{
                cout << "Deposit amount must be positive." << endl;
            }
        }
        void withdraw(double amount){
            if(amount > 0 && amount <= balance){
                balance -= amount;
                cout << "Withdrew: " << amount << endl;
            }else{
                cout << "Invalid withdrawal amount." << endl;
            }
        }
        double getBalance() const {
            return balance;
        }
        string getAccountNumber() const {
            return accountNumber;
        }
        

};
    
int main(){
    BankAccount account("123456789", 1000.0);
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Initial Balance: " << account.getBalance() << endl;

    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0); // Invalid withdrawal

    return 0;

}

