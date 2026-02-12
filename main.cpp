#include <iostream>
#include "account.h"
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    int selected =0;
    string strSelected="0";
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

        //Input validation
        while(newAccount.typeValidation(strSelected)==false)
        {
            cout << "Invaild input. Please enter a number\n";
            cout << "Enter your choice: ";
            getline(cin, strSelected);
        }

        selected = stoi(strSelected);
        switch (selected)
        {
            //Create account
        case 1:
            newAccount.createAccount();
            accountList[newAccount.getAccountNumber()] = newAccount;
            loggedin=true;
            break;
            // Withdraw
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
            //Deposit
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
            //Check balance
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
            //Login
        case 5:
        {
            int acc;
            string pin;
            cout << "\n***** Login *****" << endl;
            cout << "\nAccount No: ";
            cin >> acc;
            cout << "Pin: ";
            cin >> pin;
            cin.ignore();

            //check for login
            auto currentAccount = accountList.find(acc);

            if(currentAccount != accountList.end() && currentAccount->second.getPin()==pin)
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
            //Save accounts to a file
        case 6:
            newAccount.saveAccounts(accountList);
            cout << "Save Complete\n";
            break;
            //Load accounts from accounts
        case 7:
            accountList.clear();
            newAccount.readAccounts(accountList);
            cout << "Read Complete\n";
            break;
            //Exit app
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


