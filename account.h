#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;

class account
{
private:
    int accountNumber;
    string name;
    double balance;
    int pin;
public:
    account();
    account(int a, string n, double b, int pin);

    void deposit();
    void withdraw();
    double checkBalance();
    void createAccount();
    int getAccountNumber();
    int getPin();
    string getName();
};

#endif // ACCOUNT_H
