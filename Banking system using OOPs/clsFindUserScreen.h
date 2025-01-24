#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;

class clsFindUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permission;
        cout << "\n___________________\n";

    }

public:
    static void ShowFindUserMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::epDeletClient))
        {
            return;
        }
        string username = ""; 
        cout << "Enter username that you want to search for ? "; 
        username = clsInputValidate::ReadString(); 
        while (!clsUser::IsUserExit(username))
        {
            cout << "the username is not in the system " << endl;
            username = clsInputValidate::ReadString(); 
        }
        clsUser NewUser = clsUser::find(username); 
        _PrintUser(NewUser); 
    }

};

