#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <map>

using namespace std;

class account
{
private:
    int accountNumber;
    string name;
    double balance;
    string pin;
public:
    account();
    account(int a, string n, double b, string pin);

    void deposit();
    void withdraw();
    double checkBalance() const;
    void createAccount();
    int getAccountNumber() const;
    string getPin() const;
    string getName() const;
    void saveAccounts(const map<int, account>& accList);
    void readAccounts(map<int, account>& accList);
    bool lengthValidation(string pin);
    bool typeValidation(string pin);
};

#endif // ACCOUNT_H
