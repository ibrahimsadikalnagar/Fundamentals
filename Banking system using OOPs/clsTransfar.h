#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"


class clsTransfar:protected clsScreen
{
private:
	static void _PrintClient(clsBankClients Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	static string _ReadAccountNumber()
	{
		string  accountNo = ""; 
		cout << "\nPlease enter account number to transfar from "; 
		accountNo = clsInputValidate::ReadString(); 
		while (!clsBankClients::IsClientExist(accountNo))
		{
			cout << "\nThe accountNo you entered is not in the system , try again "; 
			accountNo = clsInputValidate::ReadString();

		}
		return accountNo; 
	}
		
	static float _ReadAmount(clsBankClients SourceClient)
	{
		float Amount;
		cout << "\nEnter the transfar amount : ";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount exceeds the available balance , enter another amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount; 
	}
	
public:
	static void ShowTransfar()
	{
		
		_DrawScreenHeader("\tTransfar Screen"); 

		clsBankClients SourceClient = clsBankClients::find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClients DestinationClient = clsBankClients::find(_ReadAccountNumber()); 
		_PrintClient(DestinationClient); 

		float amount = _ReadAmount(SourceClient); 

		char Answer = 'n'; 
		cout << "\nAre you sure you want to perform this operation ? " ; 
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (Answer == 'Y' || Answer == 'y')
			{
				if (SourceClient.Transfar(amount, DestinationClient, CurrentUser.UserName))
				{
					cout << "\nTransfer done successfully\n";
				}
				else
				{
					cout << "\nTransfer Faild \n";
				}
			}

			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
		}
	}
};
