#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClients.h"
#include <iomanip>
#include"clsUtil.h"

class clsShowTotalBalance : protected clsScreen
{

	void _PrintClientRecordLine(clsBankClients Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
	static void _PrintClientRecordBalanceLine(clsBankClients Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public:
	static void ShowTotalBalance()
	{
		_DrawScreenHeader("\t Show Total balance ");
		vector<clsBankClients> vClients = clsBankClients::GetClientList();
		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalance = clsBankClients::GetTotalBalance();
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t No Client available in the system";
		}
		for (clsBankClients Clients : vClients)
		{
			_PrintClientRecordBalanceLine(Clients);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << TotalBalance << endl;
		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalance) << ")";
	}

};

