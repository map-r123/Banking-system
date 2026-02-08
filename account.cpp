#include "account.h"


account::account() {}

account::account(int a, string n, double b, int p)
{
    accountNumber=a;
    name=n;
    balance=b;
    pin=p;
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
    string nam,strPin;
    cout << "***** Create Account *****" << endl;
    cout << "\nAccount No:";
    cin >> acc;
    cin.ignore();
    cout << "Account Holder Name: ";
    getline(cin,nam);
    cout << "Current Balance: ";
    cin >> bal;
    cout << "4 digit Pin: ";
    cin >> strPin;


    while(strPin.length()!=4)
    {
        cout << "Please enter 4 digit pin: ";
        cin >> strPin;
    }

    accountNumber=acc;
    name=nam;
    balance=bal;
    pin= stoi(strPin);
    cout << "Account Created Successfully\n";
}

int account::getAccountNumber()
{
    return accountNumber;
}

int account::getPin()
{
    return pin;
}

string account::getName()
{
    return name;
}
