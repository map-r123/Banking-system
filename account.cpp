#include "account.h"

account::account() {}

account::account(int a, string n, double b)
{
    accountNumber=a;
    name=n;
    balance=b;
}

void account::deposit()
{
    double amount;
    cout << "\nDeposit Amount: ";
    cin >> amount;
    cout << "Deposit Successful\n";
    balance = balance + amount;
}

void account::withdraw()
{
    double amount;
    cout << "\nWithdraw Amount: ";
    cin >> amount;

    while(amount > balance)
    {
        cout << "Withdraw amount is greater than current balance" << endl;
        cout << "Withdraw Amount: ";
        cin >> amount;
    }
    balance = balance - amount;
    cout << "Withdraw Successful\n";
}

double account::checkBalance()
{
    return balance;
}

void account::createAccount()
{
    int acc;
    double bal;
    string nam;
    cout << "***** Create Account *****" << endl;
    cout << "\nAccount No:";
    cin >> acc;
    cin.ignore();
    cout << "Account Holder Name: ";
    getline(cin,nam);
    cout << "Current Balance: ";
    cin >> bal;

    accountNumber=acc;
    name=nam;
    balance=bal;
}
