#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClients.h"
class clsShowWithDrewScreen :protected clsScreen
{
private:
	static void _ReadAccountNumber()
	{

	}
public:
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
	static void ShowWithDrewMenu()
	{
		_DrawScreenHeader("\t WithDrew Menu ");
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";

		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClients Clients = clsBankClients::find(AccountNumber);
		_PrintClient(Clients);

		double amount = 0;
		cout << "\nPlease enter withdraw amount ";
		amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction ";
		char n;
		cin >> n;
		if (n == 'y' || n == 'Y')
		{
			if (Clients.WithDraw(amount))
			{
				cout << "\nWithDraw sucssesfully";
			}
			else
			{
				cout << "\nError please try again "; 
			}
		}
	
	}
};

