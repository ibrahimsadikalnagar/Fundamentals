#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClients.h"

class clsDeleteClientScreen : protected clsScreen
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

public:

	static void ShowDeleteClientScreen()
	{
		/*if (!CheckAccessRights(clsUser::enPermissions::epDeletClient))
		{
			return; 
		}*/
		_DrawScreenHeader("\t Delete menu");
		string AccountNumber = "";
		cout << "\nEnter account number ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nThe account number is not found , try another one  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClients NewClient = clsBankClients::find(AccountNumber);
		_PrintClient(NewClient);
		cout << "\nDo you want to delete the record ? press Y - N or y - n  : ";
		char accept = 'y';
		cin >> accept;
		if (accept == 'y' || accept == 'Y')
		{
			if (NewClient.Delete())
			{
				cout << "\nSuccessfully deleted ";
			}
			else
			{
				cout << "\n Error ... its not deleted ";
			}
		}


	}

};

