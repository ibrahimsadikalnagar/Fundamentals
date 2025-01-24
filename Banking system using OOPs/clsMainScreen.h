#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iostream>
#include <iomanip>
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsShowUpdateClientScreen.h"
#include"clsShowFindClientScreen.h"
#include"clsShowTransactionScreen.h"
#include"clsShowManageUser.h"
#include"Global.h"
#include"clsShowUserLoginScreen.h"
#include"clsLoginListScreen.h"

using namespace std; 

class clsMainScreen: protected clsScreen
{
private:
    enum enMainMenuOption
    {
        eListClient =1 , 
        eAddNewClient =2, 
        eDeleteClient=3, 
        eUpdatClient=4, 
        eFindClient=5, 
        eShowTransaction=6, 
        eManageUser=7, 
        eLoginUser=8,
        eExit=9
    };
   static void _GoBackToMainMenue()
    {
       cout << setw(37) << left << ""<< "\n\tPress any key to return back to main menu\n"; 
       system("pause>0");
       ShowMainMenu(); 
    }
    static void _ShowAllClientsScreen()
    {
        system("cls");
        clsClientListScreen::ShowClientList();
       
    }
    static void _ShowAddNewClient()
    {
        system("cls");
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _ShowDeleteClient()
    {
        system("cls"); 
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static void _ShowUpdateClient()
    {
        system("cls");
        clsShowUpdateClientScreen::ShowUpdateClientScreen();
    }
    static void _ShowFindClient()
    {
        system("cls");
        clsShowFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransaction()
    {
        system("cls");
        clsShowTransactionScreen::ShowTransactionMenu();
    }
    static void _ShowManageUser()
    {
        system("cls");
        clsShowManageUser::ShowManageUserMenu();
        
    }
    static void _ShowLoginList()
    {
        system("cls"); 
        clsShowUserLoginScreen::ShowUserLoginList();
         
    }
    static void _ShowExit()
    {
        system("cls");
        cout << "\nEnd screen will be here";
    }
    static void _Logout()
    {
       CurrentUser = clsUser::find("", ""); 
       
    }


   static void _preformMainMenuOption(enMainMenuOption MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case clsMainScreen::eListClient:
            _ShowAllClientsScreen();
            _GoBackToMainMenue(); 
            break;
        case clsMainScreen::eAddNewClient:
            _ShowAddNewClient();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eDeleteClient:
            _ShowDeleteClient(); 
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eUpdatClient:
            _ShowUpdateClient(); 
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eFindClient:
            _ShowFindClient();
            _GoBackToMainMenue(); 
            break;
        case clsMainScreen::eShowTransaction:
            _ShowTransaction();
              _GoBackToMainMenue();
            break;
        case clsMainScreen::eManageUser:
            _ShowManageUser();
            _GoBackToMainMenue(); 
            break;
        case clsMainScreen::eLoginUser:
            _ShowLoginList();
            _GoBackToMainMenue(); 
            break;
        case clsMainScreen::eExit:
            system("cls"); 
            _Logout();
            
         
            break;
        default:
            break;
        }
    }
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }
public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\t Main Screen " );

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Show login list Users.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        
        _preformMainMenuOption((enMainMenuOption )_ReadMainMenueOption()); 
	}
	
};

