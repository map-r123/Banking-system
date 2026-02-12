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
    cin.ignore();
    cout << "Deposit Successful\n";
    balance = balance + amount;
}

void account::withdraw()
{
    double amount;
    string strAmount;
    cout << "\nWithdraw Amount: ";
    getline(cin, strAmount);

    while(typeValidation(strAmount)==false)
    {
        cout << "Incorret Input type. Please input a number";
        cout << "\nWithdraw Amount: ";
        getline(cin, strAmount);
    }

    amount=stod(strAmount);

    while(amount > balance)
    {
        cout << "Withdraw amount is greater than current balance" << endl;
        cout << "Withdraw Amount: ";
        getline(cin, strAmount);

        while(typeValidation(strAmount)==false)
        {
            cout << "Incorret Input type. Please input a number";
            cout << "\nWithdraw Amount: ";
            getline(cin, strAmount);
        }

        amount=stod(strAmount);
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
    cin.ignore();
    cout << "Enter 4 digit pin: ";
    getline(cin, strPin);


    while(lengthValidation(strPin)==false  || typeValidation(strPin)==false)
    {
        cout << "Invaild Pin. Please enter 4 digit pin: ";
        getline(cin, strPin);
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
//Functions to save accounts to file
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

//Function to load accounts from files
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
//function to check if a string has 4 charactors
bool account::lengthValidation(string pin)
{
    if(pin.length()==4)
    {
        return true;
    }
    return false;
}
// function to check if a string is digital
// an improvement is to return a string that has already been check
// incorrent imput should be asked in the function
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
