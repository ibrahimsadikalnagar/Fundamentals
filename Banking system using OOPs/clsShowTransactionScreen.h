#pragma once
#include"clsScreen.h"
#include<iostream>
#include <iomanip>
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsShowWithDrewScreen.h"
#include"clsShowTotalBalance.h"
#include"clsTransfar.h"
#include"clsTransfarLog.h"

using namespace std;
class clsShowTransactionScreen :protected clsScreen
{
	string RollNo, Name, Subject;
private:
	enum enTransaction
	{
		enDeposit = 1,
		enWithDrewl = 2,
		enShowTotalBalance = 3,
		enTransfar = 4,
		enTransfarLog= 5,
		enShowMainMenu=6
	};

	static void _ShowDopsitScreen()
	{
		system("cls"); 
		clsDepositScreen::ShowDepositMenu(); 
	}

	static void _ShowWithDrewScreen()
	{
		system("cls");
		clsShowWithDrewScreen::ShowWithDrewMenu(); 
	}
	static void _ShowTotalBalanceScreen()
	{
		system("cls");
		clsShowTotalBalance::ShowTotalBalance();
	}
	static void _ShowTransfarScreen()
	{
		system("cls"); 
		clsTransfar::ShowTransfar(); 
		
	}

	
	static void _ShowTransfarLog()
	{
		system("pause>0"); 
		clsTransfarLog::ShowTransfarLogScreen(); 
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionMenu();
	}


public:
	static void  _PerformTransactionMenuOption(enTransaction Transaction)
	{
		switch (Transaction)
		{
		case clsShowTransactionScreen::enDeposit:
			_ShowDopsitScreen();
			_GoBackToTransactionsMenue();

			break;
		case clsShowTransactionScreen::enWithDrewl:
			_ShowWithDrewScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransactionScreen::enShowTotalBalance:
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
			
		case clsShowTransactionScreen::enTransfar:
			_ShowTransfarScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransactionScreen::enTransfarLog:
		_ShowTransfarLog();
		_GoBackToTransactionsMenue();
		default:
			break;
		}
	}
	static short ReadTransactionMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	

	static void ShowTransactionMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::epTransaction))
		{
			return; 
		}
		system("cls");
		_DrawScreenHeader("\t Transaction Menue");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfar.\n";
		cout << setw(37) << left << "" << "\t[5] Transfar Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionMenuOption((enTransaction)ReadTransactionMenuOption());
	}
};
	

