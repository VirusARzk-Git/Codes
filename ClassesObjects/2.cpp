#include <iostream>
using namespace std;

class BankAccount
{
    int balance;
    string name;
    
    public:
    BankAccount(int openingBalance) {
        this->balance = openingBalance;
        cout << "\nBank Account Opened!";
    }
    void deposit(int amt) {
        balance += amt;
        cout << "\nDeposit Successful!";
    }
    void withdraw(int amt)  {
        if (amt > balance)
            cout << "\nInsufficient Balance!";
        else    {
            balance -= amt;
            cout << "\nWithdrawal Successful!";
        }
    }

    int checkBalance()
    {
        return balance;
    }

    ~BankAccount(){
        cout << "\nBank Account Closed!";
    }
};

int main()
{
    BankAccount b(5000);
    while (true)
    {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit";
        cout << "\nEnter choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter amount to deposit : ";
            int amt1;
            cin >> amt1;
            b.deposit(amt1);
            break;
            case 2:
            cout << "\nEnter amount to withdraw : ";
            int amt2;
            cin >> amt2;
            b.withdraw(amt2);
            break;
        case 3:
            cout << "\nBalance is " << b.checkBalance();
            break;
        case 4:
            return 0;
        }
    }
}