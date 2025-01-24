#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsShowFindClientScreen : protected clsScreen
{
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
public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::epFindClient))
        {
            return; 
        }
        _DrawScreenHeader("\t Find Menu");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClients::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClients NewClient = clsBankClients::find(AccountNumber); 
        _PrintClient(NewClient);
    }

};

