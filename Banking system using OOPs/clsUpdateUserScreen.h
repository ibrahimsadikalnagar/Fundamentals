#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std; 
class clsUpdateUserScreen:protected clsScreen
{
private:
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::epListClient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epAddClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epDeletClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epTransaction;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::epManagerUser;
        }

        return Permissions;

    }

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permission = _ReadPermissionsToSet();
	}
	static void _PrintUser(clsUser& User)
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
	static void showUpdateUserScreen()
	{
       /* if (!CheckAccessRights(clsUser::enPermissions::epDeletClient))
        {
            return;
        }*/
		_DrawScreenHeader("Update Menu"); 
		cout << "Enter user name : " << endl; 
		string username = ""; 
		username = clsInputValidate::ReadString(); 
		while (!clsUser::IsUserExit(username))
		{
			cout << "The username that you entered is not in the system , try again? "; 
			username = clsInputValidate::ReadString(); 
		}
		clsUser NewUser = clsUser::find(username); 
		_PrintUser(NewUser);
        _ReadUserInfo(NewUser); 
        clsUser::enSaveResult SaveResult; 
        SaveResult = NewUser.Save(); 
        switch (SaveResult)
        {
        case clsUser::svFaildEmptyObject:
            break;
        case clsUser::svSuccessfull:
            cout << "\nUser update successfully"; 
            _PrintUser(NewUser); 
            break;
        case clsUser::svFaildUserExists:
            cout << "\nError User was not saved because it's Empty";
            break;
        default:
            break;
        }
		
	}

};

