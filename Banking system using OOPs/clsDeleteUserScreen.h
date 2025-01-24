#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
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
	static void ShowDeleteUserMenu()
	{
		_DrawScreenHeader("Delete Menu");
		string username;
		username = clsInputValidate::ReadString();
		while (clsUser::IsUserExit(username))
		{
			cout << "\nthe user is not in the system , try another name ";
			username = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::find(username);
		_PrintUser(NewUser);
		cout << "\nAre you sure you want to delete Press y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (NewUser.Delete())
			{
				cout << "\nSuccessful deleted";
			}
			else
			{
				cout << "Error , try again";
			}
		}
	}

}; 