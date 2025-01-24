#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClients.h"
#include <iomanip>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsListUserScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsAddNewUserScreen.h";
#include"clsDeleteClientScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsShowManageUser : protected clsScreen
{
private:
    enum enManageUserMenuOption
    {
        enLlistUser = 1,
        enAddUser = 2,
        enDeleteUser = 3,
        enUpdateUser = 4,
        enFindUser = 5,
        enMainMenue = 6


    };
    static void _GoBackToMainManageMenu()
    {
        cout << "\nPlease press any key to get back to main Manage menu ";
        system("pause>0"); 
        ShowManageUserMenu();
    }
    static void _ShowListUser()
    {
        system("cls"); 
        clsListUserScreen::ShowUserListScreen();
    }
    static void _ShowAdduser()
    {
        system("cls");
        clsAddNewUserScreen::ShowAddListScreen();
    }
    static void _ShowDeleteUser()
    {
        system("cls"); 
        clsDeleteClientScreen::ShowDeleteClientScreen(); 
    }
    static void _ShowUpdateUser()
    {
        system("cls");
        clsUpdateUserScreen::showUpdateUserScreen(); 
    }
    static void _ShowFindUser()
    {
        system("cls");
        clsFindUserScreen::ShowFindUserMenu(); 
        
    }

    static void _PerformManageUserMenuOption(enManageUserMenuOption MainMenu)
    {
        switch (MainMenu)
        {
        case clsShowManageUser::enLlistUser:
            _ShowListUser();
            _GoBackToMainManageMenu();
            break;
        case clsShowManageUser::enAddUser:
            _ShowAdduser();
            _GoBackToMainManageMenu();
            break;
        case clsShowManageUser::enDeleteUser:
            _ShowDeleteUser();
            _GoBackToMainManageMenu();
            break;
        case clsShowManageUser::enUpdateUser:
            _ShowUpdateUser();
            _GoBackToMainManageMenu();
            break;
        case clsShowManageUser::enFindUser:
            _ShowFindUser(); 
            _GoBackToMainManageMenu();
            break;
        case clsShowManageUser::enMainMenue:
            
            break;
        default:
            break;
        }
    }
    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
  

public:
	static void ShowManageUserMenu()
	{
        if (!CheckAccessRights(clsUser::enPermissions::epManagerUser))
        {
            return; 
        }
        system("cls");
        _DrawScreenHeader("\t Manage User ");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUserMenuOption((enManageUserMenuOption)_ReadManageUsersMenueOption());
	}
};

