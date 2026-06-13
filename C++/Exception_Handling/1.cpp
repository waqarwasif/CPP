#include<iostream>
#include<stdexcept>
using namespace std;
 
class Customer
{
    string name;
    int balance, accnum;

    public:
    Customer(string name, int balance , int accnum){
        this->accnum = accnum;
        this->balance = balance;
        this->name = name;  

    }

    // deposit
    void deposit(int amount){
        if(amount <= 0)
        throw "not a valid amount";
        
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
        

    }

    // withdraw
    void withdraw(int amount){
        
        if(amount > balance)
        throw "Insufficient Balance";

        balance -= amount;
        cout << "Amount Withdrawn: " << amount << endl;
        
        }
};

int main(){
    Customer c1("John Doe", 1000, 12345);
    try
    {
        c1.deposit(500);
        c1.withdraw(60000);
    }

    catch(const char* e)
    {
        cout<<"Error: "<<e<<endl;
    }
    

}