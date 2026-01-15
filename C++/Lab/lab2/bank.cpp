/*Create a bank account class that has a name, password, and balance
as its data. For behaviors, the user must be able to create an
account, deposit and withdraw money, and check their balance.*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printmenu(){
    cout<<"1. Deposit"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Get Balance"<<endl;
    cout<<"4. Set Password"<<endl;
    cout<<"5. Exit"<<endl; 
}

class BankAccount {
    private:
    string name ;
    string password ;
    float balance ;

    public:
    BankAccount():balance(0){}
    void createAccount();
    void deposit();
    void withdraw();
    void getBalance();
    void setPassword();
     
};
void BankAccount::createAccount(){
    cout<<"Please first Create your bank account"<<endl;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Set Password: ";
    cin>>password;
    balance=0;
    cout<<"Account Created Successfully"<<endl;
}
void BankAccount::setPassword(){
     while (1)
    {
        string pass;
        string oldpass;
        cout<<"Enter Old Password to continue: ";
        cin>>oldpass;
        if(oldpass==password){

            cout<<"Enter New Password"<<endl;
            cin>>pass;
            password = pass;
            cout<<"Password Changed Successfully"<<endl;
            break;
        }
        else{
            cout<<"Sorry Password is Incorrect "<<endl;
            
        }
    }
}
void BankAccount::deposit(){
    string pass;
    while (1)
    {
        
        cout<<"Enter password to continue: ";
        cin>>pass;
        if (password ==pass ){
    
            float bal;
            cout<<"Enter Amount: ";
            cin>>bal;
            balance+=bal;
            break;
    }
     else{
            cout<<"Sorry Password is Incorrect "<<endl;
        }
    
    }
    
}
void BankAccount::withdraw(){
    string pass;
    while (1)
    {
        
        cout<<"Enter password to continue: ";
        cin>>pass;
        if (password ==pass ){
    
            float bal;
            cout<<"Enter Amount: ";
            cin>>bal;
            balance-=bal;
            break;
    }
    else{
            cout<<"Sorry Password is Incorrect "<<endl;
            
        }
    
    }
    
}
void BankAccount::getBalance(){
    string pass;
    while (1)
    {
        
        cout<<"Enter password to continue: ";
        cin>>pass;
        if (password ==pass ){
    
            cout<<"Your Balance is : "<<balance<<endl;
            break;
    }
    else{
            cout<<"Sorry Password is Incorrect "<<endl;
            
        }
    
    }
    
}

main(){
    BankAccount b;
    b.createAccount();
    while(1){
        printmenu();
        int choice;
        cin>>choice;
        if(choice==5){
            break;
        }
        switch (choice)
        {
        case 1:
            b.deposit();
            break;
        case 2:
            b.withdraw();
            break;
        case 3:
            b.getBalance();
            break;
        case 4:
            b.setPassword();
            break;
        default:
        cout<<"Invalid Choice"<<endl;
            break;
        }
    }

}