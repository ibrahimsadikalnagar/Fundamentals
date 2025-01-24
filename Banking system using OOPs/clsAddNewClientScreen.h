#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsAddNewClientScreen:protected clsScreen
{
private:
	
	static void _ReadClientInfo(clsBankClients& Client)
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
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::epAddClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add new client ");
		string AccountNumber = "";
		cout << "\nEnter account number ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nThe Account number you entered is already in the system enter another ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClients NewClient = clsBankClients::GetAddNewClientObject(AccountNumber);
		
		_ReadClientInfo(NewClient);

		clsBankClients::enSaveResult SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClients::svFieldEmptyObject:
			cout << "\nError the data is not saved";
			break;
		case clsBankClients::svSucceeded:
			cout << "\nThe data successfull saved ";
			_PrintClient(NewClient);
			break;
		case clsBankClients::svFaildAccountNumberExists:
			cout << "\nError the account number exit ";
			break;
		default:
			break;
		}

	}

};

