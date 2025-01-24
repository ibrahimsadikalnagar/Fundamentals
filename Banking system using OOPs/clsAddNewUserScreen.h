#pragma once
#include"clsUser.h"
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidate.h"
using namespace std; 

class clsAddNewUserScreen : protected clsScreen
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
	static short _ReadPermissionToset()
	{
		short permission = 0; 
		char Answer = 'n'; 

		cout << "\nDo you want to give full access ?"; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1; 
		}

		cout << "\nDo you want to give access to : \n";
		cout << "\nShow Client List y/n ? "; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y')
		{
			permission += clsUser::enPermissions::epListClient; 
		}

		cout << "\n Add new client ? "; 
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			permission += clsUser::enPermissions::epAddClient; 

		}

		cout << "\n Delete client ? "; 
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			permission += clsUser::enPermissions::epDeletClient; 

		}
		cout << "\n Update client ? "; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y')
		{
			permission += clsUser::enPermissions::epUpdateClient; 
		}
		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::epFindClient; 
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::epTransaction; 
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::epManagerUser;
		}
		

		cout << "\nLogin List Menu ? y/n ? "; 
		cin >> Answer; 
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::epLoginListUser; 
		}
		return permission;
	}

	static void _ReadUserNameInfo(clsUser &User)
	{
		cout << "\nEnter first name : ";
		User.FirstName = clsInputValidate::ReadString(); 
		cout << "\nEnter last name : "; 
		User.LastName = clsInputValidate::ReadString(); 
		cout << "\nEnter Email account "; 
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter your phone number "; 
		User.Phone = clsInputValidate::ReadString(); 
		cout << "\nEnter Password "; 
		User.Password = clsInputValidate::ReadString(); 
		cout << "\nEnter permission"; 
		User.Permission = _ReadPermissionToset(); 

	}
public:
	static void ShowAddListScreen()
	{
		/*if (!CheckAccessRights(clsUser::enPermissions::epAddClient))
		{
			return; 
		}*/
		string Username = ""; 
		cout << "Enter Username : " << endl; 
		Username = clsInputValidate::ReadString(); 

		while (clsUser::IsUserExit(Username))
		{
			cout << "\nUserName Is Already Used, Choose another one: ";
			Username = clsInputValidate::ReadString(); 

		}

		clsUser NewUser = clsUser::_GetAddUserObject(Username); 
		_ReadUserNameInfo(NewUser); 
		clsUser::enSaveResult SaveResult;
		SaveResult = NewUser.Save(); 
		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "Error user was not saved because its empty"; 
			break;
		case clsUser::svSuccessfull:
			cout << "Successfully saved ";
			_PrintUser(NewUser);
			break;
		case clsUser::svFaildUserExists:
			cout << "Error user was not saved because its used "; 
			break;
		
		}
	}
};

