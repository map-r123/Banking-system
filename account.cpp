#include "account.h"
#include <fstream>
#include <sstream>
#include <cctype>

account::account() {}

account::account(int a, string n, double b, string p)
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
    cout << "Enter 4 digit pin: ";
    cin >> strPin;

    while(lengthValidation(strPin)==false  || typeValidation(strPin)==false)
    {
        cout << "Invaild Pin. Please enter 4 digit pin: ";
        cin >> strPin;

    }

    accountNumber=acc;
    name=nam;
    balance=bal;
    pin= strPin;
    cout << "Account Created Successfully\n";
}

int account::getAccountNumber() const
{
    return accountNumber;
}

string account::getPin() const
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
    int accNo;

    while(getline(myFile,line))
    {
        stringstream ss(line);

        getline(ss, accStr, '|');
        getline(ss, nam, '|');
        getline(ss, balStr, '|');
        getline(ss, pinStr, '|');

        accNo = stoi(accStr);
        bal = stod(balStr);
        pin = pinStr;

        account acc(accNo, nam, bal, pinStr);
        accList[accNo]=acc;
    }

    myFile.close();

}

bool account::lengthValidation(string pin)
{
    if(pin.length()==4)
    {
        return true;
    }
    return false;
}

bool account::typeValidation(string pin)
{
    for (int i = 0; i < pin.length(); ++i)
    {
        if(!isdigit(pin[i]))
        {
            return false;
        }
    }

    return true;
}
