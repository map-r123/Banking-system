#include <iostream>
#include "account.h"
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    int selected =0;
    string strSelected;
    account newAccount;
    map<int,account> accountList;
    bool loggedin = false;

    while (selected!=8)
    {
        cout << "\n***** Simple Banking System *****" << endl;
        cout << "\n1. Create Account" << endl;
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Check Balance\n";
        cout << "5. Login\n";
        cout << "6. Save accounts\n";
        cout << "7. Load Accounts\n";
        cout << "8. Exit\n\n";
        cout << "Enter your choice: ";
        getline(cin, strSelected);

        while(newAccount.typeValidation(strSelected)==false)
        {
            cout << "Invaild input. Please enter a number\n";
            cout << "Enter your choice: ";
            getline(cin, strSelected);
        }
        
        selected = stoi(strSelected);
        switch (selected)
        {
        case 1:
            newAccount.createAccount();
            accountList[newAccount.getAccountNumber()] = newAccount;
            loggedin=true;
            break;
        case 2:
            if(loggedin==true)
            {
                newAccount.withdraw();
                accountList[newAccount.getAccountNumber()]=newAccount;
            }
            else
            {
                cout << "Please Login\n";
            }

            break;
        case 3:
            if(loggedin==true)
            {
                newAccount.deposit();
                accountList[newAccount.getAccountNumber()]=newAccount;
            }
            else
            {
                cout << "Please Login\n";
            }

            break;
        case 4:
            if(loggedin==true)
            {
                cout << "\nYour Balance: " << fixed << setprecision(2) << newAccount.checkBalance() ;
            }
            else
            {
                cout << "Please Login\n";
            }
            break;
        case 5:
        {
            int acc,pin;
            cout << "\n***** Login *****" << endl;
            cout << "\nAccount No: ";
            cin >> acc;
            cout << "Pin: ";
            cin >> pin;

            auto currentAccount = accountList.find(acc);

            if(currentAccount != accountList.end())
            {
                newAccount=accountList[acc];
                cout << "Welcome " <<newAccount.getName() << endl;
                loggedin=true;
            }
            else
            {
                cout << "Login Fail (Incorret Account Number or Pin)\n";
            }
            break;
        }
        case 6:
            newAccount.saveAccounts(accountList);
            cout << "Save Complete\n";
            break;
        case 7:
            accountList.clear();
            newAccount.readAccounts(accountList);
            cout << "Read Complete\n";
            break;
        case 8:
            cout << "Thank you " << newAccount.getName() <<
                " for using our simple banking system";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }

    }

    return 0;
}


