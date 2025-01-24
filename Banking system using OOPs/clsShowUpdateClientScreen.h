#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClients.h"
#include"clsScreen.h"
#include<string.h>

class clsShowUpdateClientScreen : protected clsScreen 
{
private:
    static void _PrintClient(clsBankClients Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static void ReadClientInfo(clsBankClients& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (CheckAccessRights(clsUser::epUpdateClient))
        {
            return; 
        }
        _DrawScreenHeader("\t Update Menu");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClients::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClients Client1 = clsBankClients::find(AccountNumber);
        _PrintClient(Client1); 
        cout << "\nAre you sure you want to update this client y/n ? ";
        char Answer = 'n';
        cin >> Answer; 
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Client Info ";
            cout << "\n______________________\n"; 
            ReadClientInfo(Client1); 
            clsBankClients::enSaveResult SaveResult;
            SaveResult = Client1.Save();
            switch (SaveResult)
            {
            case clsBankClients::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClients::enSaveResult::svFieldEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};

