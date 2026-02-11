#include "account.h"
#include <fstream>
#include <sstream>

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

double account::checkBalance() const
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

    while(strPin.length()!=4 )
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

int account::getAccountNumber() const
{
    return accountNumber;
}

int account::getPin() const
{
    return pin;
}

string account::getName() const
{
    return name;
}

void account::saveAccounts(const map<int, account>& accList)
{
    ofstream file("accounts.txt");

    for (const auto& pair : accList) {
        const account& acc = pair.second;
        file << acc.getAccountNumber() << "|"
             << acc.getName() << "|"
             << acc.checkBalance() << "|"
             << acc.getPin() << "\n";
    }

    file.close();
}

void account::readAccounts(map<int, account>& accList)
{
    ifstream myFile("accounts.txt");

    if (!myFile.is_open())
    {
        cout << "Error: Unable to open file\n";
    }

    double bal;
    string nam, line, accStr, balStr, pinStr;
    int accNo,p;

    while(getline(myFile,line))
    {
        stringstream ss(line);

        getline(ss, accStr, '|');
        getline(ss, nam, '|');
        getline(ss, balStr, '|');
        getline(ss, pinStr, '|');

        accNo = stoi(accStr);
        bal = stod(balStr);
        pin = stoi(pinStr);

        account acc(accNo, nam, bal, p);
        accList[accNo]=acc;
    }

    myFile.close();

}
