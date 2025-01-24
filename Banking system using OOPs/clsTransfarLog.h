#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"


class clsTransfarLog:protected clsScreen
{
public:
	static void PrintTransfarLogRecordLine(clsBankClients::stTransfarLogin TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.stBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.dedBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.username;
	}
	static void ShowTransfarLogScreen()
	{
		vector<clsBankClients::stTransfarLogin> vTransfarLog = clsBankClients::GetTransfarLoginList();
		string Title = "\tTransfar Log List Screen "; 
		string Subtitle = "\t    (" + to_string(vTransfarLog.size()) + ") Record (s) .";
		_DrawScreenHeader(Title, Subtitle); 
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;
		if (vTransfarLog.size() == 0)
		
			cout << "\t\t\t\tNo Transfars available in the system "; 
		else

			for (clsBankClients::stTransfarLogin Record : vTransfarLog)
			{
				PrintTransfarLogRecordLine(Record); 
				cout << endl; 
			}
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n"
			<< endl;
	}
};

